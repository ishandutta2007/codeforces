#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
LL dp[55][55][55][3];
int mod=1e9+7;
LL DP(int a,int b,int c,int op){
    if(a<0||b<0||c<0)return 0;
    if(dp[a][b][c][op]!=-1)return dp[a][b][c][op];
    if(op==0){
        dp[a][b][c][op]=(DP(a,b-1,c,1)*b+DP(a,b,c-1,2)*c)%mod;
    }
    else if(op==1){
        dp[a][b][c][op]=(DP(a-1,b,c,0)*a+DP(a,b,c-1,2)*c)%mod;
    }  
    else if(op==2){
        dp[a][b][c][op]=(DP(a-1,b,c,0)*a+DP(a,b-1,c,1)*b)%mod;
    }
    return dp[a][b][c][op];
}
int cnt[2501][24000];
int number[55][55][55];
int inv[24000][3];
vector<int> v[2501];

int main(){
    int n,t;
    scanf("%d %d",&n,&t);
    int index=0;
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=i;j++){
            for(int k = 0;j+k<=i;k++){
                number[j][k][i-j-k]=index;
                inv[index][0]=j;
                inv[index][1]=k;
                inv[index][2]=i-j-k;
                index++;
            }
        }
    }
    MEMS(cnt);
    cnt[0][0]=1;
    v[0].pb(0);
    int tot=0;
    for(int i =0;i<n;i++){
        int x,y;//x=rand()%50+1,y=rand()%3+1;
        scanf("%d %d",&x,&y);
        for(int j=tot;j>=0;j--){
            for(int k :v[j]){
                int a,b,c;
                a=inv[k][0],b=inv[k][1],c=inv[k][2];
                if(a+b+c>i)
                break;
                if(y==1)a++;
                if(y==2)b++;
                if(y==3)c++;
                int num=number[a][b][c];
                if(cnt[j+x][num]==-1){
                    v[j+x].pb(num);
                    cnt[j+x][num]=0;
                }
                cnt[j+x][num]+=cnt[j][k];
               // printf("%d %d %d %d\n",j+x,a,b,c);
                cnt[j+x][num]%=mod;
            }
        }
        tot+=x;
    }
    LL ans=0;
    MEMS(dp);
    dp[0][0][0][0]=dp[0][0][0][1]=dp[0][0][0][2]=1;
    for(int k :v[t]){
        int a,b,c;
        a=inv[k][0],b=inv[k][1],c=inv[k][2];
     //   printf("%d %d %d\n",a,b,c);
        ans+=(LL)cnt[t][k]*(DP(a-1,b,c,0)*a%mod+DP(a,b-1,c,1)*b%mod+DP(a,b,c-1,2)*c%mod)%mod;
    }
    printf("%lld\n",ans%mod);
}
/*
m3->m2->m->m4
0 1 2 3 453*
0 1 3 2 4 4 2
0 1 4 2 3 3 2
0 2 1 3 4
0 2 3 1 4 4 1
0 2 4 1 3 3 1
0 3 1 2 4 4 2
0 3 2 1 4 4 1
0 4 1 
0 4 2
0 4 3

*/