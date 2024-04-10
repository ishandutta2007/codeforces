#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;
const int maxn=1e6+12;
int n;
ll ans,a[maxn];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int x; scanf("%d",&x);
        a[x+n-i]+=x;
    }
    for (int i=0;i<maxn;i++) ans=max(ans,a[i]);
    cout << ans << endl;
}