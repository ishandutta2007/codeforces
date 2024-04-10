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
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
map<int,int>M[2];
int n,k,a[200005];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	M[0][0]++;
	ll ans = 1LL*n*(n+1)/2;
	int cur = 0;
	for(int i=1;i<=n;i++){
		cur ^= a[i];
		int A = 0, B = 0;
		if(M[0].find(cur) != M[0].end()) A += M[0][cur];
		if(M[1].find(cur) != M[1].end()) B += M[1][cur];
		if(M[0].find((1<<k)-1-cur) != M[0].end()) B += M[0][(1<<k)-1-cur];
		if(M[1].find((1<<k)-1-cur) != M[1].end()) A += M[1][(1<<k)-1-cur];
		if(A <= B){
			ans -= A;
			M[0][cur]++;
		}
		else{
			ans -= B;
			M[1][cur]++;
		}
	}
	cout << ans << endl;
}