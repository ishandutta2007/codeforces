#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

const int MAXN = 200*1000+1;
int n,m,k,a[MAXN];
pi offer[MAXN];
LL dp[2001];
int best[2001];
LL pref[2001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1; i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1; i<=k;i++) pref[i]=pref[i-1]+a[i];
    for(int i=0; i<m;i++) {
        cin>>offer[i].ST>>offer[i].ND;
    }
    sort(offer,offer+m);
    for(int i=0; i<m;i++) {
        if(offer[i].ST<=k) {
            best[offer[i].ST] = offer[i].ND;
        }
    }
    for(int i=1; i<=k;i++) {
        dp[i] = dp[i-1]+a[i];
        for(int j=1; j<=k; j++) {
            if(i<j) continue;
            dp[i] = min(dp[i],dp[i-j] + pref[i] - pref[i-j+best[j]]);
            //cout<<j<<" "<<best[j]<<"\n";
        }
        //cout<<dp[i]<<"\n";
    }
    cout<<dp[k];
}