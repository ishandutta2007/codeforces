#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<ll,ll,ll> tll;
typedef vector<vector<ll>> mat;
const ll mod=998244353;
const int N=1e6+5;
int n;
ll a[N],b[N],sm,ans=1e18;
void Do(ll c)
{
    if(c==1) return;
    for(int i=1;i<=n;i++) a[i]=b[i];
    ll res=0,cursz=0,m=(c+1)/2,sl=0,sr=0,mp=0;
    for(int i=1;i<=n;i++){
        if(!a[i]) continue;
        if(cursz+a[i]<c){
            if(cursz+a[i]<m){
                sl+=a[i]*(ll)i;
                cursz+=a[i];
                continue;
            }
            if(cursz<m){
                ll d=m-cursz;
                sl+=(ll)i*d;
                mp=i;
                a[i]-=d;
                cursz+=d;
                i--;
                continue;
            }
            sr+=(ll)i*a[i];
            cursz+=a[i];
            continue;
        }
        if(cursz){
            if(cursz<m){
                ll d=m-cursz;
                sl+=(ll)i*d;
                mp=i;
                a[i]-=d;
                i--;
                cursz+=d;
                continue;
            }
            ll d=c-cursz;
            sr+=(ll)i*d;
            res+=sr-sl; if(c&1) res+=mp;
            a[i]-=d;
            sl=0; sr=0; cursz=0; mp=0; i--; continue;
        }
        ll cnt=a[i]/c;
        a[i]-=c*cnt;
        sl=0; sr=0; cursz=0; mp=0;
        i--;
        continue;
    }
    ans=min(ans,res);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        sm+=a[i];
    }
    if(sm==1){
        cout<<-1;
        return 0;
    }
    ll sm2=sm;
    for(ll t=2;sm2!=1&&t*t<=sm;t++){
        if(sm2%t==0){
            while(sm2%t==0) sm2/=t;
            Do(t);
        }
    }
    Do(sm2);
    cout<<ans;
    return 0;
}