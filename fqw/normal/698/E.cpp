// 11:50
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

const int seconds_in_day=60*60*24;

bool is_leap_year(int y) { return y%4==0 && (y%100!=0 || y%400==0); }

int days_in_month(int y, int m) {
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) return 31;
    if(m==4 || m==6 || m==9 || m==11) return 30;
    if(m==2) return is_leap_year(y)?29:28;
    return 0;
}

int days_in_year(int y) {
    return is_leap_year(y)?366:365;
}

struct Time {
    int s=0, m=0, h=0;
    int day=4, date=1, month=1, year=1970;
    void read() { cin>>s>>m>>h>>day>>date>>month; }
};

Time from_unix(LL ut) {
    Time t;
    while(1) {
        int days=days_in_year(t.year);
        LL seconds=seconds_in_day*(LL)days;
        if(seconds>ut) break;
        ut-=seconds;
        t.day=(t.day-1+days)%7+1;
        t.year++;
    }
    while(1) {
        int days=days_in_month(t.year, t.month);
        LL seconds=seconds_in_day*(LL)days;
        if(seconds>ut) break;
        ut-=seconds;
        t.day=(t.day-1+days)%7+1;
        t.month++;
    }
    int days=int(ut/seconds_in_day);
    ut-=seconds_in_day*(LL)days;
    t.day=(t.day-1+days)%7+1;
    t.date+=days;
    t.h=int(ut/3600);
    ut-=t.h*3600;
    t.m=int(ut/60);
    ut-=t.m*60;
    t.s=int(ut);
    return t;
}

LL to_unix(Time t) {
    LL ut=0;
    rep(y, 1970, t.year-1) {
        ut+=seconds_in_day*(LL)days_in_year(y);
    }
    rep(m, 1, t.month-1) {
        ut+=seconds_in_day*(LL)days_in_month(t.year, m);
    }
    ut+=seconds_in_day*(LL)(t.date-1)+3600*t.h+60*t.m+t.s;
    return ut;
}

bool match(const Time& pattern, const Time& t) {
    if(pattern.s>=0 && pattern.s!=t.s) return false;
    if(pattern.m>=0 && pattern.m!=t.m) return false;
    if(pattern.h>=0 && pattern.h!=t.h) return false;
    if(pattern.month>=0 && pattern.month!=t.month) return false;
    if(pattern.day>=0 || pattern.date>=0) {
        bool ok=false;
        if(pattern.day>=0 && pattern.day==t.day) ok=true;
        if(pattern.date>=0 && pattern.date==t.date) ok=true;
        if(!ok) return false;
    }
    return true;
}

Time solve(Time pattern, Time t) {
    bool first=true;
    do {
        if(first || (pattern.s>=0 && pattern.s!=t.s) || (pattern.s<0 && t.s!=0)) {
            ++t.s;
        } else if((pattern.m>=0 && pattern.m!=t.m) || (pattern.m<0 && t.m!=0)) {
            ++t.m;
        } else if((pattern.h>=0 && pattern.h!=t.h) || (pattern.h<0 && t.h!=0)) {
            ++t.h;
        } else {
            t.day=t.day%7+1, ++t.date;
        }
        if(t.s==60) { t.s=0, ++t.m; }
        if(t.m==60) { t.m=0, ++t.h; }
        if(t.h==24) { t.h=0, t.day=t.day%7+1, ++t.date; }
        if(t.date>days_in_month(t.year, t.month)) {
            t.date=1, ++t.month;
        }
        if(t.month>12) { t.month=1, ++t.year; }
        first=false;
    } while(!match(pattern, t));
    return t;
}

int main() {
    Time pattern; pattern.read();
    int n; cin>>n;
    while(n--) {
        LL ut; cin>>ut;
        Time r=solve(pattern, from_unix(ut));
        cout<<to_unix(r)<<endl;
    }
    return 0;
}