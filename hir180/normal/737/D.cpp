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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int dp[4005][91][91][2];
int n,x[4005],rui[4005];
int rec(int zan,int dif,int pre,int play){
	if(dp[zan][dif][pre][play] != -INF) return dp[zan][dif][pre][play];
	if(zan<=0) return 0;
	int L,R;
	if(play == 0){
		L = 1 + (n-zan-dif)/2;
		R = n - (n-zan+dif)/2;
		if(R-L+1 >= pre){
			int LL = L+pre,RR = R;
			int get = rui[LL-1]-rui[L-1];
			dp[zan][dif][pre][play] = max(dp[zan][dif][pre][play],get-rec(zan-pre,pre-dif,pre,1-play));
		}
		if(R-L+1 >= pre+1){
			int LL = L+pre+1,RR = R;
			int get = rui[LL-1]-rui[L-1];
			dp[zan][dif][pre][play] = max(dp[zan][dif][pre][play],get-rec(zan-pre-1,pre+1-dif,pre+1,1-play));
		}
	}
	else{
		L = 1 + (n-zan+dif)/2;
		R = n - (n-zan-dif)/2;
		if(R-L+1 >= pre){
			int LL = L,RR = R-pre;
			int get = rui[R]-rui[RR];
			dp[zan][dif][pre][play] = max(dp[zan][dif][pre][play],get-rec(zan-pre,pre-dif,pre,1-play));
		}
		if(R-L+1 >= pre+1){
			int LL = L,RR = R-pre-1;
			int get = rui[R]-rui[RR];
			dp[zan][dif][pre][play] = max(dp[zan][dif][pre][play],get-rec(zan-pre-1,pre+1-dif,pre+1,1-play));
		}
	}
	if(dp[zan][dif][pre][play] == -INF) dp[zan][dif][pre][play] = 0;
	return dp[zan][dif][pre][play];
}
int main()
{
	cin >> n; 
	for(int i=1;i<=n;i++){
		cin >> x[i];
		rui[i] = rui[i-1]+x[i];
	}
	rep(i,4005) rep(j,91) rep(k,91) rep(l,2) dp[i][j][k][l] = -INF;
	cout << rec(n,0,1,0) << endl;
}