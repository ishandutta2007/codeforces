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
const int N=1000005;
pii seg[4*N];
int lazy[4*N];
void update(int node,int start,int end,int l,int r,int val){
    if(lazy[node]!=0){
        seg[node].x+=lazy[node];
        seg[node].y+=lazy[node];
        if(start!=end){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r){
        seg[node].x+=val;
        seg[node].y+=val;
        if(start!=end){
            lazy[node<<1]+=val;
            lazy[node<<1|1]+=val;
        }
        return;
    }
    int mid=(start+end)>>1;
    update(node<<1,start,mid,l,r,val);
    update(node<<1|1,mid+1,end,l,r,val);
    seg[node].x=max(seg[node<<1].x,seg[node<<1|1].x);
    seg[node].y=min(seg[node<<1].y,seg[node<<1|1].y);
}
pii query(int node,int start,int end,int l,int r){
    if(start>end || start>r || end<l) return {0,0};
    if(lazy[node]!=0){
        seg[node].x+=lazy[node];
        seg[node].y+=lazy[node];
        if(start!=end){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>=l && end<=r) return seg[node];
    int mid=(start+end)>>1;
    pii q1=query(node<<1,start,mid,l,r);
    pii q2=query(node<<1|1,mid+1,end,l,r);
    return {max(q1.x,q2.x),min(q1.y,q2.y)};
}
string s,a;
int n;
void solve(){
    cin>>n>>s;
    rep(i,0,n+2) a+='#';
    int cur=0;
    rep(i,0,n){
        if(s[i]=='L'){
            cur--;
            cur=max(cur,0);
        }
        else if(s[i]=='R') cur++;
        else if(s[i]=='('){
            if(a[cur]=='(');
            else if(a[cur]==')') update(1,0,n,cur,n,2);
            else update(1,0,n,cur,n,1);
            a[cur]=s[i];
        }
        else if(s[i]==')'){
            if(a[cur]==')');
            else if(a[cur]=='(') update(1,0,n,cur,n,-2);
            else update(1,0,n,cur,n,-1);            
            a[cur]=s[i];
        }
        else{
            if(a[cur]==')') update(1,0,n,cur,n,1);
            else if(a[cur]=='(') update(1,0,n,cur,n,-1);
            a[cur]=s[i];
        }
        pii w=query(1,0,n,0,n);
        pii q=query(1,0,n,n,n);
        if(w.y<0 or abs(q.x)+abs(q.y)) cout<<-1<<" ";
        else cout<<w.x<<" ";
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