#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=1e6+100;
int t[3005],n,k;
vector<ll> v[3005];
ll s[3005],ans;
void solve(int l,int r,ll a[]){
    if (l==r){
        ll sum=0; ans=max(ans,a[k]);
        for (int i=0;i<t[l];i++){
            sum+=v[l][i];
            ans=max(ans,a[k-i-1]+sum);
        }
        return;
    }
    ll b[3005],c[3005];
    int mid=(l+r)>>1;
    for (int i=0;i<=k;i++) b[i]=c[i]=a[i];
    for (int i=l;i<=mid;i++)
        for (int j=k;j>=t[i];j--)
            c[j]=max(c[j],c[j-t[i]]+s[i]);
    for (int i=mid+1;i<=r;i++)
        for (int j=k;j>=t[i];j--)
            b[j]=max(b[j],b[j-t[i]]+s[i]);
    solve(l,mid,b);
    solve(mid+1,r,c);
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%d",&t[i]);
        for (int j=0;j<t[i];j++){
            ll x;scanf("%d",&x);
            if (j<k){
                s[i]+=x; v[i].pb(x);
            }
        }
        t[i]=min(t[i],k);
    }
    ll a[3005];
    for (int i=0;i<=k;i++) a[i]=0;
    solve(1,n,a);
    printf("%lld\n",ans);
    return 0;
}