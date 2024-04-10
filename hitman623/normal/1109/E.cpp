#include <bits/stdc++.h>

#define int         long long
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
const int N=100005;
int n,mod,q;
vi primes;
int a[N];
int seg1[4*N],lazy1[4*N];
int seg2[4*N][10],lazy2[4*N][10];
int seg3[4*N],lazy3[4*N];
void build(int node,int start,int end){
    lazy1[node]=lazy3[node]=1;
    if(start==end){
        seg1[node]=a[start]%mod;
        rep(i,0,sz(primes)){
            while(a[start]%primes[i]==0) a[start]/=primes[i],seg2[node][i]++;
        }
        seg3[node]=a[start]%mod;
        return;
    }
    int mid=(start+end)>>1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    seg1[node]=(seg1[node<<1]+seg1[node<<1|1])%mod;
    rep(i,0,sz(primes)) seg2[node][i]=seg2[node<<1][i]+seg2[node<<1|1][i];
    seg3[node]=(seg3[node<<1]+seg3[node<<1|1])%mod;
}
void update11(int node,int start,int end,int l,int r,int val){
    if(lazy1[node]!=1){
        seg1[node]=seg1[node]*lazy1[node]%mod;
        if(start!=end){
            lazy1[node<<1]=lazy1[node<<1]*lazy1[node]%mod;
            lazy1[node<<1|1]=lazy1[node<<1|1]*lazy1[node]%mod;
        }
        lazy1[node]=1;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r){
        seg1[node]=seg1[node]*val%mod;
        if(start!=end){
            lazy1[node<<1]=lazy1[node<<1]*val%mod;
            lazy1[node<<1|1]=lazy1[node<<1|1]*val%mod;
        }
        return;
    }
    int mid=(start+end)>>1;
    update11(node<<1,start,mid,l,r,val);
    update11(node<<1|1,mid+1,end,l,r,val);
    seg1[node]=(seg1[node<<1]+seg1[node<<1|1])%mod;
}
void update12(int node,int start,int end,int p,int val){
    if(start==end){
        seg1[node]=val%mod;
        lazy1[node]=1;
        return;
    }
    if(lazy1[node]!=1){
        seg1[node]=seg1[node]*lazy1[node]%mod;
        if(start!=end){
            lazy1[node<<1]=lazy1[node<<1]*lazy1[node]%mod;
            lazy1[node<<1|1]=lazy1[node<<1|1]*lazy1[node]%mod;
        }
        lazy1[node]=1;
    }
    int mid=(start+end)>>1;
    if(p<=mid){
        update12(node<<1,start,mid,p,val);
        seg1[node]=(seg1[node<<1]+lazy1[node<<1|1]*seg1[node<<1|1])%mod;
    }
    else{ 
        update12(node<<1|1,mid+1,end,p,val);
        seg1[node]=(lazy1[node<<1]*seg1[node<<1]+seg1[node<<1|1])%mod;
    }
}
int query1(int node,int start,int end,int l,int r){
    if(start>end || start>r || end<l) return 0;
    if(lazy1[node]!=1){
        seg1[node]=seg1[node]*lazy1[node]%mod;
        if(start!=end){
            lazy1[node<<1]=lazy1[node<<1]*lazy1[node]%mod;
            lazy1[node<<1|1]=lazy1[node<<1|1]*lazy1[node]%mod;
        }
        lazy1[node]=1;
    }
    if(start>=l && end<=r) return seg1[node]%mod;
    int mid=(start+end)>>1;
    int q1=query1(node<<1,start,mid,l,r);
    int q2=query1(node<<1|1,mid+1,end,l,r);
    return (q1+q2)%mod;
}
void update2(int node,int start,int end,int l,int r,int val,int f){
    if(lazy2[node][f]!=0){
        seg2[node][f]+=(end-start+1)*lazy2[node][f];
        if(start!=end){
            lazy2[node<<1][f]+=lazy2[node][f];
            lazy2[node<<1|1][f]+=lazy2[node][f];
        }
        lazy2[node][f]=0;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r){
        seg2[node][f]+=(end-start+1)*val;
        if(start!=end){
            lazy2[node<<1][f]+=val;
            lazy2[node<<1|1][f]+=val;
        }
        return;
    }
    int mid=(start+end)>>1;
    update2(node<<1,start,mid,l,r,val,f);
    update2(node<<1|1,mid+1,end,l,r,val,f);
    seg2[node][f]=seg2[node<<1][f]+seg2[node<<1|1][f];
}
int query2(int node,int start,int end,int l,int r,int f){
    if(start>end || start>r || end<l) return 0;
    if(lazy2[node][f]!=0){
        seg2[node][f]+=(end-start+1)*lazy2[node][f];
        if(start!=end){
            lazy2[node<<1][f]+=lazy2[node][f];
            lazy2[node<<1|1][f]+=lazy2[node][f];
        }
        lazy2[node][f]=0;
    }
    if(start>=l && end<=r) return seg2[node][f];
    int mid=(start+end)>>1;
    int q1=query2(node<<1,start,mid,l,r,f);
    int q2=query2(node<<1|1,mid+1,end,l,r,f);
    return q1+q2;
}
void update3(int node,int start,int end,int l,int r,int val){
    if(lazy3[node]!=1){
        seg3[node]=seg3[node]*lazy3[node]%mod;
        if(start!=end){
            lazy3[node<<1]=lazy3[node<<1]*lazy3[node]%mod;
            lazy3[node<<1|1]=lazy3[node<<1|1]*lazy3[node]%mod;
        }
        lazy3[node]=1;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r){
        seg3[node]=seg3[node]*val%mod;
        if(start!=end){
            lazy3[node<<1]=lazy3[node<<1]*val%mod;
            lazy3[node<<1|1]=lazy3[node<<1|1]*val%mod;
        }
        return;
    }
    int mid=(start+end)>>1;
    update3(node<<1,start,mid,l,r,val);
    update3(node<<1|1,mid+1,end,l,r,val);
    seg3[node]=(seg3[node<<1]+seg3[node<<1|1])%mod;
}
int query3(int node,int start,int end,int l,int r){
    if(start>end || start>r || end<l) return 0;
    if(lazy3[node]!=1){
        seg3[node]=seg3[node]*lazy3[node]%mod;
        if(start!=end){
            lazy3[node<<1]=lazy3[node<<1]*lazy3[node]%mod;
            lazy3[node<<1|1]=lazy3[node<<1|1]*lazy3[node]%mod;
        }
        lazy3[node]=1;
    }
    if(start>=l && end<=r) return seg3[node]%mod;
    int mid=(start+end)>>1;
    int q1=query3(node<<1,start,mid,l,r);
    int q2=query3(node<<1|1,mid+1,end,l,r);
    return (q1+q2)%mod;
}
void solve(){
    cin>>n>>mod;
    int cur=mod,phi=mod;
    for(int i=2;i*i<=cur;++i){
        if(cur%i==0){
            primes.pb(i);
            while(cur%i==0) cur/=i;
            phi=phi/i*(i-1);
        }
    }
    if(cur>1) primes.pb(cur),phi=phi/cur*(cur-1);
    rep(i,1,n+1) cin>>a[i];
    build(1,1,n);
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r,x;
            cin>>l>>r>>x;
            update11(1,1,n,l,r,x);
            rep(i,0,sz(primes)){
                int cnt=0;
                while(x%primes[i]==0) cnt++,x/=primes[i];
                if(cnt) update2(1,1,n,l,r,cnt,i);
            }
            update3(1,1,n,l,r,x);
        }
        else if(type==2){
            int p,x,val=1;
            cin>>p>>x;
            rep(i,0,sz(primes)){
                int cnt=0;
                while(x%primes[i]==0) cnt++,x/=primes[i];
                if(cnt) update2(1,1,n,p,p,-cnt,i);                
                val=val*expo(primes[i],query2(1,1,n,p,p,i),mod)%mod;
            }
            x=expo(x,phi-1,mod);
            update3(1,1,n,p,p,x);
            update12(1,1,n,p,query3(1,1,n,p,p)*val%mod);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<query1(1,1,n,l,r)%mod<<endl;
        }
    }
}

signed main(){
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