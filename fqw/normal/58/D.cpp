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

vector<string> a;
char delim;
int n;

struct cmp1 {
    bool operator()(int i, int j) {
        return a[i]+a[j]>a[j]+a[i];
    }
};

struct cmp2 {
    bool operator()(int i, int j) {
        return a[i]+delim+a[j]>a[j]+delim+a[i];
    }
};

int main() {
    cin>>n;
    a.resize(n);
    int len=0;
    repn(i, n) {
        cin>>a[i];
        len+=sz(a[i]);
    }
    len/=n/2;
    cin>>delim;

    vector<priority_queue<int, vector<int>, cmp1>> q1(len+1);
    priority_queue<int, vector<int>, cmp2> q2;
    repn(i, n) {
        q1[sz(a[i])].push(i);
        q2.push(i);
    }
    vector<bool> used(n, false);
    repn(k, n/2) {
        int i, j;
        do {
            i=q2.top();
            q2.pop();
        } while(used[i]);
        used[i]=true;
        do {
            j=q1[len-sz(a[i])].top();
            q1[len-sz(a[i])].pop();
        } while(used[j]);
        used[j]=true;
        cout<<a[i]<<delim<<a[j]<<endl;
    }
    return 0;
}