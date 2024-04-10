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
#define hell        1000000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
const int N=1000005;
int n,value[N];
vector<pair<pii,int>> v;
mi mp;
vii vv[N];
int seg[4*N],lazy[4*N];
void build(int node,int start,int end){
    if(start==end){
        seg[node]=-value[start];
        return;
    }
    int mid=(start+end)>>1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    seg[node]=max(seg[node<<1],seg[node<<1|1]);
}
void update(int node,int start,int end,int l,int r,int val){
    if(lazy[node]!=0){
        seg[node]+=lazy[node];
        if(start!=end){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r){
        seg[node]+=val;
        if(start!=end){
            lazy[node<<1]+=val;
            lazy[node<<1|1]+=val;
        }
        return;
    }
    int mid=(start+end)>>1;
    update(node<<1,start,mid,l,r,val);
    update(node<<1|1,mid+1,end,l,r,val);
    seg[node]=max(seg[node<<1],seg[node<<1|1]);
}
int query(int node,int start,int end,int l,int r){
    if(start>end || start>r || end<l) return -hell;
    if(lazy[node]!=0){
        seg[node]+=lazy[node];
        if(start!=end){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>=l && end<=r) return seg[node];
    int mid=(start+end)>>1;
    int q1=query(node<<1,start,mid,l,r);
    int q2=query(node<<1|1,mid+1,end,l,r);
    return max(q1,q2);
}
void solve(){
    cin>>n;
    rep(i,0,n){
        int x,y,c;
        cin>>x>>y>>c;
        int l=min(x,y);
        int r=max(x,y);
        v.pb({{l,r},c});
        mp[l]=1;
        mp[r]=1;
    }
    int cnt=0;
    for(auto &i:mp){
        i.y=++cnt;
        value[cnt]=i.x;
    }
    build(1,1,cnt);
    vi w;
    for(auto &i:v){
        i.x.x=mp[i.x.x];
        i.x.y=mp[i.x.y];
        vv[i.x.x].pb({i.x.y,i.y});
        update(1,1,cnt,i.x.y,cnt,i.y);
        w.pb(i.x.x);
    }
    sort(all(w));
    w.resize(unique(all(w))-w.begin());
    int ans=-hell;
    for(auto i:w){
        ans=max(ans,query(1,1,cnt,i,cnt)+value[i]);
        for(auto j:vv[i]){
            update(1,1,cnt,j.x,cnt,-j.y);
        }
    }
    if(ans<0){
        cout<<0<<endl;
        int www=1000000007;
        cout<<www<<" "<<www<<" "<<www<<" "<<www<<endl;
        return;
    }
    build(1,1,cnt);
    memset(lazy,0,sizeof lazy);
    for(auto &i:v){
        update(1,1,cnt,i.x.y,cnt,i.y);
    }
    for(auto i:w){
        int d=query(1,1,cnt,i,cnt)+value[i];
        if(ans==d){
            rep(j,i,cnt+1){
                if(query(1,1,cnt,j,j)+value[i]==ans){
                    cout<<ans<<endl;
                    cout<<value[i]<<" "<<value[i]<<" "<<value[j]<<" "<<value[j]<<endl;
                    return;
                }
            }
        }
        for(auto j:vv[i]){
            update(1,1,cnt,j.x,cnt,-j.y);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}