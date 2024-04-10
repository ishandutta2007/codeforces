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
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int ans[155][155],n;;
int main(){
	ans[0][0] = 1;
	ans[1][1] = 1;
	for(int i=2;i<=150;i++){
		bool bad = 0;
		for(int j=0;j<=150;j++){
			ans[i][j] = 0;
			ans[i][j] += ans[i-2][j];
			if(j) ans[i][j] += ans[i-1][j-1];
			if(abs(ans[i][j]) >= 2) bad = 1;
		}
		if(!bad) continue;
		bad = 0;
		for(int j=0;j<=150;j++){
			ans[i][j] = 0;
			ans[i][j] += ans[i-2][j];
			if(j) ans[i][j] -= ans[i-1][j-1];
			if(abs(ans[i][j]) >= 2) bad = 1;
		}
		assert(!bad);
	}
	for(int i=2;i<=150;i++){
	    if(ans[i][i] >= 0) continue;
	    for(int j=0;j<=150;j++){
	        ans[i][j] *= -1;
	    }
	}
	cin>>n;
	cout<<n<<endl;
	for(int i=0;i<=n;i++) cout<<ans[n][i]<<" ";
	cout<<endl;
	cout<<n-1<<endl;
	for(int i=0;i<=n-1;i++) cout<<ans[n-1][i]<<" ";
	cout<<endl;
}