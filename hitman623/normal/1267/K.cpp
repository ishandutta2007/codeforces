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
int C[22][22];
void compute(){
    rep(i,0,22){
        rep(j,0,i+1){
            if(j==0 or i==j) C[i][j]=1;
            else C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
}
int get(mi f,int n){
    vii v(all(f));
    int ans=1,cnt=0;
    for(int i=sz(v)-1;i>=0;i--){
        v[i].x=max(v[i].x,1LL);
        ans=ans*C[n-v[i].x-cnt][v[i].y];
        cnt+=v[i].y;
    }    
    return ans;
}
void solve(){
    int m,n=-1;
    mi f;
    cin>>m;
    rep(i,2,22){
        if(m==0) break;
        f[m%i]++;
        m/=i;
        n=i;
    }
    int ans=get(f,n);
    if(f.count(0)){
        f[0]--;
        if(f[0]==0) f.erase(0);
        ans-=get(f,n-1);
    }
    cout<<ans-1<<endl;
}

signed main(){
    compute();
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