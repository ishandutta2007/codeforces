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

int a[100010], cnt[100010], cnt2[100010];
int n;

int find_even() {
    fillchar(cnt2, 0);
    int j0=n;
    while(j0>n/2) {
        ++cnt2[a[j0]];
        if(cnt2[a[j0]]*2>cnt[a[j0]]) break;
        --j0;
    }
    if(j0<=n/2) {
        fillchar(cnt2, 0);
        int j1=1, nonzeros=0;
        while(j1<=j0) {
            nonzeros-=(cnt2[a[j1]]!=0);
            nonzeros-=(cnt2[a[n-j1+1]]!=0);
            ++cnt2[a[j1]], --cnt2[a[n-j1+1]];
            nonzeros+=(cnt2[a[j1]]!=0);
            nonzeros+=(cnt2[a[n-j1+1]]!=0);
            if(nonzeros==0)
                break;
            ++j1;
        }
        while(j0>=j1 && a[j0]==a[n-j0+1])
            --j0;
    }
    return j0;
}

int find_odd() {
    fillchar(cnt2, 0);
    int j0=n;
    while(j0>n/2+1) {
        ++cnt2[a[j0]];
        if(cnt2[a[j0]]*2>cnt[a[j0]]) break;
        --j0;
    }
    if(j0<=n/2+1) {
        fillchar(cnt2, 0);
        int j1=1, nonzeros=0;
        while(j1<=j0) {
            nonzeros-=(cnt2[a[j1]]!=0);
            nonzeros-=(cnt2[a[n-j1+1]]!=0);
            ++cnt2[a[j1]], --cnt2[a[n-j1+1]];
            nonzeros+=(cnt2[a[j1]]!=0);
            nonzeros+=(cnt2[a[n-j1+1]]!=0);
            if(nonzeros==0)
                break;
            ++j1;
        }
    //printf("j1=%d\n",j1);
        while(j0>j1 && a[j0]==a[n-j0+1])
            --j0;
    }
    //printf("j0=%d\n",j0);
    return j0;
}

LL go() {
    int j0;
    if(n%2==0) j0=find_even();
        else j0=find_odd();
    LL ans=0;
    rep(i, 1, n) {
        int j=n-i+1;
        int j1=max(j0, i);
        int j2=j-1;
        if(j1<=j2) ans+=j2-j1+1;
        if(a[i]!=a[j]) break;
    }
    return ans;
}

LL solve() {
    fillchar(cnt, 0);
    rep(i, 1, n) cnt[a[i]]++;
    int odd_cnt=0;
    rep(i, 1, n) if(cnt[i]%2!=0) ++odd_cnt;
    if(odd_cnt>1) return 0;

    int i=1, j=n;
    LL ans=0;
    while(i<=j) {
        ++ans;
        if(a[i]!=a[j]) break;
        ++i, --j;
    }

    ans+=go();
    reverse(a+1, a+n+1);
    ans+=go();

    return ans;
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    LL ans=solve();
    cout<<ans<<endl;
    return 0;
}