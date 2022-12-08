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

struct Node {
    int cnt[2]={0, 0};
    Node* ch[2]={nullptr, nullptr};
}* root;

int bit(int v, int d) {
    return (v&(1<<d))?1:0;
}

Node* insert(Node* x, int v, int d) {
    if(d<0) return nullptr;
    if(!x) x=new Node();
    int b=bit(v, d);
    ++x->cnt[b];
    x->ch[b]=insert(x->ch[b], v, d-1);
    return x;
}

int get_gt(Node* x, int xorv, int v, int d) {
    if(x==nullptr || d<0) return 0;
    int xorb=bit(xorv, d);
    int b=bit(v, d);
    if(b) {
        return get_gt(x->ch[1^xorb], xorv, v, d-1);
    } else {
        return get_gt(x->ch[0^xorb], xorv, v, d-1)+x->cnt[1^xorb];
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, k; cin>>n>>k;
    int s=0;
    root=insert(nullptr, 0, 30);

    LL ans=0;
    repn(i, n) {
        int x; cin>>x;
        s^=x;
        ans+=get_gt(root, s, k-1, 30);
        root=insert(root, s, 30);
    }
    cout<<ans<<endl;
    return 0;
}