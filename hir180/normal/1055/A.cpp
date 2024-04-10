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
int n,s,a[1005],b[1005];
bool ok[1005];
int main(){
	cin>>n>>s;
	repn(i,n)cin>>a[i];
	repn(i,n)cin>>b[i];
	queue<int>que;
	que.push(1);
	while(!que.empty()){
		int q = que.front(); que.pop();
		if(ok[q]) continue;
		ok[q] = 1;
		for(int x=q+1;x<=n;x++){
			if(a[q] && a[x] && !ok[x]){
				que.push(x);
			}
		}
		for(int x=1;x<q;x++){
			if(b[q] && b[x] && !ok[x]){
				que.push(x);
			}
		}
	}
	puts(ok[s]?"YES":"NO");
}