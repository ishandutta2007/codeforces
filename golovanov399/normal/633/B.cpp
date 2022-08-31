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

int qw(int x){
	int res = 0;
	while (x % 5 == 0){
		x /= 5;
		res++;
	}
	return res;
}

int main(){

	int n;
	cin >> n;
	int cnt = 0;
	vector<int> ans;
	for (itn i = 1; cnt <= n; i++){
		cnt += qw(i);
		if (cnt == n)
			ans.push_back(i);
	}

	cout << ans.size() << "\n";
	for (auto x : ans)
		cout << x << " ";
	cout << "\n";

	return 0;
}