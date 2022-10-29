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
void solve(){
    vi xs,ys;
    int x=0,y=0;
    string s;
    cin>>s;
    xs.pb(0);
    ys.pb(0);
    for(auto i:s){
        if(i=='W') y++;
        if(i=='S') y--;
        if(i=='A') x--;
        if(i=='D') x++;
        xs.pb(x);
        ys.pb(y);
    }
    vi maxsx=xs,minsx=xs,maxpx=xs,minpx=xs,maxsy=ys,minsy=ys,maxpy=ys,minpy=ys;
    rep(i,1,sz(xs)){
        maxpx[i]=max(maxpx[i],maxpx[i-1]);
        minpx[i]=min(minpx[i],minpx[i-1]);
        maxpy[i]=max(maxpy[i],maxpy[i-1]);
        minpy[i]=min(minpy[i],minpy[i-1]);
    }
    for(int i=sz(xs)-2;i>=0;i--){    
        maxsx[i]=max(maxsx[i],maxsx[i+1]);
        minsx[i]=min(minsx[i],minsx[i+1]);
        maxsy[i]=max(maxsy[i],maxsy[i+1]);
        minsy[i]=min(minsy[i],minsy[i+1]);
    }
    int len=maxsx[0]-minsx[0]+1;
    int bred=maxsy[0]-minsy[0]+1;
    int ans=len*bred;
    rep(i,1,sz(xs)+1){
        ans=min(ans,len*(max(maxpy[i-1],maxsy[i-1]+1)-min(minpy[i-1],minsy[i-1]+1)+1));
        ans=min(ans,len*(max(maxpy[i-1],maxsy[i-1]-1)-min(minpy[i-1],minsy[i-1]-1)+1));
        ans=min(ans,bred*(max(maxpx[i-1],maxsx[i-1]+1)-min(minpx[i-1],minsx[i-1]+1)+1));
        ans=min(ans,bred*(max(maxpx[i-1],maxsx[i-1]-1)-min(minpx[i-1],minsx[i-1]-1)+1));
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}