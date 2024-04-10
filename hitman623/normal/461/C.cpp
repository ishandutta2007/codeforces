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
int n,q,flipped,a[100005];
int bit[100005];
void update(int x,int y){
    for(;x<=n;x+=x&(-x)) bit[x]+=y;
}
int query(int x){
    int res=0;
    for(;x>0;x-=x&(-x)) res+=bit[x];
        return res;
}
void solve(){
    cin>>n>>q;
    int L=1,R=n;
    rep(i,1,n+1) update(i,1);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int p;
            cin>>p;
            if(!flipped){
                if(2*p<=R-L+1){
                    rep(i,L+p,L+2*p){
                        int d=query(2*(L+p)-i-1)-query(2*(L+p)-i-2);
                        update(i,d);
                        update(2*(L+p)-i-1,-d);
                    }
                    L=L+p;
                }
                else{
                    rep(i,L+p,R+1){
                        int d=query(i)-query(i-1);
                        update(i,-d);
                        update(2*(L+p)-i-1,d);
                    }         
                    R=L+p-1;           
                    flipped^=1;
                }
            }
            else{
                p=R-L+1-p;
                if(2*p<=R-L+1){
                    rep(i,L+p,L+2*p){
                        int d=query(2*(L+p)-i-1)-query(2*(L+p)-i-2);
                        update(i,d);
                        update(2*(L+p)-i-1,-d);
                    }
                    L=L+p;
                    flipped^=1;
                }
                else{
                    rep(i,L+p,R+1){
                        int d=query(i)-query(i-1);
                        update(i,-d);
                        update(2*(L+p)-i-1,d);
                    }         
                    R=L+p-1;
                }                
            }
        }
        else{
            int l,r;
            cin>>l>>r;
            l++;
            if(flipped){
                l=R-L+1-l+1,r=R-L+1-r+1;
                swap(l,r);
            } 
            cout<<query(L+r-1)-query(L+l-2)<<endl;
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