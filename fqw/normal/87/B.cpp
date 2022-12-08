#include <algorithm>
#include <map>
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

int main() {
    map<string, int> stars;
    const auto parse=[&](string s) {
        int x=0, y=0;
        while(s[0]=='&') {
            ++x, s=s.substr(1);
        }
        while(s.back()=='*') {
            ++y, s.pop_back();
        }
        if(stars.count(s)==0) {
            stars[s]=-1;
        }
        if(stars[s]<0) {
            return -1;
        } else {
            return max(-1, stars[s]+y-x);
        }
    };
    stars["void"]=0;

    int n; cin>>n;
    while(n--) {
        string type, a; cin>>type>>a;
        if(type=="typedef") {
            string b; cin>>b;
            stars[b]=parse(a);
        } else {
            int i=parse(a);
            if(i<0) {
                cout<<"errtype"<<endl;
            } else {
                cout<<"void"<<string(i, '*')<<endl;
            }
        }
    }
    return 0;
}