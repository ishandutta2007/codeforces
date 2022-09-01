#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
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
int n,a[200005];
int x=0,y=0;
bool used[400005];
int cur = -1;
vector<int>ans;

void check(vector<int>C){
	assert(C.size() == n);
	int sum = 0,w=0;
	for(int i=0;i<n;i++){
		sum += C[i];
		if(!used[sum]) w++;
	}
	if(cur < w){
		ans = C;
		cur = w;
	}
}

int main(){
	used[1] = 1;
	for(int i=2;i<400005;i++){
		if(used[i]) continue;
		for(int j=2;i*j<400005;j++) used[i*j] = 1;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) x++; else y++;
	}
	if(x >= 3){
		vector<int>vi;
		rep(i,3) vi.pb(1);
		rep(i,y) vi.pb(2);
		rep(i,x-3) vi.pb(1);
		check(vi);
	}
	if(x >= 1){
		vector<int>vi;
		rep(i,1) vi.pb(1);
		rep(i,y) vi.pb(2);
		rep(i,x-1) vi.pb(1);
		check(vi);
	}
	vector<int>vi;
	rep(i,y) vi.pb(2);
	rep(i,x) vi.pb(1);
	check(vi);
	if(x >= 1 && y >= 1){
		vector<int>vi;
		rep(i,1) vi.pb(2);
		rep(i,1) vi.pb(1);
		rep(i,y-1) vi.pb(2);
		rep(i,x-1) vi.pb(1);
		check(vi);
	}
	//cout << cur << endl;
	rep(i,n) printf("%d ",ans[i]);
	puts("");
	return 0;
}