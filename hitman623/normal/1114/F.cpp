#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
bool p[303];
vi primes;
void process_seive(int n){
    memset(p,1,sizeof p);
    rep(i,2,n+1){
        if(p[i]==0) continue;
        primes.pb(i);
        for(int j=2*i;j<=n;j+=i){
            p[j]=0;
        }
    }
}
int n,q,inv[66];
int a[400005];
ll seg[1600002],lazy[1600002];
void update(int node,int start,int end,int l,int r,ll val){
    if(lazy[node]){
        seg[node]|=lazy[node];
        if(start!=end){
            lazy[node<<1]|=lazy[node];
            lazy[node<<1|1]|=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r){
        seg[node]|=val;
        if(start!=end){
            lazy[node<<1]|=val;
            lazy[node<<1|1]|=val;
        }
        return;
    }
    int mid=(start+end)>>1;
    update(node<<1,start,mid,l,r,val);
    update(node<<1|1,mid+1,end,l,r,val);
    seg[node]=seg[node<<1]|seg[node<<1|1];
}
ll query(int node,int start,int end,int l,int r){
    if(start>end || start>r || end<l) return 0;
    if(lazy[node]){
        seg[node]|=lazy[node];
        if(start!=end){
            lazy[node<<1]|=lazy[node];
            lazy[node<<1|1]|=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>=l && end<=r) return seg[node];
    int mid=(start+end)>>1;
    return query(node<<1,start,mid,l,r)|query(node<<1|1,mid+1,end,l,r);
}
int seg2[1600002],lazy2[1600005];
void build2(int node,int start,int end){
    if(start==end){
        seg2[node]=a[start];
        return;
    }
    int mid=(start+end)>>1;
    build2(node<<1,start,mid);
    build2(node<<1|1,mid+1,end);
    seg2[node]=1LL*seg2[node<<1]*seg2[node<<1|1]%hell;
}
void update2(int node,int start,int end,int l,int r,int val){
    if(lazy2[node]!=1){
        seg2[node]=1LL*seg2[node]*expo(lazy2[node],(end-start+1),hell)%hell;
        if(start!=end){
            lazy2[node<<1]=1LL*lazy2[node<<1]*lazy2[node]%hell;
            lazy2[node<<1|1]=1LL*lazy2[node<<1|1]*lazy2[node]%hell;
        }
        lazy2[node]=1;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r){
        seg2[node]=1LL*seg2[node]*expo(val,end-start+1,hell)%hell;
        if(start!=end){
            lazy2[node<<1]=1LL*lazy2[node<<1]*val%hell;
            lazy2[node<<1|1]=1LL*lazy2[node<<1|1]*val%hell;
        }
        return;
    }
    int mid=(start+end)>>1;
    update2(node<<1,start,mid,l,r,val);
    update2(node<<1|1,mid+1,end,l,r,val);
    seg2[node]=1LL*seg2[node<<1]*seg2[node<<1|1]%hell;
}
int query2(int node,int start,int end,int l,int r){
    if(start>end || start>r || end<l) return 1;
    if(lazy2[node]!=1){
        seg2[node]=1LL*seg2[node]*expo(lazy2[node],(end-start+1),hell)%hell;
        if(start!=end){
            lazy2[node<<1]=1LL*lazy2[node<<1]*lazy2[node]%hell;
            lazy2[node<<1|1]=1LL*lazy2[node<<1|1]*lazy2[node]%hell;
        }
        lazy2[node]=1;
    }
    if(start>=l && end<=r) return seg2[node];
    int mid=(start+end)>>1;
    int q1=query2(node<<1,start,mid,l,r);
    int q2=query2(node<<1|1,mid+1,end,l,r);
    return 1LL*q1*q2%hell;
}
void solve(){
    cin>>n>>q;
    rep(i,0,4*n+1) lazy2[i]=1;
    rep(i,1,n+1){
        int x;
        cin>>x;
        a[i]=x;
        ll val=0;
        rep(j,0,sz(primes)){
            if(x%primes[j]==0) val|=1LL<<j;
        }
        update(1,1,n,i,i,val);
    }
    build2(1,1,n);
    while(q--){
        string s;
        cin>>s;
        if(s=="MULTIPLY"){
            int l,r,x;
            cin>>l>>r>>x;
            update2(1,1,n,l,r,x);
            ll val=0;
            rep(j,0,sz(primes)){
                if(x%primes[j]==0) val|=1LL<<j;
            }
            update(1,1,n,l,r,val);
        }
        else{
            int l,r;
            cin>>l>>r;
            int ans=query2(1,1,n,l,r);
            ll val=query(1,1,n,l,r);
            rep(j,0,sz(primes)){
                if((val>>j)&1LL){
                    ans=1LL*ans*inv[j]%hell*(primes[j]-1)%hell;
                }
            }
            cout<<ans<<endl;
        }
    }
}

signed main(){
    process_seive(300);
    rep(i,0,sz(primes)) inv[i]=expo(primes[i],hell-2,hell);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}