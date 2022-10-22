/**
 *    author:  gary
 *    created: 01.10.2021 13:39:46
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e5+1;
int n;
int a[MAXN];
int dp[MAXN],pre[MAXN],is[MAXN],ans[MAXN];
int main(){
    cin>>n;
    vector<mp> v;
    rb(i,1,n) scanf("%d",&a[i]),v.PB(II(a[i],i));
    sort(ALL(v));
    sort(a+1,a+1+n);
    rb(i,1,n) is[i]=v[i-1].SEC;
    memset(dp,63,sizeof(dp));
    dp[0]=0;
    rb(i,1,n){
        rb(j,3,min(6,i)){
            if(dp[i-j]+a[i]-a[i-j+1]<dp[i]){
                dp[i]=dp[i-j]+a[i]-a[i-j+1];
                pre[i]=j;
            }
        }
    }
    printf("%d ",dp[n]);
    int now=n;
    int cnt=0;
    while(now){
        int z=pre[now];
        ++cnt;
        rep(j,z){
            ans[is[now-j]]=cnt;
        }
        now-=z;
    }
    cout<<cnt<<endl;
    rb(i,1,n) printf("%d ",ans[i]);
    return 0;
}