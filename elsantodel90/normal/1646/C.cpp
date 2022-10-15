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

template <typename T>
ostream & operator <<(ostream &os, const vector<T>& v) {
    os << "[";
    forn(i,v.size())
    {
        if (i > 0) os << " ";
        os << v[i];
    }
    return os << "]";
}

template <typename T>
istream & operator >>(istream &is, vector<T>& v) {
    int n;
    is >> n;
    v.resize(n);
    forn(i,n)
        is >> v[i];
    return is;
}

const int MAX = 16;
const int INF = 1000000000;
const int CUT = 14;
const tint BOUND = 1000000000000LL;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int TT;
    cin >> TT;
    
    tint factorial[MAX];
    factorial[0] = 1;
    forn(i,MAX-1)
        factorial[i+1] = (i+1) * factorial[i];
    assert(factorial[CUT] < BOUND);
    assert(factorial[CUT+1] > BOUND);
    
    forn(tt,TT)
    {
        tint n;
        cin >> n;
        int best = INF;
       
        forn(mask, 1<<CUT)
        {
            tint s = 0;
            int k = 0;
            forn(i, CUT)
            if ((mask >> i) & 1)
            {
                s += factorial[i+1];
                k++;
            }
            if (s <= n)
            {
                int ret = k + __builtin_popcountll(n-s);
                best = min(ret, best);
            }
        }
        assert(best != INF);
        cout << best << "\n";
    }
    
    return 0;
}