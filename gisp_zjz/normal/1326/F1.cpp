#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
const int N=14;
int n,r,id[1<<N],d[1<<N],cnt[N],to[1<<N][N],rev[1<<N][N],cc[N];
vector <int> g[N];
ll ans[1<<N];
ll dp[2][5125120];
bool a[N][N];
char s[N];

int main(){
    cin >> n; r=(1<<n)-1;
    for (int i=1;i<=r;i++) d[i]=d[i/2]+i%2;
    for (int i=1;i<=r;i++) {
        id[i]=cnt[d[i]]++;
        g[d[i]].pb(i);
        int tt=0;
        for (int j=0;j<n;j++) if ((i>>j)&1) {
            to[i][tt]=j;
            rev[i][j]=tt;
            tt++;
        }
    }
    for (int i=1;i<=n;i++) cc[i]=(cnt[i]*i)<<(i-1);

    for (int i=0;i<n;i++){
        cin >> s;
        for (int j=0;j<n;j++) a[i][j]=(s[j]=='1');
    }
    for (int i=0;i<n;i++) dp[1][i]=1;
    for (int i=1;i<n;i++){
        int o=i&1;
        int w=(1<<(i-1))-1;
        for (int j=0;j<cc[i+1];j++) dp[o^1][j]=0;
        for (int j=0;j<cc[i];j++){
            ll res=dp[o][j];
            int val=j&w,tmp=j>>(i-1);
            int mask=g[i][tmp/i];
            int s=to[mask][tmp%i];
            for (int t=0;t<n;t++) if (!(mask&(1<<t))){
                int nval=val*2+a[s][t];
                int nmask=mask|(1<<t);
                dp[o^1][((id[nmask]*(i+1)+rev[nmask][t])<<i)|nval]+=res;
            }
        }
    }
    int w=(1<<(n-1))-1;
    for (int i=0;i<cc[n];i++) ans[i&w]+=dp[n&1][i];
    for (int i=0;i<(1<<(n-1));i++) cout << ans[i] << ' '; cout << endl;
    return 0;
}