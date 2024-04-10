#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,x,y;
vector<int>vec;
ll ans[300005][2];
ll rec(int n,int t){
	if(ans[n][t] != -1) return ans[n][t];
	if(n==0) return 0LL;
	else if(n==1){
		if(t==1) return 0LL;
		else return 1LL*y;
	}
	else if(n==2){
		return 1LL*y;
	}
	ans[n][t] = 1e18;
	ans[n][t] = min(rec(n-1,0)+min(x,y),ans[n][t]);
	ans[n][t] = min(rec(n-1,1)+min(x,y),ans[n][t]);
	if(n>=4){
		ans[n][t] = min(rec(n-2,t)+min(x,y),ans[n][t]);
	}
	if(n==3){
	    ans[n][t] = min(rec(n-2,t)+y,ans[n][t]);
	}
	return ans[n][t];
}
int main(){
	cin>>n>>x>>y;
	string s; cin>>s;
	rep(i,n) vec.pb(s[i]-'0');
	ERASE(vec);
	if(vec.size() == 1){
		if(vec[0] == 1){
			puts("0");
		}
		else{
			cout<<y<<endl;
		}
		return 0;
	}
	else if(vec.size() == 2){
		cout<<y<<endl;
		return 0;
	}
	memset(ans,-1ll,sizeof(ans));
	cout<<rec(vec.size(),vec[0])<<endl;
}