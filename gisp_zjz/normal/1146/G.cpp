#include<bits/stdc++.h>
#define maxn 300050
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
ll dp[55][55][55],f[55][55][55],s[55][55],c[55];
int L[55],R[55],V[55],n,m,h;
void Max(ll &x,ll y){if (x<y) x=y;}

int main(){
    cin >> n >> h >> m;
    for (int i=0;i<m;i++) cin >> L[i] >> R[i] >> V[i] >> c[i];
    for (int len=1;len<=n;len++){
        for (int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            memset(s,0,sizeof(s));
            for (int i=0;i<m;i++) if (L[i]>=l&&R[i]<=r)
                for (int j=L[i];j<=R[i];j++) s[j][V[i]+1]+=c[i];
            for (int i=1;i<=n;i++)
                for (int j=2;j<=h;j++) s[i][j]+=s[i][j-1];
            for (int i=1;i<=h;i++){
                dp[l][r][i]=dp[l][r][i-1];
                for (int pos=l;pos<=r;pos++) Max(dp[l][r][i],dp[l][pos-1][i]+dp[pos+1][r][i]+i*i-s[pos][i]);
            }
        }
    }
    cout << dp[1][n][h] << endl;
}