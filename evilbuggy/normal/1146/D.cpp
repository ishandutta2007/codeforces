#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll getSum(int l, int r, int b){
	if(l > r)return 0;
	ll ret = r - l + 1;
	while(l%b != 0 && l <= r){
		ret += l/b;
		l++;
	}
	if(l > r)return ret;
	while((r+1)%b != 0 && l <= r){
		ret += r/b;
		r--;
	}
	if(l > r)return ret;
	ret += b*1LL*(r/b + l/b)*(r/b - l/b + 1)/2;
	return ret;
}

int vis[200005];

void dfs(int v, int &a, int &b, int &cur, int &lim){
	if(vis[v])return;
	vis[v] = true;
	cur++;
	if(v + a <= lim)dfs(v + a, a, b, cur, lim);
	if(v - b >= 0)dfs(v - b, a, b, cur, lim);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int m, a, b;
	cin>>m>>a>>b;
	int g = __gcd(a, b);
	memset(vis, 0, sizeof(vis));
	int cur = 1;
	vis[0] = 1;
	ll ans = 1;
	for(int i = 1; i < min(m + 1, a+b); i++){
		if(i >= a && vis[i-a] == 1){
			dfs(i, a, b, cur, i);
		}
		ans += cur;
	}
	ans += getSum(a + b, m, g);
	cout<<ans<<endl;
	return 0;
}