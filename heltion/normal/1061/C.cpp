#include<bits/stdc++.h>
#define maxn 1200000
using namespace std;
typedef long long LL;
vector<int> G[maxn];
int S[maxn] = {1};
const int MOD = 1000000007;
int main(){
	ios::sync_with_stdio(false);
	for(int i = 1; i < maxn; i += 1){
		for(int j = i; j < maxn; j += i)
			G[j].push_back(i);
		reverse(G[i].begin(), G[i].end());
	}
	int n;
	cin >> n;
	while(n --){
		int a;
		cin >> a;
		for(int x : G[a]) S[x] = (S[x] + S[x - 1]) % MOD;
	}
	int ANS = 0;
	for(int i = 1; i < maxn; i += 1){
		ANS = (ANS + S[i]) % MOD;
	}
	cout << ANS;
}