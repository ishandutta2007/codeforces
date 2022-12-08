#include <algorithm>
#include <queue>
#include <map>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define sz(a) static_cast<int>(a.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=200010;

int n, k, b, c;
int t[N];

class Set {
    priority_queue<LL> q;
    LL s=0, d=0;

public:
    void insert(LL x) {
        x-=d;
        q.push(x); s+=x;
    }
    void add_all(LL v) {
        d+=v;
    }
    void remove_largest() {
        s-=q.top(); q.pop();
    }
    LL sum() const {
        return s+d*size();
    }
    int size() const {
        return sz(q);
    }
};

LL solve(int mod5) {
    map<int, VI> nums;
    rep(i, 1, n) {
        int x=t[i], d=(mod5-x%5+5)%5;
        nums[x+d].pb(c*d);
    }

    Set s;
    int cur=0;
    LL ans=1LL<<60;
    for(const auto& kv: nums) {
        s.add_all(LL(kv.fi-cur)/5*b);
        cur=kv.fi;
        for(int x: kv.se) s.insert(x);

        while(s.size()>k) s.remove_largest();
        if(s.size()==k) setmin(ans, s.sum());
    }
    return ans;
}

int main() {
    scanf("%d%d%d%d", &n,&k,&b,&c);
    setmin(b, 5*c);
    rep(i, 1, n) scanf("%d", &t[i]);
    sort(t+1, t+n+1);

    LL ans=1LL<<60;
    repn(i, 5) setmin(ans, solve(i));
    cout<<ans<<endl;
    return 0;
}