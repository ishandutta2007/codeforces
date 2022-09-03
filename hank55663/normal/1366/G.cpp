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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
#define ll long long
short dp[10005][10005];
int main(){
    char s[10005],t[10005];
    scanf("%s %s",s+1,t+1);
    int ans=0,cnt=0;
    for(int i = 1;s[i]!=0;i++){
        if(s[i]=='.'){
            if(cnt)cnt--;
            else ans++;
        }
        else{
            cnt++;
        }
        dp[0][i]=ans+cnt;
    }
    for(int i = 1;t[i]!=0;i++){
        dp[i][0]=15000;
    }
    //for(int i = 1;t[i]!=0;i++){
    for(int j=1;s[j]!=0;j++){
        dp[1][j]=15000;
        if(t[1]==s[j]){
            dp[1][j]=dp[0][j-1];
        }
      //  printf("%d ",dp[1][j]);
        
    }
   // printf("\n");
    for(int i = 2;t[i]!=0;i++){
        vector<pii> v;
        int cnt=0;
        for(int j = 1;s[j]!=0;j++){
            dp[i][j]=15000;
            if(s[j]==t[i]&&v.size()){
                dp[i][j]=min(v.back().x+cnt-v.back().y,(int)dp[i][j]);
            }
            if(s[j]=='.')cnt--;
            else cnt++;
            if(!v.empty()&&v.back().y>cnt){
                pii p=v.back();
                v.pop_back();
                p.x+=p.y-cnt;
                p.y=cnt;
                while(v.size()&&v.back().y>=cnt&&v.back().x>p.x)v.pop_back();
                if(v.empty()||p.x<v.back().x+cnt-v.back().y)v.pb(p);
            }
            while(v.size()&&v.back().y>=cnt&&v.back().x>dp[i-1][j])v.pop_back();
            if(v.empty()||dp[i-1][j]<v.back().x+cnt-v.back().y){
                
                v.pb(mp(dp[i-1][j],cnt));
            }
          //  printf("%d ",dp[i][j]);
        }
      //  printf("\n");
    }
    int aans=20000;
    int len=strlen(t+1);
    for(int i = 1;s[i]!=0;i++){
        int cnt=0,tot=0;
        for(int j = i+1;s[j]!=0;j++){
            if(s[j]=='.'){
                if(cnt)cnt--;
                else tot++;
            }
            else cnt++;
        }
        aans=min(aans,dp[len][i]+cnt+tot);
    }
    printf("%d\n",aans);
    //}
}
/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/