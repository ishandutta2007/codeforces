#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long tint;
typedef pair<int,int> pint;

const int MAX = 22;

vector<int> sol;
vector<int> bestSol;

int N;
#define TARGET ((1<<N)-1)

struct Estado
{
    int mask[MAX];
    bool win()
    {
        forn(i,N)
        if (mask[i] != TARGET)
            return false;
        return true;
    }
} e;

void go(int next)
{
    if (e.win())
    {
        if (sol.size() < bestSol.size())
            bestSol = sol;
        return;
    }
    if (sol.size() + 1 >= bestSol.size())
        return;
    if (next == 0)
        return;
    next--;
    go(next);
    Estado previo = e;
    sol.push_back(next);
    int masca = e.mask[next];
    while (masca)
    {
        int j = __builtin_ctz(masca);
        e.mask[j] |= e.mask[next];
        masca &= masca-1;
    }
    go(next);
    sol.pop_back();
    e = previo;
}


int main() 
{
    #ifdef ACMTUYO
        assert(freopen("b.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int M; cin >> N >> M;
    forn(i,M)
    {
        int a,b; cin >> a >> b;
        a--; b--;
        e.mask[a] |= (1<<b);
        e.mask[b] |= (1<<a);
    }
    forn(i,N)
        e.mask[i] |= (1<<i);
    bestSol = vector<int>(N+1, -1);
    go(N);
    cout << bestSol.size() << endl;
    forn(j,bestSol.size())
    {
        if (j > 0) cout << " ";
        cout << 1+bestSol[j];
    }
    cout << endl;
    return 0;
}