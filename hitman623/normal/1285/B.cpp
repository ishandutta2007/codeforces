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
#define hell        1000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,s;
int a[100005];
void solve(){
	s=0;
	cin>>n;
	rep(i,1,n+1){
		cin>>a[i];
		s+=a[i];
		a[i]+=a[i-1];
	}
	int mn=0;
	rep(i,1,n){
		if(a[i]-mn>=s){
			cout<<"NO"<<endl;
			return;
		}
		mn=min(mn,a[i]);
	}
	mn=a[1];
	rep(i,2,n+1){
		if(a[i]-mn>=s){
			cout<<"NO"<<endl;
			return;
		}
		mn=min(mn,a[i]);
	}
	cout<<"YES"<<endl;
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