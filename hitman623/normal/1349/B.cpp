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
int n,k,a[100005];
void solve(){
    cin>>n>>k;
    int f=0,g=0;
    rep(i,1,n+1){
    	cin>>a[i];
    	if(a[i]==k) g=1;
    	if(a[i]>=k) a[i]=1;
    	else a[i]=-1;
    	a[i]+=a[i-1];
    }
    if(n==1){
    	if(g==1) cout<<"yes"<<endl;
    	else cout<<"no"<<endl;
    	return;
    }
    int mn=hell;
    rep(i,1,n+1){
    	if(a[i]-mn>=1) f=1;
    	mn=min(mn,a[i-1]);
    }
    if(f and g) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
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