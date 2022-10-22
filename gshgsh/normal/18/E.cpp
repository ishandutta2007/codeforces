#include<iostream>
#include<cstring>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define F first
#define S second
#define INF 0x3fffffff
#define MAXN 501
int N,M,x[MAXN],y[MAXN],cnt[MAXN][2][26],f[MAXN][26][26];Pair pre[MAXN][26][26];
int main()
{
    cin>>N>>M;For(i,1,N)For(j,0,M-1){char c;cin>>c;cnt[i][j&1][c-'a']++;}
    For(i,1,N)For(j,0,25)For(k,0,25)if(j!=k){f[i][j][k]=INF;For(a,0,25)if(a!=j)For(b,0,25)if(a!=b&&b!=k&&f[i][j][k]>f[i-1][a][b])f[i][j][k]=f[i-1][a][b],pre[i][j][k]={a,b};f[i][j][k]+=M-cnt[i][0][j]-cnt[i][1][k];}
    int ans=f[N][0][1];Pair now={0,1};For(i,0,25)For(j,0,25)if(i!=j&&ans>f[N][i][j])ans=f[N][i][j],now={i,j};cout<<ans<<endl;
    int i=N;while(i>=1)x[i]=now.F,y[i]=now.S,now=pre[i--][now.F][now.S];For(i,1,N){For(j,0,M-1)cout<<char((j&1?y[i]:x[i])+'a');cout<<endl;}return 0;
}