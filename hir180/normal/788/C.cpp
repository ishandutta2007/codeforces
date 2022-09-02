#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
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
int n,m;
bool used[1005];
vector<int>vec;
bitset<2200>dp[1005];
int main(){
	cin>>n>>m;
	rep(i,m){
		int a; scanf("%d",&a);
		used[a] = 1;
	}
	for(int i=0;i<=1000;i++) if(used[i]) vec.pb(i-n);
	dp[0][1100] = 1;
	for(int i=1;i<=1003;i++){
		for(int j=0;j<vec.size();j++){
			if(vec[j] > 0){
				dp[i] |= (dp[i-1]<<vec[j]);
			}
			else if(vec[j] < 0){
				dp[i] |= (dp[i-1]>>(-vec[j]));
			}
			else dp[i] |= dp[i-1];
			if(dp[i][1100] == 1){
				cout << i << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}