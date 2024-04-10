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
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		a[i] = nxt();
	}

	vector<char> used(n);
	int i = 0;
	while (i >= 0 && i < n && !used[i]){
		used[i] = 1;
		if (s[i] == '>')
			i += a[i];
		else
			i -= a[i];
	}

	cout << ((i >= 0 && i < n) ? "INFINITE" : "FINITE") << "\n";

	return 0;
}