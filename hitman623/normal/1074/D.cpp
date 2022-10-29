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
#define hell        400000
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int q,last;
int par[30][800005],s[30][800005];
int bit;
int fp(int x){
    if(par[bit][x]!=x) return par[bit][x]=fp(par[bit][x]);
    else return x;
}
void merge(int x,int y){
    if(s[bit][x]<s[bit][y]) par[bit][x]=y,s[bit][y]+=s[bit][x];
    else par[bit][y]=x,s[bit][x]+=s[bit][y];
}
void update(int l,int r,int x){
    int lc=l+hell,rc=r+hell;
    for(bit=0;bit<30;++bit){
        fp(l);
        fp(r);
        fp(rc);
        fp(lc);
        if((x>>bit)&1){
            merge(par[bit][l],par[bit][rc]);
            merge(par[bit][lc],par[bit][r]);
        }
        else{
            merge(par[bit][l],par[bit][r]);
            merge(par[bit][lc],par[bit][rc]);
        }
    }
}
int query(int l,int r){
    int ans=0;
    int lc=l+hell,rc=r+hell;
    for(bit=0;bit<30;++bit){
        fp(l);
        fp(r);
        fp(rc);
        fp(lc);
        if(par[bit][l]==par[bit][rc] or par[bit][lc]==par[bit][r]) ans+=1<<bit;
        else if(par[bit][l]==par[bit][r] or par[bit][lc]==par[bit][rc]);
        else return -1;
    }
    return ans;
}
map<int,int> compressed;
int cntr=1;
void solve(){
    rep(i,0,30){
        rep(j,0,800001){
            par[i][j]=j;
            s[i][j]=1;
        }
    }
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r,x;
            cin>>l>>r>>x;
            l^=last;
            r^=last;
            x^=last;
            if(l>r) swap(l,r);
            l--;
            int g=cntr;
            if(!compressed.count(l)) l=compressed[l]=cntr++;
            else l=compressed[l];
            if(!compressed.count(r)) r=compressed[r]=cntr++;
            else r=compressed[r];
            int d=(g==cntr?query(l,r):-1);
            if(d==-1) update(l,r,x);
        }
        else{
            int l,r;
            cin>>l>>r;
            l^=last;
            r^=last;
            if(l>r) swap(l,r);
            l--;
            if(compressed.count(l) and compressed.count(r)){
                l=compressed[l];
                r=compressed[r];
                last=query(l,r);
            }
            else last=-1;
            cout<<last<<endl;
        }
        if(last==-1) last=1;
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