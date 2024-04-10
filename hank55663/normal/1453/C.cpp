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
using namespace std;
#define MXN 100005
int val[2005][2005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            char c;
            scanf(" %c",&c);
            val[i][j]=c-'0';
        }
    }
    for(int i = 0;i<=9;i++){
        int Maxx=0,Minx=1e9,Maxy=0,Miny=1e9;
        int cnt=0;
        for(int j = 0;j<n;j++){
            for(int k=0;k<n;k++){
                if(val[j][k]==i){
                    Maxx=max(Maxx,j);
                    Minx=min(Minx,j);
                    Maxy=max(Maxy,k);
                    Miny=min(Miny,k);
                    cnt++;
                }
            }
        }
        if(cnt<2){
            printf("0 ");
        }
        else{
            int ans=0;
            for(int j=0;j<n;j++){
                for(int k = 0;k<n;k++){
                    if(val[j][k]==i){
                        ans=max(ans,(Maxx-j)*(n-1-k));
                        ans=max(ans,(Maxx-j)*(k));
                        ans=max(ans,(j-Minx)*(n-1-k));
                        ans=max(ans,(j-Minx)*(k));
                        ans=max(ans,(n-1-j)*(Maxy-k));
                        ans=max(ans,(n-1-j)*(k-Miny));
                        ans=max(ans,(j)*(Maxy-k));
                        ans=max(ans,(j)*(k-Miny));
                    }
                }
            }
           // printf("%d\n",ans);
            for(int j = 0;j<n;j++){
                int Max=0,Min=1e9;
                for(int k = 0;k<n;k++){
                    if(val[j][k]==i){
                        Max=max(Max,k);
                        Min=min(Min,k);
                    }
                }
                if(Max>=Min)
                ans=max(ans,(Max-Min)*max(j,n-j-1));
               // printf("%d %d %d\n",Max,Min,i);
                Max=0,Min=1e9;
                for(int k = 0;k<n;k++){
                    if(val[k][j]==i){
                        Max=max(Max,k);
                        Min=min(Min,k);
                    }
                }
                if(Max>=Min)
                 ans=max(ans,(Max-Min)*max(j,n-j-1));
                  //printf("%d %d\n",Max,Min);
            }
            printf("%d ",ans);
        }
    }
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
       solve();
    }
}
/*
*/