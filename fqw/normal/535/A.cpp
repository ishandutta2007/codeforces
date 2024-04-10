#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

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
#ifdef DEBUG
    #define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
    #define _debug(args...) {}
#endif
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


int main() {
    function<string(int)> get = [&get](int x) -> string {
        if(x<10) {
            if(x==0) return "zero";
            if(x==1) return "one";
            if(x==2) return "two";
            if(x==3) return "three";
            if(x==4) return "four";
            if(x==5) return "five";
            if(x==6) return "six";
            if(x==7) return "seven";
            if(x==8) return "eight";
            if(x==9) return "nine";
        }
        int y=x%10; x/=10;
        string t;
        if(x==1) {
            x=y;
            if(x==0) return "ten";
            if(x==1) return "eleven";
            if(x==2) return "twelve";
            if(x==3) return "thirteen";
            if(x==4) return "fourteen";
            if(x==5) return "fifteen";
            if(x==6) return "sixteen";
            if(x==7) return "seventeen";
            if(x==8) return "eighteen";
            if(x==9) return "nineteen";
        }
        if(x==2) t="twenty";
        if(x==3) t="thirty";
        if(x==4) t="forty";
        if(x==5) t="fifty";
        if(x==6) t="sixty";
        if(x==7) t="seventy";
        if(x==8) t="eighty";
        if(x==9) t="ninety";
        if(y>0)
            t=t+"-"+get(y);
        return t;
    };
    int x;
    cin>>x;
    cout<<get(x)<<endl;
    return 0;
}