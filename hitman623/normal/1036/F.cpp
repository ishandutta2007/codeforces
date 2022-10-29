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
bool expo(int base,int exponent,int a){
    int ans=1;
    while(exponent!=0){
        if(exponent&1){
            if(base>a/ans) return 1;
            ans=ans*base;
        }
        exponent>>=1;
        if(exponent and base>a/base) return 1;
        base=base*base;
    }
    return 0;
}
int root(int a,int n,int d){
    int lo=1,hi=d+1;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(expo(mid,n,a)) hi=mid;
        else lo=mid;
    }
    return lo;
}
int f(int n){
    int v[60];
    v[1]=n-1;
    rep(i,2,60){
        if(i==2) v[i]=root(n,i,n)-1;
        else v[i]=root(n,i,v[i-1]+1)-1;
    }
    for(int i=59;i>=1;i--){
        for(int j=2*i;j<=59;j+=i){
            v[i]-=v[j];
        }
    }
    return v[1];
}
void solve(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;
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