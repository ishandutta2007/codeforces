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

int main() {
    string s; getline(cin, s);
    while(1) {
        const auto i=s.find("  ");
        if(i==string::npos) break;
        s.erase(s.begin()+i);
    }
    while(1) {
        bool found=false;
        repn(i, sz(s)) if(s[i]==' ') {
            if(i>0 && i+1<sz(s) && isdigit(s[i-1]) && isdigit(s[i+1])) {
                continue;
            }
            s.erase(s.begin()+i);
            found=true;
            break;
        }
        if(!found) break;
    }
    while(1) {
        bool found=false;
        repn(i, sz(s)) if(s[i]==',') {
            if(i+1==sz(s) || s[i+1]==' ') continue;
            s.insert(s.begin()+i+1, ' ');
            found=true;
            break;
        }
        if(!found) break;
    }
    while(1) {
        bool found=false;
        repn(i, sz(s)) if(s[i]=='.') {
            if(i==0 || s[i-1]==' ') {
                i+=2;
                continue;
            }
            s[i+1]=s[i+2]='*';
            s.insert(s.begin()+i, ' ');
            found=true;
            break;
        }
        if(!found) break;
    }
    for(char& c: s) if(c=='*') c='.';
    cout<<s<<endl;

    return 0;
}