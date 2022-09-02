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
int n;
bool dp[100005];
int main(){
	cin>>n;
	dp[0] = 1;
	int cur = 1;
	for(int i=1;i<=100;i++){
		for(int j=100000;j>=0;j--){
			if(j>=4 && dp[j-4] && !dp[j]){
				dp[j] = 1;
				cur++;
			}
			if(j>=9 && dp[j-9] && !dp[j]){
				dp[j] = 1;
				cur++;
			}
			if(j>=49 && dp[j-49] && !dp[j]){
				dp[j] = 1;
				cur++;
			}
		}
		if(i==n){
			cout<<cur<<endl;
			return 0;
		}
	}
	cout<<1LL*cur+49LL*(n-100)<<endl;
}