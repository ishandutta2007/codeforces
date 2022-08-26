#include<bits/stdc++.h>
#define maxn 1000050
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
bool vis[maxn];
ll n,k,ans,sum;
priority_queue <ll, vector<ll>, greater<ll> > q;
pi a[maxn];

int main(){
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i].S >> a[i].F;
    sort(a+1,a+n+1);
    for (int i=n;i;i--){
        q.push(a[i].S); sum+=a[i].S;
        if (i<=n-k){
            sum-=q.top(); q.pop();
        }
        ans=max(ans,sum*a[i].F);
    }
    cout << ans << endl;
    return 0;
}