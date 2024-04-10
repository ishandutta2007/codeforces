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

bool is_pr(int x){
	for (int i = 2; i * i <= x; i++){
		if (x % i == 0)
			return false;
	}
	return true;
}

int main(){

	int n = nxt();
	vector<int> ans;
	for (int i = 2; i <= n; i++){
		if (is_pr(i)){
			int j = i;
			while (j <= n){
				ans.push_back(j);
				j *= i;
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto x : ans)
		cout << x << " ";
	cout << "\n";

	return 0;
}