#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int maxn = 120000;
void no(){ cout << "NO"; exit(0); }
int p[maxn], s[maxn];
vector<int> G[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 2; i <= n; i += 1){
		cin >> p[i];
		G[p[i]].push_back(i);
	}
	for(int i = n; i; i -= 1){
		if(not G[i].size())s[i] = 1;
		for(int v : G[i]) s[i] += s[v];
	}
	sort(s + 1, s + n + 1);
	for(int i = 1; i <= n; i += 1) cout << s[i] << " ";
}