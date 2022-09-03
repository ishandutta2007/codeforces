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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL Max[1<<18],Max2[1<<18];
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int nn=1;
    while(nn<=n)nn<<=1;
    nn--;
    for(int i = 0;i<=nn;i++){
        Max[i]=Max2[i]=0;
    }
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(Max[x]==0){
            Max[x]=i;
        }
        else{
            Max2[x]=Max[x];
            Max[x]=i;
        }
    }
    
    //printf("%lld\n",nn);
    for(int i = 0;(1<<i)<=n;i++){
        for(int j = 0;j<=nn;j++){
            if(j&(1<<i));
            else{
                int a=j|(1<<i);
                LL val[4]={Max[j],Max2[j],Max[a],Max2[a]};
                sort(val,val+4);
                Max[a]=val[3],Max2[a]=val[2];
            }
        }
    }
    LL ans=-1e18;
    for(int j =0;j<=nn;j++){
        if(Max[j]&&Max2[j]){
            ans=max(ans,Max[j]*Max2[j]-k*j);
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
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2

3 3 4 4
*/