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
#define N 262144
int dp[2005][2005];
int mod=1e9+7;
int cal(char *c,int m,int d){
    MEM(dp);
    int len=strlen(c);
    int now=0;
    int ok=1;
    for(int i = 0;c[i]!=0;i++){
        if(ok)
        for(int j=0;j<c[i]-'0';j++){
            if(i==0&&j==0)continue;
            if((i%2==0&&j!=d)||(i%2==1&&j==d)){
                dp[i][(now*10+j)%m]++;
            }
        }
        if(i%2==0&&c[i]-'0'==d)ok=0;
        if(i%2!=0&&c[i]-'0'!=d)ok=0;
        now=(now*10+c[i]-'0')%m;
    }
    int st=1;
    if(c[0]=='0'){
        st=2;
    }
    /*for(int i = st;c[i]!=0;i++){
        for(int j=1;j<=9;j++){
            if((i%2==0&&j!=d)||(i%2==1&&j==d)){
                dp[i][j%m]++;
            }
        }
    }*/
    for(int i = 0;c[i]!=0;i++){
        for(int j=0;j<m;j++){
         //   printf("%d %d %d\n",i,j,dp[i][j]);
            if(c[i+1]!=0)
            for(int k=0;k<10;k++){
                if((i%2==1&&k!=d)||(i%2==0&&k==d)){
                    dp[i+1][(j*10+k)%m]+=dp[i][j];
                     dp[i+1][(j*10+k)%m]%=mod;
                }
            }
        }
    }
    return dp[len-1][0];
}
int main(){
    int m,d;
    scanf("%d %d",&m,&d);
    char a[2005],b[2005];
    scanf("%s %s",a+1,b+1);
    a[0]=b[0]='0';
    int len=strlen(a+1);
    int cnt=1;
   // if(len%2==0){
        int sum=(b[1]-'0')%m;
        if(b[1]==d+'0')cnt=0;
        for(int i = 2;b[i]!=0;i+=2){
            if(b[i]!=d+'0')cnt=0;
            if(b[i-1]==d+'0')cnt=0;
            sum=(sum*10+b[i]-'0')%m;
        }
        if(sum)cnt=0;
    //}
   /* else{
        int sum=0;
        for(int i = 1;b[i]!=0;i+=2){
            if(b[i]!=d+'0')cnt=0;
            if(b[i+1]==d+'0')cnt=0;
            sum=(sum*10+b[i]-'0')%m;
        }
        if(sum)cnt=0;
    }*/
    //if(len%2==0)
   // printf("%d\n",cnt);
    printf("%d\n",((cal(b+1,m,d)-cal(a+1,m,d)+cnt)%mod+mod)%mod);
   // else{
    //    printf("%d\n",((cal(b,m,d)-cal(a,m,d)+cnt)%mod+mod)%mod);
    //}
}

/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/