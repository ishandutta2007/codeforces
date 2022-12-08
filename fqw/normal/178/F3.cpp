// 6:17
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
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
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

struct Node {
    vector<Node*> ys;
    int h=-1;
};

int main() {
    int n, k;
    cin>>n>>k;
    VS ss(n);
    repn(i, n) cin>>ss[i];
    sort(all(ss));
    VI height(n-1);
    repn(i, n-1) {
        int j=0;
        while(j<sz(ss[i]) && j<sz(ss[i+1]) && ss[i][j]==ss[i+1][j]) {
            ++j;
        }
        height[i]=j;
    }

    const function<Node*(int, int)> build=[&](int l, int r) {
        Node* x=new Node();
        if(l+1==r) return x;
        int h=*min_element(height.begin()+l, height.begin()+r-1);
        x->h=h;
        int i=l;
        replr(j, l, r) {
            if(j==r-1 || height[j]==h) {
                x->ys.pb(build(i, j+1));
                i=j+1;
            }
        }
        return x;
    };
    Node* root=build(0, n);

    const function<VI(Node*)> solve=[&](Node* x) {
        if(x->h<0) return VI{0, 0};
        VI ans{0};
        for(Node* y: x->ys) {
            VI tmp=solve(y);
            VI r(sz(ans)+sz(tmp)-1);
            repn(i, sz(ans)) repn(j, sz(tmp)) {
                setmax(r[i+j], ans[i]+tmp[j]+i*j*x->h);
            }
            ans=r;
        }
        if(sz(ans)>k+1) ans.resize(k+1);
        return ans;
    };
    VI ans=solve(root);
    if(k<sz(ans)) {
        cout<<ans[k]<<endl;
    } else {
        cout<<0<<endl;
    }

    return 0;
}