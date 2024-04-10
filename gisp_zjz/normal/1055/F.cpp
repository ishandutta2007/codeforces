#include<bits/stdc++.h>
#define maxn 1000200

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<int,ll> pii;
map <pi,int> f;
vector <pii> h[maxn];
ll k,a[maxn],ans,d;
int n,w,L[maxn],R[maxn];

void dfs(int x,ll y){
    a[x]=y;
    for (int i=0;i<h[x].size();i++) dfs(h[x][i].first,h[x][i].second^y);
}

void build(int l,int r){
    if (a[l]==a[r]) return;
    ll u=a[l],v=a[r]; d=0;
    int ll=l,rr=r;
    while (u/2!=v/2) u>>=1,v>>=1,d++;
    while ((a[l]>>d)==u&&(a[r]>>d)==v) l++,r--;
    if ((a[l]>>d)!=u) f[(pi){ll,rr}]=l-1,build(ll,l-1),build(l,rr);
    else f[(pi){ll,rr}]=r,build(ll,r),build(r+1,rr);
}

int main(){
    cin >> n >> k;
    for (int i=2;i<=n;i++){
        scanf("%d%lld",&w,&d);
        h[w].push_back((pii){i,d});
    }
    dfs(1,0);
    sort(a+1,a+n+1);
    build(1,n);
    for (int i=1;i<=n;i++) L[i]=1,R[i]=n;
    for (int i=61;i>=0;i--){
        ll cnt=0;
        for (int j=1;j<=n;j++) if (L[j]<=R[j]){
            d=(a[j]>>i)&1;
            if ((a[L[j]]>>i)!=(a[R[j]]>>i)){
                int mid=f[(pi){L[j],R[j]}];
                if (d==1) cnt+=R[j]-mid; else cnt+=mid-L[j]+1;
            } else {
                if (((a[L[j]]>>i)&1)==d) cnt+=R[j]-L[j]+1;
            }
        }
        bool flag=0;
        //cout<<i<<' '<<cnt<<endl;
        if (cnt<k) k-=cnt,ans|=(1ll<<i),flag=1;
        //if (!flag) continue;
        for (int j=1;j<=n;j++) if (L[j]<=R[j]){
            d=(a[j]>>i)&1;
            if ((a[L[j]]>>i)!=(a[R[j]]>>i)){
                int mid=f[(pi){L[j],R[j]}];
                if (d^flag) L[j]=mid+1; else R[j]=mid;
            } else {
                if (((a[L[j]]>>i)&1)^d^flag) R[j]=L[j]-1;
            }
        }
    }
    cout << ans << endl;
}