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
pair<pii,int> dp[44][44][44][44];
void solve(){
    MEM(dp);
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    char c[45];
    scanf("%s",c);
    dp[0][0][0][0]=mp(mp(0,0),1);
    for(int i = 0;i<n;i++){
        for(int j=0;j<=i;j++){
            for(int x=0;x<a;x++){
                for(int y=0;y<b;y++){
                  //  printf("??? %d %d %d %d\n",x,y,j,j-i);
                    if(dp[x][y][j][i-j].y){
                      //  printf("%d %d %d %d\n",x,y,j,j-i);
                      //  printf("? %d %d %d %d\n",(x*10+c[i]-'0')%a,y,j+1,j-i);
                      //  printf("? %d %d %d %d\n",x,(y*10+c[i]-'0')%b,j,j-i+1);
                        dp[(x*10+c[i]-'0')%a][y][j+1][i-j]=mp(mp(x,y),1);
                        dp[x][(y*10+c[i]-'0')%b][j][i-j+1]=mp(mp(x,y),2);
                    }
                }
            }
        }
    }
    int ans=100;
    for(int i = 1;i<n;i++){
        if(dp[0][0][i][n-i].y){
            ans=min(ans,abs(n-i-i));
        }
    }
    if(ans==100){
        printf("-1\n");
    }
    else{
        for(int i = 1;i<n;i++){
            if(dp[0][0][i][n-i].y){
                if(abs(n-i-i)==ans){
                    vector<int> v;
                    int x=0,y=0,cx=i,cy=n-i;
                    while(cx||cy){
                        auto p=dp[x][y][cx][cy];
                        v.pb(p.y);
                        x=p.x.x;
                        y=p.x.y;
                        if(p.y==1)cx--;
                        else cy--;
                    }
                    reverse(v.begin(),v.end());
                    char c[4]=" RB";
                    for(auto it:v)printf("%c",c[it]);
                    printf("\n");
                    return;
                }
            }
        }
    }
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
*/