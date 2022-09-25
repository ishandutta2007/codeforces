#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define fi first
#define se second
#define endl '\n'

#define puf push_front
#define pof pop_front
#define pub push_back
#define pob pop_back
#define lb lower_bound
#define ub upper_bound

#define rep(x,s,e) for (int x=(s)-((s)>(e));x!=(e)-((s)>(e));((s)<(e))?x++:x--)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[500005];
int pref[500005];

int cnt;

bool check(int h,int w){
	//2 * h boards
	//h * w boards
	
	if (2*h>arr[n] && h>arr[n-1]) return false;
	
	int reduce=h/w+1;
	
	if (h<=cnt-2*reduce) return true;
	if (cnt-2*reduce+2<h) return false;
	
	int num=0;
	int mx=0;
	int hr=h%w;
	
	{
		int l=hr,r=w-1;
		while (l<500005){
			if (h<=r) num+=pref[min(r,500004LL)]-pref[max(l,h)-1];
			l+=w,r+=w;
		}
	}
	
	if (2*h<=arr[n]){
		mx=1-(2*hr)/w;
		
		int l=(2*hr)%w,r=w-1;
		while (l<500005){
			if (2*h<=r && pref[min(r,500004LL)]-pref[max(l,2*h)-1]) mx=2-(2*hr)/w;
			l+=w,r+=w;
		}
	}
	
	return cnt-2*reduce+min(2LL,max(num,mx))>=h;
}

signed main(){
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(false);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	sort(arr+1,arr+n+1);
	rep(x,1,n+1) pref[arr[x]]++;
	rep(x,1,500005) pref[x]+=pref[x-1];
	
	int mx=arr[n];
	
	int ans=0;
	rep(x,2,mx+1){
		cnt=0;
		
		int curr=0;
		int l=0,r=x-1;
		while (l<500005){
			cnt+=(pref[min(r,500004LL)]-pref[max(l,1LL)-1])*curr;
			l+=x,r+=x;
			curr++;
		}
		
		int lo=1,hi=mx+1,mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			
			if (check(mi,x)) lo=mi;
			else hi=mi;
		}
		
		if (lo>=2) ans=max(ans,lo*x);
	}
	
	cout<<ans<<endl;
}