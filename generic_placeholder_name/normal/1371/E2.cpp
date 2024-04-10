//	ZapZu's code hohoho
//  #pragma GCC optimize ("O3")

//borrowing sb else's code to test whether 64bit makes a big difference
//I predict that it does
//orginial runtime: 234ms
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define dfs_black 1
#define dfs_white -1
#define pr pair
#define vt vector
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
typedef double db;
typedef long long li;
typedef long double ld;
 
typedef pr<int, int> ii;
typedef pr<ld,ld> dd;
 
typedef vt<int> vi;
typedef vt<li> vli;
typedef vt<ld> vld;
typedef vt<ii> vii;
 
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, char> mic;
 
typedef set<int> s_i;
typedef set<char> s_c;
 
const int MOD = 1e9+7;
const li INF = 1e18;
const ld PI = 4*atan((ld)1);
int n, p;
int a[200005], cnt[200005], rem[200005];
bool ch[200005];
signed main()
{
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);
	cin>>n>>p;
	for(int i=1; i<=n; i++) cin>>a[i]; 
	sort(a+1, a+n+1);
	int mn=0, mx=a[p];
	for(int i=1; i<=n; i++) mn=max(mn, a[i]-i+1);
	for(int i=n; i>=1; i--)
	{
		int temp = p-(i+1-max(a[i]-mn+1, 1))%p; while(temp<0) temp+=p; while(temp>=p) temp-=p;
		rem[i]=temp;
		cnt[temp]++;
	}
	s_i  s; 
	int pnt=1;
	for(int i=mn; i<mx; i++)
	{
		while(pnt<p and a[pnt]-i+1<=1) 
		{
			pnt++;
			cnt[rem[pnt]]--;
		}
		if(!cnt[i-mn]) s.insert(i);
	}
	cout<<s.size()<<endl;
	for(auto temp: s) cout<<temp<<" ";
}