#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
int dp[6][210][210][4][4];
pii from[6][210][210][4][4];
int main(){
    int t;
    scanf("%d",&t);
    dp[0][0][0][0][0]=1;
    for(int i = 1;i<=5;i++){
        for(int j=0;j<205;j++){
            for(int k=0;k<205;k++){
                for(int aa=0;aa<3;aa++){
                    for(int bb=0;bb<3;bb++){
                        if(dp[i-1][j][k][aa][bb]){
                            int sc=25;
                            if(i==5)sc=15;
                           // if(j<25&&k<25){
                               // printf("%d %d %d %d %d\n",i-1,j,k,aa,bb);
                            //}
                            for(int a=0;a<sc-1&&j+a<205&&k+sc<205;a++){
                                dp[i][j+a][k+sc][aa][bb+1]=1;
                                from[i][j+a][k+sc][aa][bb+1]=mp(a,sc);
                            }
                            for(int b=0;b<sc-1&&k+b<205&&j+sc<205;b++){
                                dp[i][j+sc][k+b][aa+1][bb]=1;
                                from[i][j+sc][k+b][aa+1][bb]=mp(sc,b);
                            }
                            for(int a=sc+1;j+a<205&&a+k-2<205;a++){
                                int b=a-2;
                                dp[i][j+a][b+k][aa+1][bb]=1;
                                from[i][j+a][b+k][aa+1][bb]=mp(a,b);
                            }
                            for(int b=sc+1;k+b<205&&b+j-2<205;b++){
                                int a=b-2;
                                dp[i][j+a][b+k][aa][bb+1]=1;
                                from[i][j+a][b+k][aa][bb+1]=mp(a,b);
                            }
                        }
                    }
                }
            }
        }
    }
   // printf("%d\n",dp[5][20][0][2][3]);
    while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        int ok=0;
        for(int i=3;i<=5;i++){
            int nowa,nowb,nowaa,nowbb;
            if(dp[i][a][b][3][i-3]){
                ok=1;
                printf("%d:%d\n",3,i-3);
                nowa=a,nowb=b,nowaa=3,nowbb=i-3;
            }
            if(ok){
                vector<pii> v;
                for(int j=i;j>0;j--){
                    v.pb(from[j][nowa][nowb][nowaa][nowbb]);
                    nowa-=v.back().x;
                    nowb-=v.back().y;
                    if(v.back().x>v.back().y)nowaa--;
                    else nowbb--;
                }
                reverse(v.begin(),v.end());
                for(auto it:v)
                printf("%d:%d ",it.x,it.y);
                printf("\n");
                break;
            }
        }
        if(!ok){
            for(int i=5;i>=3;i--){
                int nowa,nowb,nowaa,nowbb;
                if(dp[i][a][b][i-3][3]){
                //   printf("%d %d %d %d %d\n",i,a,b,i-3,i)
                    ok=1;
                    printf("%d:%d\n",i-3,3);
                    nowa=a,nowb=b,nowaa=i-3,nowbb=3;
                }
                if(ok){
                    vector<pii> v;
                    for(int j=i;j>0;j--){
                        v.pb(from[j][nowa][nowb][nowaa][nowbb]);
                        nowa-=v.back().x;
                        nowb-=v.back().y;
                        if(v.back().x>v.back().y)nowaa--;
                        else nowbb--;
                    }
                    reverse(v.begin(),v.end());
                    for(auto it:v)
                    printf("%d:%d ",it.x,it.y);
                    printf("\n");
                    break;
                }
            }
        }
        if(!ok){
            printf("Impossible\n");
        }
    }
}