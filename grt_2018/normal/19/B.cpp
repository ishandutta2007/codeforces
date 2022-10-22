#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

const int MAXN = 2001;
const LL INF = (LL)1000*1000*1000*1000*1000*1000;
int n;
int t[MAXN],c[MAXN];
LL dp[MAXN*MAXN+100];
LL ans=INF;
LL s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n;i++) {
        cin>>t[i]>>c[i];
        t[i]++;
        s+=t[i];
    }
    dp[0] = 0;
    for(int i=1; i<=s;i++) dp[i]=INF;
    for(int i=1; i<=n;i++) {
        for(int j=n; j>=0; j--) {
            dp[j+t[i]] = min(dp[j+t[i]],dp[j]+c[i]);
        }
    }
    for(int i=n;i<=s;i++) {
        ans=min(ans,dp[i]);
    }
    cout<<ans;
}