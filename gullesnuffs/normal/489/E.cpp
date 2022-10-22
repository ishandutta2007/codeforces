#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int x[1005],b[1005];
double dp[1005];
int parent[1005];

int main(){
	int n, l;
	cin >> n >> l;
	rep(i,1,n+1){
		cin >> x[i] >> b[i];
	}
	double lo=0, hi=1000000000;
	for(int i=0; i < 60; ++i){
		double mid=(lo+hi)/2;
		rep(j,0,n+1)
			dp[j]=-1000000000;
		dp[0]=0;
		rep(j,0,n)
			rep(k,j+1,n+1){
				double f=sqrt(fabs(0.0+l-(x[k]-x[j])));
				double diff=mid*b[k]-f;
				if(dp[j]+diff > dp[k]){
					dp[k]=dp[j]+diff;
					parent[k]=j;
				}
			}
		if(dp[n] > 0)
			hi=mid;
		else
			lo=mid;
	}
	vector<int> ans;
	while(n != 0){
		ans.push_back(n);
		n=parent[n];
	}
	for(int i=ans.size()-1; i >= 0; --i)
		printf("%d ", ans[i]);
	printf("\n");
}