#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
typedef long long LL;
LL s[maxn];
int p[maxn];
vector<int> G[maxn];
void no(){
	cout << -1;
	exit(0);
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 2; i <= n; i += 1){
		cin >> p[i];
		G[p[i]].push_back(i);
	}
	for(int i = 1; i <= n; i += 1) cin >> s[i];
	for(int i = 1; i <= n; i += 1)
		if(s[i] < 0)
			if(G[i].size() == 0) s[i] = s[p[i]];
			else{
				s[i] = 1E18;
				for(int v : G[i]) s[i] = min(s[i], s[v]);
				if(s[i] < s[p[i]]) no();
			}
	LL ans = 0;
	for(int i = 1; i <= n; i += 1) ans += s[i] - s[p[i]];
	cout << ans;
}