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

const int N=500050;
const int LOG=22;

int jmp[N], dis[N], longjmp[N][LOG];
int n; char str[N];

void init() {
    scanf("%d%s", &n, str+1);
    VI stack;
    jmp[0]=0; dis[0]=0;
    rep(i, 1, n) {
        jmp[i]=-1;
        if(str[i]=='(') {
            stack.pb(i);
        } else {
            if(!stack.empty()) {
                jmp[i]=stack.back()-1;
                dis[i]=dis[jmp[i]]+1;
                stack.pop_back();
            }
        }
    }
    repn(j, LOG) rep(i, 0, n) if (jmp[i]>=0) {
        longjmp[i][j]=(j==0 ? jmp[i] : longjmp[longjmp[i][j-1]][j-1]);
    }
}

struct Node {
    Node *succ[2], *f;
    int l;
    Node(int _l, Node* copy=nullptr) {
        if(copy) *this=*copy; else memset(this, 0, sizeof(Node));
        l=_l;
    }
} *root, *last;

void extend(int ch) {
    Node* p=last;
    Node* np=new Node(p->l+1);
    for(; p && !p->succ[ch]; p=p->f) {
        p->succ[ch]=np;
    }
    if(!p) {
        np->f=root;
    } else {
        Node* q=p->succ[ch];
        if(q->l==p->l+1) {
            np->f=q;
        } else {
            Node* nq=new Node(p->l+1, q);
            np->f=q->f=nq;
            for(; p && p->succ[ch]==q; p=p->f) {
                p->succ[ch]=nq;
            }
        }
    }
    last=np;
}

void solve() {
    last=root=new Node(0);
    LL ans=0;
    rep(i, 1, n) {
        extend(str[i]==')'?1:0);
        if(jmp[i]<0) continue;

        const int start=i-last->f->l;
        int j=i;
        irepn(k, LOG) if(jmp[longjmp[j][k]]+1>=start) j=longjmp[j][k];
        if(jmp[j]+1>start) j=jmp[j];
        ans+=dis[j];
    }
    cout<<ans<<endl;
}

int main() {
    init();
    solve();
    return 0;
}