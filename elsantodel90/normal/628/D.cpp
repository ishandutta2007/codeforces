#include <iostream>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <cassert>
#include <vector>

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
typedef vector<int> vint;
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

const int MOD = 1000000007;

int m,d;

const int MAX = 2048;

// dp(i,r,ok)
int dpArray[2][MAX][2];

#define dp(i,r,ok) dpArray[((i%2)+2)%2][r][ok]

int f(const vector<int> &b)
{
    const int N = SIZE(b);
    
    forn(r,m)
    forn(ok,2)
        dp(N,r,ok) = (r == 0);
    
    dforn(i,N)
    forn(r,m)
    forn(ok,2)
    {
        int minDigit = 0, maxDigit = ok ? 9 : b[i];
        int forbidden = -1;
        if (i % 2)
        {
            minDigit = d;
            maxDigit = min(d, maxDigit);
        }
        else
            forbidden = d;
        dp(i,r,ok) = 0;
        forsn(digit, minDigit, maxDigit+1)
        if (digit != forbidden)
        {
            dp(i,r,ok) += dp(i+1, (10*r+digit)%m, ok || digit < b[i]);
            dp(i,r,ok) %= MOD;
        }
    }
        
    return dp(0,0,0);
}

vector<int> readNumber()
{
    string s;
    cin >> s;
    vector<int> ret(SIZE(s));
    forn(i,SIZE(s))
        ret[i] = s[i] - '0';
    return ret;
}

vector<int> minusOne(vector<int> x)
{
    assert(SIZE(x) > 0);
    assert(x[0] > 0);
    dforn(i,SIZE(x))
    if (x[i] == 0)
        x[i] = 9;
    else
    {
        x[i]--;
        return x;
    }
    assert(false);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> m >> d;
    
    vector<int> a = readNumber();
    vector<int> b = readNumber();
    
    cout << ((f(b) - f(minusOne(a)))+MOD)%MOD << "\n";
    
    return 0;
}