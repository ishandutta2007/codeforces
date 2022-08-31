#include<bits/stdc++.h>
#define maxn 505
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double db;
const ll M=998244353;
map<ll,ll> f,g;
ll ans,a[maxn],b[maxn],p[maxn],cnt,n,r;
void ins(ll x,ll y){
    if (f.find(x)==f.end()) p[cnt++]=x,f[x]=y;
    else f[x]+=y;
}

int main(){
    cin >> n; ans=1;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++){
        ll x=(ll)sqrt((db)a[i]+0.5);
        while (x*x>a[i]) x--;
        while (x*x<a[i]) x++;
        if (x*x!=a[i]) continue;
        a[i]=-1;
        ll y=(ll)sqrt((db)x+0.5);
        while (y*y>x) y--;
        while (y*y<x) y++;
        if (y*y!=x){
            ins(x,2);
        } else {
            ins(y,4);
        }
    }
    for (int i=0;i<n;i++){
        if (a[i]==-1) continue;
        ll x=(ll)pow((db)a[i],(db)1.0/3);
        while (x*x*x>a[i]) x--;
        while (x*x*x<a[i]) x++;
        if (x*x*x!=a[i]) continue;
        a[i]=-1;
        ins(x,3);
    }
    //for (int i=0;i<cnt;i++)cout<<p[i]<<'!'<<endl;
    for (int i=0;i<n;i++){
        if (a[i]==-1) continue;
        for (int j=0;j<cnt;j++){
            if (a[i]%p[j]==0){
                ins(p[j],1); ins(a[i]/p[j],1);
                a[i]=-1;
                break;
            }
        }
        if (a[i]==-1) continue;
        for (int j=i+1;j<n;j++){
            if (a[j]==-1) continue;
            ll x=__gcd(a[i],a[j]);
            if (x==a[i]||x==1) continue;
            ins(x,1); ins(a[i]/x,1);
            a[i]=-1;
            break;
        }
    }
    for (int i=0;i<n;i++){
        if (a[i]==-1) continue;
        g[a[i]]++;
    }
    for (auto u:f) {
        ans=ans*(u.S+1)%M;
        //cout<<u.F<<' '<<u.S<<endl;
    }
    for (auto u:g) {
        ans=ans*(u.S+1)%M*(u.S+1)%M;
        //cout<<u.F<<' '<<u.S<<endl;
    }
    cout << ans << endl;
}