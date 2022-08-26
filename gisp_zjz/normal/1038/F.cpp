#include<bits/stdc++.h>
#define maxn 123456
#define F first
#define S second

using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
char t[50],c;
ll dp[50][50][2],n,m,nxt[50],fail[50],ans,pos;

void get_nxt()
{
    ll i,j;
    j=nxt[0]=-1;
    i=0;
    while (i<m)
        if (j==-1||t[i]==t[j]) nxt[++i]=++j; else j=nxt[j];
    //for (int i=1;i<=m;i++) printf("%d ",nxt[i]); printf("\n");
}

int main(){
    cin >> n >> t;
    m=strlen(t);
    get_nxt();
    dp[0][0][0]=1; fail[0]=0;
    for (int i=0;i<m;i++){
        int j=i;
        while (j>0&&t[j]==t[i]) j=nxt[j];
        if (t[j]==t[i]) fail[i]=0; else fail[i]=j+1;
    }
    for (int x=0;x<m;x++){
        pos=0;
        for (int i=0;i<x;i++) {
            if (t[pos]==t[m-x+i]) pos++; else pos=fail[pos];
        }
        memset(dp,0,sizeof(dp));
        dp[x][pos][0]=1;
        for (int i=x;i<n;i++)
            for (int j=0;j<=m;j++){
                dp[i+1][j][1]+=dp[i][j][1]*2;
                //if (x==2&&dp[i][j][1])cout<<i+1<<' '<<j<<' '<<dp[i][j][1]*2<<endl;
                if (j==m) continue;
                dp[i+1][j+1][(j+1)==m]+=dp[i][j][0];
                dp[i+1][fail[j]][0]+=dp[i][j][0];
                //if (x==2&&dp[i][j][0])cout<<i+1<<' '<<j<<' '<<j+1<<' '<<dp[i][j][0]<<endl;
                //if (x==2&&dp[i][j][0])cout<<i+1<<' '<<j<<' '<<fail[j]<<' '<<dp[i][j][0]<<endl;
            }
        ans+=dp[n][m-x][x==0];
        for (int i=m-x+1;i<m;i++){
            bool flag=true; pos=i;
            for (int j=0;j<x;j++) {
                if (t[pos]==t[m-x+j]) pos++; else pos=fail[pos];
                if (j!=x-1&&pos==m) {flag=false;break;}
            }
            //cout<<x<<' '<<i<<' '<<pos<<endl;
            if (flag&&pos==m) ans+=dp[n][i][0];
        }
        //cout<<ans<<endl;
    }
    cout << ans << endl;
}