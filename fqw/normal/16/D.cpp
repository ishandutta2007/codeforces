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

int parse_int(char x, char y) {
    return int(x-'0')*10+int(y-'0');
}

int parse(string s) {
    int h=parse_int(s[1], s[2]);
    int m=parse_int(s[4], s[5]);
    bool is_am=(s[7]=='a');
    if(h==12) h=0;
    if(!is_am) h+=24;
    return h*60+m;
}

int main() {
    int n; cin>>n;
    string s; getline(cin, s);
    int x=1, y=-1, cnt=0;
    while(n--) {
        getline(cin, s);
        int cur=parse(s);
        //cout<<s.substr(0, 12)<<" "<<cur<<endl;
        if(cur==y) {
            if(++cnt>10) {
                cnt=1;
                ++x;
            }
        } else {
            cnt=1;
            if(cur<y) ++x;
            y=cur;
        }
    }
    cout<<x<<endl;

    return 0;
}