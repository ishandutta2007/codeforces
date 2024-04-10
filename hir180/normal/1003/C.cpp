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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,k;
int x[5005],rui[5005];
int main(){
	cin>>n>>k;
	repn(i,n){
		scanf("%d",&x[i]);
		rui[i] = rui[i-1]+x[i];
	}
	double ans = 0;
	repn(i,n){
		for(int j=i+k-1;j<=n;j++){
			int sum = rui[j]-rui[i-1];
			double res = (double)(sum)/(double)(j-i+1);
			ans=max(ans,res);
		}
	}
	printf("%.12f\n",ans);
}