#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
typedef long long ll;
const int M=998244353;
const int maxn=1e6+10;
int _,n,m,ans[maxn];
struct gp{
    ll sz,sum,offset;
    int id;
}b[maxn];
vector<ll> v[maxn];
ll a[maxn];
bool cmp(gp u,gp v){
    return u.sum*v.sz>v.sum*u.sz;
}
int s[3][maxn];
bool valid(int o,int l,int r){
    return s[o][r]-s[o][l-1]==r-(l-1);
}
bool check(ll x,gp y){
    return x*y.sz>=y.sum;
}
void solve(){
    scanf("%d%d",&m,&n);
    for (int i=1;i<=m;i++) scanf("%lld",&a[i]);
    sort(a+1,a+m+1); reverse(a+1,a+m+1);
    int cnt=0;
    for (int i=1;i<=n;i++){
        b[i].sum=0; b[i].id=i;
        int k;scanf("%d",&k);
        b[i].sz=k; v[i].clear();
        while (k--){
            ll x;scanf("%lld",&x);
            b[i].sum+=x; v[i].pb(x);
        }
        b[i].offset=cnt;
        cnt+=b[i].sz;
    }
    sort(b+1,b+n+1,cmp);
    for (int i=1;i<=n;i++){
        s[0][i]=s[0][i-1]+check(a[i],b[i]);
        s[1][i]=s[1][i-1]+check(a[i],b[i+1]);
        s[2][i]=s[2][i-1]+check(a[i],b[i-1]);
    }
    for (int i=1;i<=n;i++){
        int pos=b[i].offset;
        for (auto x:v[b[i].id]){
            pos++;
            gp tmp=b[i];
            tmp.sz--; tmp.sum-=x;
            int l=0,r=n+1;
            while (r-l>1){
                int mid=(l+r)>>1;
                if (cmp(b[mid],tmp)) l=mid; else r=mid;
            }
            if (i<r){
            // i -> l
                ans[pos]=valid(0,1,i-1)&&valid(0,l+1,n)&&valid(1,i,l-1)&&check(a[l],tmp);
            } else {
            // i -> r
                ans[pos]=valid(0,1,r-1)&&valid(0,i+1,n)&&valid(2,r+1,i)&&check(a[r],tmp);
            }
        }
    }
    for (int i=1;i<=cnt;i++) printf("%d",ans[i]); puts("");
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
    return 0;
}