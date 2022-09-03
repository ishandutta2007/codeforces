#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define N 700005
int Size[1505];
int cnt[1505];
int f[1505];
LL dp[1505][1505];
int Max[1505];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    vector<pair<int,pii> > v;
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            scanf("%d",&x);
            if(j<i){
                v.pb(mp(x,mp(i,j)));
            }
        }
    }
    sort(v.begin(),v.end());
    for(int i = 0;i<n;i++){
        dp[i][1]=1;
        f[i]=i;
        Size[i]=1;
        Max[i]=1;
        cnt[i]=0;
    }
    for(auto it:v){
        int x,y;
        tie(x,y)=it.y;
        int fx=Find(x),fy=Find(y);
        if(fx!=fy){
        
            int tmp[1505];
            fill(tmp,tmp+1505,0);
            for(int i = 1;i<=Max[fx];i++){
                for(int j = 1;j<=Max[fy];j++){
                    tmp[i+j]+=dp[fx][i]*dp[fy][j]%mod;
                    tmp[i+j]%=mod;
                }
            }
            f[fx]=fy;
            Size[fy]+=Size[fx];
            cnt[fy]+=cnt[fx];
            Max[fy]+=Max[fx];
            cnt[fy]++;
            for(int i = 1;i<=Max[fy];i++)dp[fy][i]=tmp[i];
            if(cnt[fy]==Size[fy]*(Size[fy]-1)/2){
                dp[fy][1]++;
              //  printf("!\n");
            }
        }
        else{
            cnt[fx]++;
            if(cnt[fx]==Size[fx]*(Size[fx]-1)/2){
                dp[fx][1]++;
               // printf("?\n");
            }
        }
    }
    int x=Find(1);
    for(int i = 1;i<=n;i++)printf("%lld ",dp[x][i]);
    printf("\n");
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/