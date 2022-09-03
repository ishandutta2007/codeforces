#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int cnt1[3005],cnt2[3005];
void solve(){
    int n;
    scanf("%d",&n);
    LL ans=0;
    int a[3005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]),cnt1[a[i]]++;
    LL val=0;
    for(int i = 0;i<n;i++){
        cnt1[a[i]]--;
        for(int j = i+1;j<n;j++){
            cnt1[a[j]]--;
            val-=cnt2[a[j]];
            if(a[i]==a[j]){
                ans+=val;
            }
            cnt2[a[j]]++;
            val+=cnt1[a[j]];
        }
        for(int j = i+1;j<n;j++){
            cnt1[a[j]]++;
            cnt2[a[j]]--;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/