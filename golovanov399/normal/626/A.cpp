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

int main(){

	int n = nxt();
	string s;
	cin >> s;
	vector<int> x(n + 1), y(n + 1);
	for (int i = 0; i < n; i++){
		x[i + 1] = x[i];
		y[i + 1] = y[i];
		if (s[i] == 'U')
			x[i + 1]++;
		else if (s[i] == 'D')
			x[i + 1]--;
		else if (s[i] == 'L')
			y[i + 1]++;
		else
			y[i + 1]--;
	}
	int cnt = 0;
	for (int i = 0; i < n + 1; i++){
		for (int j = i + 1; j < n + 1; j++){
			if (x[i] == x[j] && y[i] == y[j])
				cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}