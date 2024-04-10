// https://codeforces.com/problemset/problem/1251/E2

#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define DBG(x) do {cerr << #x << " = " << (x) << endl;} while (false)
#define DBGY(x) do {cerr << #x << " = " << (x) << " , ";} while (false)
#define DBG2(x,y) do {DBGY(x); DBG(y); } while (false)
#define DBG3(x,y,z) do {DBGY(x); DBGY(y); DBG(z); } while (false)
#define DBG4(x,y,z,w) do {DBGY(x); DBGY(y); DBGY(z); DBG(w); } while (false)
#define RAYA do {cerr << " ================ " << endl; } while (false)

#define SIZE(c) int((c).size())
#define esta(x,c) ((c).find(x) != (c).end())
#define all(c) (c).begin(), (c).end()

typedef long long tint;
typedef pair<int,int> pint;
typedef pair<tint,tint> ptint;

struct Voter
{
    int m,p;
    
    bool operator<(const Voter&o) const
    {
        return m < o.m;
    }
};

struct Block
{
    int lessThanBlock;
    int m;
    vector<int> p;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int TT; cin >> TT;
    forn(tt,TT)
    {
        int n; cin >> n;
        
        vector<Voter> voters(n);
        forn(i,n)
            cin >> voters[i].m >> voters[i].p;
        
        sort(all(voters));
        vector<Block> blocks;
        blocks.reserve(n);
        int lastM = -1;
        int lessThanBlock = 0;
        for (Voter voter : voters)
        if (voter.m != lastM)
        {
            lastM = voter.m;
            blocks.push_back({lessThanBlock, voter.m, {voter.p}});
            lessThanBlock++;
        }
        else
        {
            blocks.back().p.push_back(voter.p);
            lessThanBlock++;
        }
        priority_queue<int, vector<int>, greater<int>> cheapVoters;
        tint ret = 0;
        int bought = 0;
        dforn(blockIndex, blocks.size())
        {
            Block &block = blocks[blockIndex];
            for (int p : block.p)
                cheapVoters.push(p);
            while (!cheapVoters.empty() && block.lessThanBlock + bought < block.m)
            {
                ret += cheapVoters.top();
                cheapVoters.pop();
                bought++;
            }
        }
        cout << ret << "\n";
    }
    
    return 0;
}