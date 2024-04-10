#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int arr[30][200005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<30;i++)fill(arr[i],arr[i]+n+1,0);
    int ans[200005];
    fill(ans,ans+n+1,(1<<30)-1);
    for(int i = 0;i<m;i++){
        int l,r,x;
        scanf("%d %d %d",&l,&r,&x);
        for(int j = 0;j<30;j++){
            if(x&(1<<j));
            else{
                arr[j][l]++;
                arr[j][r+1]--;
            }
        }
    }
    for(int i = 0;i<30;i++){
        int now=0;
        for(int j = 1;j<=n;j++){
            now+=arr[i][j];
            if(now){
                ans[j]^=(1<<i);
            }
        }
    }
    const int mod=1e9+7;
    LL pro=1;
    LL aans=0;
    for(int j = 1;j<n;j++)pro=pro*2%mod;
    for(int i = 0;i<30;i++){
        int ok=0;
        for(int j=1;j<=n;j++){
            if(ans[j]&(1<<i))ok++;
        }
        if(ok){
            aans+=(1ll<<i)*pro%mod;
            aans%=mod;
        }
    }
    printf("%lld\n",aans);
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/