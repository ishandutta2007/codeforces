#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)

constexpr int N=2e5+5;
int a[N], b[N], a1[N], b1[N], a2[N], b2[N];
int n, n1, n2;
ll sum; int ans, tans;

__attribute__((always_inline)) void smin(int& a, int b) {a = a < b ? a : b;}
#define max iowrhgrbrf
#define min ajebifbifq
__attribute__((always_inline)) int max(int a, int b) {return a < b ? b : a;}
__attribute__((always_inline)) int min(int a, int b) {return a < b ? a : b;}

int f(const int a1, const int b1, const int* __restrict a2, const int* __restrict b2, int n2) {
    tans=INT_MAX;
    rep(j, n2) smin(tans, max(a2[j], b1)-min(a1, b2[j]));
    return tans;
}

int32_t main() {
    fastio;
    cin>>n;
    rep(i, n) cin>>a[i];
    rep(i, n) cin>>b[i];
    rep(i, n) {
        if(a[i]>b[i]) a1[n1]=a[i], b1[n1]=b[i], n1++;
        else if(a[i]<b[i]) a2[n2]=a[i], b2[n2]=b[i], n2++;
        sum+=abs(a[i]-b[i]);
    }
    rep(i, n1) smin(ans, f(a1[i], b1[i], a2, b2, n2));
    cout<<sum+2LL*ans<<endl;
}