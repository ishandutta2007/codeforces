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
#define N           1000006
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,q,l[N],r[N],a[N],ans[N],pre[N],L[N],R[N];
vi vl[N],vr[N];
vii queries[N];
void preprocess(){
    stack<int> stk;
    rep(i,1,n+1){
        while(!stk.empty() and a[stk.top()]<a[i]) stk.pop();
        if(!stk.empty()) L[i]=stk.top()+1;
        else L[i]=1;
        stk.push(i);
    }
    while(!stk.empty()) stk.pop();
    for(int i=n;i>=1;i--){
        while(!stk.empty() and a[stk.top()]<a[i]) stk.pop();
        if(!stk.empty()) R[i]=stk.top()-1;
        else R[i]=n;
        stk.push(i);
    }
    while(!stk.empty()) stk.pop();
    rep(i,1,n+1) vl[L[i]].pb(i),vr[R[i]].pb(i),pre[i]=pre[i-1]+L[i];
}
pii bit[N][2];
void update(int x,int y,int f){
    for(;x<=n+1;x+=x&(-x)) bit[x][f].x+=y,bit[x][f].y++;
}
pii query(int x,int f){
    pii res={0,0};
    for(;x>0;x-=x&(-x)) res.x+=bit[x][f].x,res.y+=bit[x][f].y;
    return res;
}
void solve(){
    cin>>n>>q;
    rep(i,1,n+1) cin>>a[i];
    preprocess();
    rep(i,0,q) cin>>l[i];
    rep(i,0,q) cin>>r[i];
    rep(i,0,q){
        queries[r[i]].pb({i,0});
        queries[l[i]].pb({i,1});
    }
    rep(i,1,n+1){
        for(auto j:vr[i]) update(j,i,0);
        for(auto j:vl[i]) update(j,i,1);
        for(auto j:queries[i]){
            if(j.y==0){
                int id=j.x;
                pii d1=query(r[id],0);
                pii d2=query(l[id]-1,0);
                pii d={d1.x-d2.x,d1.y-d2.y};
                ans[id]+=d.x+(r[id]-l[id]+1-d.y)*r[id];
            }
            else{
                int id=j.x;
                pii d1=query(r[id],1);
                pii d2=query(l[id]-1,1);
                pii d={d1.x-d2.x,d1.y-d2.y};
                ans[id]-=pre[r[id]]-pre[l[id]-1]-d.x+d.y*l[id];                
            }
        }
    }
    rep(i,0,q) cout<<ans[i]+r[i]-l[i]+1<<" ";
    cout<<endl;
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