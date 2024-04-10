#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 511;
bitset<N> pr[N];
char ok[N];

int main(){

	pr[0][0] = true;
	ok[0] = true;

	int n = nxt(), k = nxt();
	for (int i = 0; i < n; i++){
		int x = nxt();
		for (int j = N - x - 1; j >= 0; j--){
			if (ok[j]){
				ok[j + x] = 1;
				pr[j + x] |= pr[j];
				pr[j + x] |= (pr[j] << x);
			}
		}
	}

	vector<int> ans;
	for (int i = 0; i <= k; i++){
		if (pr[k][i]){
			ans.push_back(i);
		}
	}

	printf("%d\n", (int)ans.size());
	for (auto x : ans){
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}