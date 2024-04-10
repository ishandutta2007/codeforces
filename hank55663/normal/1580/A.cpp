#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    char c[405][405];
    for(int i = 1;i<=n;i++){
        scanf("%s",c[i]+1);
    }
    int ans=1e9;
    for(int i = 1;i<=n;i++){
        int a[405];
        int b[405];
        for(int j =1;j<=m;j++){
            if(c[i][j]=='1')a[j]=0;
            else a[j]=1;
            b[j]=0;
        }
       // for(int k=1;k<=m;k++)printf("%d ",a[k]);
       // printf("\n");
        for(int j = i+1;j<=n;j++){
            for(int k=1;k<=m;k++){
                if(c[j][k]=='1');//a[j]++;
                else a[k]++;
               // printf("%d ",a[k]);
            }
           // printf("\n");
           //  for(int k=1;k<=m;k++)printf("b:%d ",b[k]);
       // printf("\n");
            if(j-i>=4){
                for(int k = 1;k<=m;k++)a[k]+=a[k-1];
                int l=0;
                int Min=1e9;
                for(int k = 4;k<=m;k++){
                    Min=min(Min,b[k-3]-a[k-3]);
                    ans=min(ans,a[k-1]+b[k]+Min);
                   // printf("%d %d %d\n",Min,a[k-1],b[k]);
                }
                for(int k=m;k>=1;k--)a[k]-=a[k-1];
            }
            for(int k = 1;k<=m;k++){
                if(c[j][k]=='1')a[k]++;
                else a[k]--,b[k]++;
            }
        }
    }
    printf("%d\n",ans);
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
7
34 38 10
8 32 9
3 7 10
5 13 9
23 40 5
28 34 1
24 26 10
*/