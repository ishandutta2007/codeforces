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
int n,m;
double a[1001],b[1001];
bool check(double mid){
    double w=m+mid,fuel=mid;
    rep(i,0,n){
        if(w<=fuel*a[i]){
            double d=w/a[i];
            w-=d;
            fuel-=d;
        }
        else return 0;
        if(fuel<0) return 0;
        if(w<=fuel*b[(i+1)%n]){
            double d=w/b[(i+1)%n];
            w-=d;
            fuel-=d;
        }
        else return 0;
        if(fuel<0) return 0;
    }
    return 1;
}
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        cin>>b[i];
    }
    double lo=0,hi=1e9+7;
    rep(i,0,301){
        double mid=(lo+hi)/2;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    if(lo<1e9+6) cout<<fixed<<setprecision(10)<<lo<<endl;
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