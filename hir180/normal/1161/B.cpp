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
int n,m,a[200005],b[200005];
vector<int>edge[100005];
bool check(int x){
	bool fail = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<edge[i].size();j++){
			int a = (i+x)%n;
			int b = (edge[i][j]+x)%n;
			if(a > b) swap(a,b);
			int x = POSL(edge[a],b);
			if(x != edge[a].size() && edge[a][x] == b);
			else{
				fail = 1;
				goto F;
			}
		}
	}
	F:;
	if(!fail) return 1;
	
	fail = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<edge[i].size();j++){
			int a = (i+n-x)%n;
			int b = (edge[i][j]+n-x)%n;
			if(a > b) swap(a,b);
			int x = POSL(edge[a],b);
			if(x != edge[a].size() && edge[a][x] == b);
			else{
				fail = 1;
				goto G;
			}
		}
	}
	G:;
	if(!fail) return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a[i],&b[i]);
		a[i]--; b[i]--;
		if(a[i] > b[i]) swap(a[i],b[i]);
		edge[a[i]].pb(b[i]);
	}
	for(int i=0;i<n;i++){
		SORT(edge[i]);
		int sz = edge[i].size();
		ERASE(edge[i]);
		assert(edge[i].size() == sz);
	}
	for(int i=1;i*i<=n;i++){
		if(n%i == 0){
			if(check(i)){
				cout<<"Yes"<<endl;
				return 0;
			}
			if(i*i!=n && i!=1){
				if(check(n/i)){
					cout<<"Yes"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"No"<<endl;
}