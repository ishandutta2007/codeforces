#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0;
int n,last[maxn],sum[maxn],cnt[maxn],dp[maxn];
char s[maxn];
void solve(){
    cin >> n >> s+1;
    int cnt0=0,cnt1=0;
    for (int i=1;i<=n;i++){
        if (s[i]=='0') cnt0++; else cnt1++;
    }
    if (cnt0==0||cnt1==0){cout << 0 << endl;return;}
    if (cnt0<cnt1){
        reverse(s+1,s+n+1);
        for (int i=1;i<=n;i++) if (s[i]=='1') s[i]='0'; else s[i]='1';
    }
    int st=1; while (s[st]!='1') st++;
    sum[st-1]=0; cnt[st-1]=0;
    for (int i=0;i<=n;i++) last[i]=0,dp[i]=inf;
    for (int i=st;i<=n;i++){
        cnt[i]=cnt[i-1]+(s[i]=='1');
        sum[i]=sum[i-1]+(s[i]=='0')-(s[i]=='1');
        if (sum[i]>=0) last[sum[i]]=i;
    }
    dp[0]=1; int N=sum[n];
    if (N<0){
        for (int i=1;i<n;i++) if (s[i]>s[i+1]){cout << 1 << endl;return;}
        cout << 0 << endl;
        return;
    }
    for (int i=0;i<=N;i++){
        int x=i+cnt[last[i]];
        x=min(x,N);
        dp[x]=min(dp[x],dp[i]+1);
        dp[i+1]=min(dp[i+1],dp[i]+1);
    }
    cout << dp[N] << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}