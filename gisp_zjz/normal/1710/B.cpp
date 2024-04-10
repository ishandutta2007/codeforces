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
const int maxn=2e6+10;
const int M=998244353;
int kase=0;
int n,tot,xa[maxn],pa[maxn];
struct node{
    int op,x,y;
}a[maxn];
bool cmp(node u,node v){
    if (u.x==v.x) return u.op<v.op;
    return u.x<v.x;
}
ll ans[maxn],m;
void add(int l,int r,int k,int b){
    a[tot++]=(node){0,l,k};
    a[tot++]=(node){0,r,-k};
    a[tot++]=(node){1,l,b};
    a[tot++]=(node){1,r,-b};
}
void solve(){
    cin >> n >> m;
    tot=0;
    for (int i=0;i<n;i++){
        int x,p; cin >> x >> p;
        xa[i]=x; pa[i]=p;
        a[tot++]=(node){2,x,i};
        add(x-p,x,1,-(x-p));
        add(x,x+p,-1,x+p);
    }
    sort(a,a+tot,cmp);
    ll K=0,B=0;
    for (int i=0;i<tot;i++){
        if (a[i].op==0){
            K+=a[i].y;
        } else if (a[i].op==1){
            B+=a[i].y;
        } else {
            ans[a[i].y]=K*a[i].x+B;
        }
    }
    //for (int i=0;i<n;i++)cout<<ans[i]<<' ';cout<<endl;
    ll ha=-inf,hb=-inf;
    for (int i=0;i<n;i++){
        if (ans[i]<=m) continue;
        ans[i]-=m;
        ha=max(ha,ans[i]+xa[i]);
        hb=max(hb,ans[i]-xa[i]);
    }
    for (int i=0;i<n;i++){
        if (pa[i]+xa[i]>=ha&&pa[i]-xa[i]>=hb) cout << 1; else cout << 0;
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}