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

const double TAU=acos(0)*4;

int n,k;
ii arr[100005];
int tkd[200005][20];

int solve(double rad){
	#define dd pair<double,double>
	#define di pair<double,int>
	vector<dd> ranges;
	
	rep(x,0,n){
		double length=sqrt(arr[x].fi*arr[x].fi+arr[x].se*arr[x].se);
		double angle=atan2(arr[x].fi,arr[x].se);
		double delta=acos(rad/length);
		
		//cout<<arr[x].fi<<" "<<arr[x].se<<endl;
		//cout<<length<<" "<<angle<<" "<<delta<<endl;
		
		double l=angle-delta,r=angle+delta;
		
		//normalize
		while (r<0) l+=TAU,r+=TAU;
		while (r>=TAU) l-=TAU,r-=TAU;
		
		ranges.pub({l,r});
		ranges.pub({l+TAU,r+TAU});
	}
	
	sort(all(ranges),[](dd i,dd j){
		return i.se<j.se;
	});
	
	memset(tkd,-1,sizeof(tkd));
	
	vector<di> stk;
	rep(x,sz(ranges),0){
		while (!stk.empty() && stk.back().fi<=ranges[x].fi) stk.pob();
		
		int lo=-1,hi=sz(stk),mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			
			if (ranges[x].se<stk[mi].fi) lo=mi;
			else hi=mi;
		}
		if (lo!=-1) tkd[x][0]=stk[lo].se;
		
		stk.pub({ranges[x].fi,x});
	}
	
	rep(layer,0,19){
		rep(x,sz(ranges),0) if (tkd[x][layer]!=-1){
			tkd[x][layer+1]=tkd[tkd[x][layer]][layer];
		}
	}
	
	int res=1e9;
	rep(x,0,n){
		int curr=1;
		int pos=x;
		rep(layer,20,0) if (tkd[pos][layer]!=-1 && tkd[pos][layer]<x+n){
			curr+=1<<layer;
			pos=tkd[pos][layer];
		}
		
		res=min(res,curr);
	}
	
	return res;
}

signed main(){
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(false);
	
	cin>>n>>k;
	rep(x,0,n) cin>>arr[x].fi>>arr[x].se;
	
	double lo=0,hi=1e18,mi;
	rep(x,0,n) hi=min(hi,sqrt(arr[x].fi*arr[x].fi+arr[x].se*arr[x].se));
	
	rep(x,0,60){
		mi=(hi+lo)/2;
		
		if (solve(mi)<=k) lo=mi;
		else hi=mi;
	}
	
	cout<<fixed<<setprecision(12)<<lo<<endl;
}