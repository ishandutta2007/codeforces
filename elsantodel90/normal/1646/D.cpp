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
    forn(i,v.size())
    {
        if (i > 0) os << " ";
        os << v[i];
    }
    return os;
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


struct Value
{
    int k, minW;
    
    bool operator !=(const Value &o) const
    {
        return k != o.k || minW != o.minW;
    }
    
    Value operator +(const Value &o) const
    {
        return {k + o.k, minW + o.minW};
    }
    
    // Min es mejor
    bool operator <(const Value &o) const
    {
        if (k != o.k)
            return k > o.k;
        return minW < o.minW;
    }
};

const Value EMPTY = {0, 0};

struct BiValue
{
    Value vale,noVale;
};

const int MAXN = 300000;

vector<int> g[MAXN];
BiValue dp[MAXN];
vector<int> weights;

BiValue divide(int x, int p)
{
    BiValue &ret = dp[x] = {EMPTY, EMPTY};
    for (int y : g[x])
    if (y != p)
    {
        BiValue v = divide(y,x);
        ret.noVale = ret.noVale + v.vale;
        ret.vale = ret.vale + v.noVale;
    }
    ret.vale = ret.vale + (Value){1, SIZE(g[x])};
    ret.vale = min(ret.vale, ret.noVale);
    return ret;
}

void rebuild(int x, int p, bool vale)
{
    bool valeChild = true;
    if (vale && dp[x].vale != dp[x].noVale)
    {
        weights[x] = SIZE(g[x]);
        valeChild = false;
    }
    for (int y : g[x])
    if (y != p)
        rebuild(y,x, valeChild);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    if (n == 2)
    {
        cout << "2 2\n1 1\n";
        return 0;
    }
    
    forn(i,n)
        g[i].clear();
        
    forn(i,n-1)
    {
        int x,y;
        cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    BiValue v = divide(0, -1);
    weights = vector<int>(n,1);
    rebuild(0, -1, true);
    
    cout << v.vale.k << " " << v.vale.minW + n - v.vale.k << "\n";
    cout << weights << "\n";
    
    return 0;
}