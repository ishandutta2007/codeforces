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
#define hell        998244353
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
const int N=200005;
int seg[N<<2];
int query(int node,int start,int end,int l,int r){
    if(l<=start && r>=end) return seg[node];
    if(r<start || l>end) return 0;
    int mid=(start+end)>>1;
    int ans1=query(node<<1,start,mid,l,r);
    int ans2=query(node<<1|1,mid+1,end,l,r);
    return (ans1+ans2)%hell;
}
void update(int node,int start,int end,int x,int val){
    if(start==end){
        seg[node]=val;
        return;
    }
    int mid=(start+end)>>1;
    if(start<=x && x<=mid) update(node<<1,start,mid,x,val);
    else update(node<<1|1,mid+1,end,x,val);
    seg[node]=(seg[node<<1]+seg[node<<1|1])%hell;
}
int n,q,inv100=expo(100,hell-2,hell),pre[200005],f1[200005],f2[200005],pref1[200005],pref2[200005],p[200005];
int get(int l,int r){
    int d=expo(pre[l-1],hell-2,hell);
    int C=pre[r-1]*d%hell*(r-l)%hell;
    C=(C+((pref2[r-1]-pref2[l-1]+hell)%hell-((pref1[r-1]-pref1[l-1]+hell)%hell)*(l-1)%hell+hell+hell)%hell*d%hell)%hell;
    int e=(1-((pref1[r-1]-pref1[l-1]+hell)%hell)*d%hell+hell)%hell;
    return C*expo(e,hell-2,hell)%hell;
}
void solve(){
    cin>>n>>q;
    rep(i,1,n+1){
        cin>>p[i];
        p[i]=p[i]*inv100%hell;
    }
    pre[0]=1;
    rep(i,1,n+1){
        pre[i]=pre[i-1]*p[i]%hell;
        f1[i]=pre[i-1]*(1-p[i]+hell)%hell;
        f2[i]=f1[i]*i%hell;
        pref1[i]=(pref1[i-1]+f1[i])%hell;
        pref2[i]=(pref2[i-1]+f2[i])%hell;
    }
    update(1,1,n,1,get(1,n+1));
    set<int> st;
    st.insert(1);
    st.insert(n+1);
    while(q--){
        int x;
        cin>>x;
        if(st.count(x)){
            auto it=st.find(x);
            int l=*(--it);
            it++;
            it++;
            int r=*it;
            update(1,1,n,l,get(l,r));
            update(1,1,n,x,0);
            st.erase(x);
        }
        else{
            st.insert(x);
            auto it=st.find(x);
            int l=*(--it);
            it++;
            it++;
            int r=*it;
            update(1,1,n,l,get(l,x));
            update(1,1,n,x,get(x,r));
        }
        cout<<query(1,1,n,1,n)<<endl;
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