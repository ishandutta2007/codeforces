#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=(1<<17)+10;
int a[maxn],n,ans,k,cnt[maxn],dp[19][maxn][4];
vector <int> P,Q,t1,t2,t3,t4;
void Max(int &x,int y){
    if (y>x) x=y;
}
int main(){
    cin >> n >> k;
    for (int i=0;i<k;i++){
        int x; cin >> x; x--;
        a[x]=1;
    }
    if (!k){
        cout << 0 << endl;
        return 0;
    }
    int fr=0;
    for (int x=1;x<=n;x++)
    for (int i=0;i<(1<<(n-x));i++) dp[x][i][1]=dp[x][i][2]=dp[x][i][3]=-1e9;
    for (int i=0;i<(1<<(n-1));i++){
        fr+=max(a[i*2],a[i*2+1]);
        int x=a[i*2]+a[i*2+1];
        if (x==1){
            dp[1][i][1]=dp[1][i][2]=0;
        } else if (x==2) {
            dp[1][i][3]=0;
        }
        //cout<<dp[1][i][0]<<' '<<dp[1][i][1]<<' '<<dp[1][i][2]<<' '<<dp[1][i][3]<<endl;
    }
    for (int x=2;x<=n;x++)
    for (int i=0;i<(1<<(n-x));i++){
        for (int p=0;p<4;p++)
        for (int q=0;q<4;q++)
            Max(dp[x][i][p|q],dp[x-1][i*2][p]+dp[x-1][i*2+1][q]);
        for (int p=0;p<4;p++) dp[x][i][p]+=p;
    }
    ans=0;
    for (int i=0;i<4;i++) ans=max(ans,dp[n][0][i]);
    cout << fr+ans+1 << endl;
    return 0;
}