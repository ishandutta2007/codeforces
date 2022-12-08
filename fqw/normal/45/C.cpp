#include <algorithm>
#include <set>
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

const int N=200000;

struct Node {
    int i, a;
    bool sex;
    Node *prev, *next;
} a[N];
set<PII> s;

void add(Node* p) {
    if(p==nullptr || p->next==nullptr) return;
    if(p->sex!=p->next->sex) {
        s.insert(mp(abs(p->a-p->next->a), p->i));
    }
}

void erase(Node* p) {
    if(p==nullptr || p->next==nullptr) return;
    if(p->sex!=p->next->sex) {
        s.erase(mp(abs(p->a-p->next->a), p->i));
    }
}

int main() {
    int n; scanf("%d", &n);
    string sex; cin>>sex;
    repn(i, n) {
        scanf("%d", &a[i].a);
        a[i].i=i, a[i].sex=(sex[i]=='B');
        a[i].prev=(i==0 ? nullptr : a+i-1);
        a[i].next=(i==n-1 ? nullptr : a+i+1);
    }
    repn(i, n) add(a+i);

    VPI ans;
    while(!s.empty()) {
        const int i=s.begin()->se, j=a[i].next->i;
        ans.pb(mp(i, j));
        Node *l=a[i].prev, *r=a[j].next;
        erase(l), erase(a+i), erase(a+j);
        if(l) l->next=r; if(r) r->prev=l;
        add(l);
    }
    printf("%d\n", sz(ans));
    for(PII p: ans) printf("%d %d\n", p.fi+1, p.se+1);

    return 0;
}