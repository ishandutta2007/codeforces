#include <bits/stdc++.h>
#define	int			long long
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;

void solve()
{
	int n,num=0,s=0;
	cin>>n;
	vi a(n);
	rep(i,0,n){
		cin>>a[i];
		s+=a[i];
	}
	sort(all(a));
	num+=s;
	s-=n*a[0];
	num+=s;
	rep(i,0,n-1){
		s=s+(i+1)*(a[i+1]-a[i])-(n-i-1)*(a[i+1]-a[i]);
		num+=s;
	}
	int g=__gcd(num,n);
	cout<<num/g<<" "<<n/g;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}