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
#define N 500005
#define rank Rank
int dp[2][2][2][2][8];
const int mod=998244353;
void solve(){
    char s[200005];
    scanf("%s",s);
    MEM(dp);
    dp[1][0][0][0][0]=1;
    for(int i = 0;s[i]!=0;i++){
        MEM(dp[i&1]);
        for(int a=0;a<2;a++){
            for(int b=0;b<2;b++){
                for(int c=0;c<2;c++){
                    for(int x=0;x<2;x++){
                        for(int y=0;y<2;y++){
                            for(int z=0;z<2;z++){
                                if(a==0&&x==1&&s[i]=='0')continue;
                                if(b==0&&y==1&&s[i]=='0')continue;
                                if(c==0&&z==1&&s[i]=='0')continue;
                                int ta,tb,tc;
                                if(a==1||(a==0&&x==0&&s[i]=='1'))ta=1;
                                else ta=0;
                                  if(b==1||(b==0&&y==0&&s[i]=='1'))tb=1;
                                else tb=0;
                                if(c==1||(c==0&&z==0&&s[i]=='1'))tc=1;
                                else tc=0;
                                int mask=0;
                                if(x+y+z==3);
                                else if(x&y)mask^=1;
                                else if(x&z)mask^=2;
                                else if(y&z)mask^=4;
                                else if(x)mask^=4;
                                else if(y)mask^=2;
                                else if(z)mask^=1;
                               
                                for(int bi=0;bi<8;bi++){
                                    {
                                    // if(i==0&&a==0&&b==0&&c==0&&bi==0){
                                      //   printf("%d %d %d %d %d %d %d %d\n",x,y,z,ta,tb,tc,dp[(i&1)^1][a][b][c][bi]);
                                     //}
                                     //else if(i==0){
                                     //    assert(dp[(i&1)^1][a][b][c][bi]==0)return;
                                     //}
                                    }
                                    dp[i&1][ta][tb][tc][bi|mask]+=dp[(i&1)^1][a][b][c][bi];
                                     dp[i&1][ta][tb][tc][bi|mask]%=mod;
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
        /*   for(int a=0;a<2;a++){
            for(int b=0;b<2;b++){
                for(int c=0;c<2;c++){
                    for(int bi=0;bi<8;bi++){
                      //  printf("%d %d %d %d %d %d\n",i,a,b,c,bi,dp[i&1][a][b][c][bi]);
                    }
                    }
                    }
                    }*/
    }
    int n=strlen(s)-1;
    int ans=0;
    for(int i = 0;i<2;i++){
        for(int j =0;j<2;j++){
            for(int k=0;k<2;k++){
                ans+=dp[n&1][i][j][k][7];
                ans%=mod;
            }
        }
    }
    printf("%d\n",ans);
}  
int main(){
    int t=1;000;
  //  scanf("%d",&t);
//    srand(time(NULL));
    while(t--){
        solve();
    }
    
}
/*
*/