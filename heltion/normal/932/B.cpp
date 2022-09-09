#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
auto no = [](){cout << "No";exit(0);}; 
#define maxn 2400000
int S[10][maxn];
int g(int n){
	if(n < 10) return n;
	int f = 1;
	for(; n; n /= 10)
		if(n % 10)
			f *= n % 10;
	return g(f);
}
int main(){
	ios::sync_with_stdio(false);
	for(int i = 1; i < maxn; i += 1){
		S[g(i)][i] = 1;
		for(int j = 1; j < 10; j += 1) S[j][i] += S[j][i - 1];
	}
	int q;
	cin >> q;
	while(q --){
		int l, r, k;
		cin >> l >> r >> k;
		cout << S[k][r] - S[k][l - 1] << endl;
	}
}