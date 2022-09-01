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
int n;
int za[300005];
char ch[300005];
int col[300005];
bool used[3];
vector<int>pos[3];
void sol_henn(){
	//GB
	for(int i=1;i<=n;i++){
		pos[col[i]].pb(za[i]);
	}
	ll ans = 0;
	if(pos[1].size()) ans += pos[1][pos[1].size()-1]-pos[1][0];
	if(pos[2].size()) ans += pos[2][pos[2].size()-1]-pos[2][0];
	if(1){cout<<ans<<endl;return;}
}

void sol_hutuu(){
	for(int i=1;i<=n;i++){
		pos[col[i]].pb(za[i]);
	}
	ll add = 0;
	if(pos[1].size() && pos[1][0] < pos[0][0]){
		add += pos[0][0]-pos[1][0];
	}
	if(pos[2].size() && pos[2][0] < pos[0][0]){
		add += pos[0][0]-pos[2][0];
	}
	if(pos[1].size() && pos[1][pos[1].size()-1] > pos[0][pos[0].size()-1]){
		add += pos[1][pos[1].size()-1] - pos[0][pos[0].size()-1];
	}
	if(pos[2].size() && pos[2][pos[2].size()-1] > pos[0][pos[0].size()-1]){
		add += pos[2][pos[2].size()-1] - pos[0][pos[0].size()-1];
	}
	for(int j=1;j<pos[0].size();j++){
		ll addd = 1e18;
		int L = pos[0][j-1],R = pos[0][j];
		int a = POSL(pos[1],L);
		int b = POSL(pos[1],R);
		int c = POSL(pos[2],L);
		int d = POSL(pos[2],R);
		//[a,b) [c,d)
		if(a<b && c<d){
		    addd = 2LL*(R-L);
		}
		ll gen = 0, gen2 = 0;
		for(int x=a;x<=b;x++){
			int pre = (x==a?L:pos[1][x-1]);
			int cur = (x==b?R:pos[1][x]);
			gen = max(gen,1LL*cur-pre);
		}
		for(int x=c;x<=d;x++){
			int pre = (x==c?L:pos[2][x-1]);
			int cur = (x==d?R:pos[2][x]);
			gen2 = max(gen2,1LL*cur-pre);
		}
		addd = min(addd,3LL*(R-L)-gen-gen2);
		add+=addd;
	}
	cout<<add<<endl;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&za[i],&ch[i]);
		if(ch[i]=='G') col[i]=0;
		else if(ch[i] == 'R') col[i]=1;
		else col[i]=2;
	}
	repn(i,n) used[col[i]]=1;
	if(used[0]) sol_hutuu();
	else sol_henn();
}