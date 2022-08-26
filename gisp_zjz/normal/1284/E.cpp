#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=2555;
const int E=2e9+7;
const int EE=1e4+83;
ll x[maxn],y[maxn],ans,sum;
ll sqr(ll x){return x*x;}
pi p[maxn],b[maxn*maxn],V[maxn][maxn];
unordered_map <ll,int> f;
int a[maxn][maxn],c[maxn*maxn],pos[maxn];
int n;
bool cmp(pi x,pi y){
    pi u=V[x.F][x.S];
    pi v=V[y.F][y.S];
    if (u.F*v.S==v.F*u.S) {
        if (x.F!=y.F) return x.F<y.F;
        return x.S<y.S;
    }
    return u.F*v.S<v.F*u.S;
}
ll mut(pi x,pi y,pi z){
    return (y.F-x.F)*(z.S-x.S)-(y.S-x.S)*(z.F-x.F);
}
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) c[i*(i-1)/2]=i;
    for (int i=0;i<n;i++) cin >> x[i] >> y[i];
    for (int i=0;i<n;i++){
        p[i].F=x[i]; p[i].S=y[i];
        pos[i]=i;
    }
    sort(p,p+n);
    int cc=0;
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            b[++cc]=(pi){i,j},V[i][j]=(pi){p[j].F-p[i].F,p[j].S-p[i].S};
    sort(b+1,b+cc+1,cmp);
    for (int i=1;i<=cc;i++){
        int u=b[i].F,v=b[i].S;
        int l,r,mid,S,T;
        l=-1; r=n;
        while (r-l>1){
            int mid=(l+r)>>1;
            if (mut(p[pos[u]],p[pos[v]],p[mid])>0) l=mid; else r=mid;
        }
        S=l+1;
        l=-1; r=n;
        while (r-l>1){
            int mid=(l+r)>>1;
            if (mut(p[pos[u]],p[pos[v]],p[mid])<0) r=mid; else l=mid;
        }
        T=n-r;
        swap(p[pos[u]],p[pos[v]]);
        swap(pos[u],pos[v]);
        sum+=S*T;
    }
    sum-=1ll*n*(n-1)*(n-2)*(n-3)/12;
    cout << sum*(n-4)/2 << endl;
    return 0;
}