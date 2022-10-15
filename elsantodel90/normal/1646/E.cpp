#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <unordered_set>
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

bitset<25000000> todos;
int nextK = 1;
tint dp[100];

tint n,m;

tint f(int k)
{
    while (k >= nextK)
    {
        forn(i,m)
            todos.set(int(i+1) * nextK);
        dp[nextK] = todos.count();
        nextK++;
    }
    return dp[k];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    dp[0] = 0;
    
    cin >> n >> m;
    
    tint ret = 1;
    
    set<tint> suspot;
    
    forsn(i,2,n+1)
    if (!esta(i, suspot))
    {
        tint poti = i;
        int k = 1;
        while (poti <= n)
        {
            suspot.insert(poti);
            poti *= i;
            k++;
        }
        ret += f(k-1);
    }
    
    cout << ret << "\n";
    
    return 0;
}