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
	vector<pair<string, int>> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;
	for (int i = 0; i < n; i++)
		p[i].second--;
	vector<char> a(1000000);
	for (itn i = 0; i < n; i++){
		if (!a[p[i].second])
			if (p[i].first == "-")
				a[p[i].second] = 1;
			else
				a[p[i].second] = 2;
	}
	int k = 0;
	int m = 0;
	for (int i = 0; i < 1000000; i++)
		k += a[i] % 2;
	m = k;
	for (int i = 0; i < n; i++){
		if (p[i].first == "+")
			k++;
		else
			k--;
		m = max(m, k);
	}
	cout << m << "\n";

	return 0;
}