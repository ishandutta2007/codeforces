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
int n,x,y,lft[200005],rgt[200005],up[200005],down[200005];
string s;
int get(int* a,int l,int r){
    if(l>r) return 0;
    return a[r]-(l?a[l-1]:0);
}
bool check(int mid){
    rep(i,0,n-mid+1){
        int l=i,r=i+mid-1;
        int dx=get(rgt,0,l-1)-get(lft,0,l-1)+get(rgt,r+1,n-1)-get(lft,r+1,n-1);
        int dy=get(up,0,l-1)-get(down,0,l-1)+get(up,r+1,n-1)-get(down,r+1,n-1);
        if(abs(x-dx)+abs(y-dy)<=mid and (abs(x-dx)+abs(y-dy))%2==mid%2) return 1;
    }
    return 0;
}
void solve(){
    cin>>n>>s;
    cin>>x>>y;
    if(abs(x)+abs(y)>n){
        cout<<-1<<endl;
        return;
    }
    rep(i,0,n){
        rgt[i]=s[i]=='R';
        lft[i]=s[i]=='L';
        up[i]=s[i]=='U';
        down[i]=s[i]=='D';
        if(i){
            rgt[i]+=rgt[i-1];
            lft[i]+=lft[i-1];
            up[i]+=up[i-1];
            down[i]+=down[i-1];
        }
    }
    int lo=-1,hi=n;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    if(check(hi)) cout<<hi<<endl;
    else cout<<-1<<endl;
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