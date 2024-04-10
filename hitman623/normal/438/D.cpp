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
const int N=100005;
int n,a[N],q;
pii t[2*N];
void build(){
    for(int i=n-1;i>0;--i){
        if(a[t[i<<1].x]>a[t[i<<1|1].x]) t[i].x=t[i<<1].x;
        else t[i].x=t[i<<1|1].x;
        t[i].y=t[i<<1].y+t[i<<1|1].y;
    }
}
void modify(int p,int val){
    a[p]=val;
    p+=n;
    t[p].x=p-n;
    t[p].y=val;
    for(;p>1;p>>=1){
        if(a[t[p].x]>a[t[p^1].x]) t[p>>1].x=t[p].x;
        else t[p>>1].x=t[p^1].x;
        t[p>>1].y=t[p].y+t[p^1].y;
    }
}
pii query(int l,int r){
    pii res={l,0};
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1){
            if(a[res.x]<a[t[l].x]) res.x=t[l].x;
            res.y+=t[l].y;         
            l++;
        }
        if(r&1){
            --r;
            res.y+=t[r].y;
            if(a[res.x]<a[t[r].x]) res.x=t[r].x;
        }
    }
    return res;
}
void solve(){
    cin>>n>>q;
    rep(i,0,n){
        cin>>a[i];
        t[i+n].x=i;
        t[i+n].y=a[i];
    }
    build();
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<query(l-1,r-1).y<<endl;
        }
        else if(type==2){
            int l,r,x;
            cin>>l>>r>>x;
            l--,r--;
            while(1){
                pii d=query(l,r);
                if(a[d.x]<x) break;
                modify(d.x,a[d.x]%x);
            }
        }
        else{
            int k,x;
            cin>>k>>x;
            modify(k-1,x);
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