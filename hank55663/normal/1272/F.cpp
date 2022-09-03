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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
int dp[205][205][205];
pair<pii,int> from[205][205][205];
char s[205],t[205];
int DP(int x,int y,int val){
    if(val>200)return 1e9;
   // printf("%d %d %d\n",x,y,val);
    if(dp[x][y][val]!=-1)return dp[x][y][val];
    int suba=0,subb=0;
    if(s[x]==')')suba=1;
    if(t[y]==')')subb=1;
    dp[x][y][val]=DP(x-suba,y-subb,val+1)+1;
    from[x][y][val]=mp(mp(x-suba,y-subb),val+1);
    if(val!=0){
        suba=0,subb=0;
        if(s[x]=='(')suba=1;
        if(t[y]=='(')subb=1;
        int v=DP(x-suba,y-subb,val-1)+1;
        if(v<dp[x][y][val])
        dp[x][y][val]=v,from[x][y][val]=mp(mp(x-suba,y-subb),val-1);//min(dp[x][y][val],DP(x-suba,y-subb,val-1));
    }
    return dp[x][y][val];
}
int main(){

    scanf("%s %s",s+1,t+1);
    MEMS(dp);
    dp[0][0][0]=0;
    DP(strlen(s+1),strlen(t+1),0);
    int a=strlen(s+1),b=strlen(t+1),val=0;
    
    string s;
    while(a!=0||b!=0||val!=0){
        int ta=from[a][b][val].x.x;
        int tb=from[a][b][val].x.y;
        int tv=from[a][b][val].y;
        if(tv<val)
        s+="(";
        else
        s+=")";
        a=ta;
        b=tb;
        val=tv;
    }
    reverse(s.begin(),s.end());
    printf("%s\n",s.c_str());
}