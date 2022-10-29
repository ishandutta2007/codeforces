#include <bits/stdc++.h>

#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<int,pii>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int n,a[200005],cur=0;
set<int> s;
void solve(){
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        s.insert(x);
    }
    for(auto i:s){
        a[cur++]=i;
    }
    n=cur;
    int ans=0;
    rep(i,0,n){
        for(int j=2*a[i];j-a[i]<=a[n-1];j+=a[i]){
            int l=lower_bound(a+i,a+n,j)-a-1;
            if(l>=i) ans=max(ans,a[l]%a[i]);
        }
    }
    cout<<ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}