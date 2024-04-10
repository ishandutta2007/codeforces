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
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int x = nxt();
			if (x)
				a[i] = max(a[i], x);
		}
	}
	int cur = n - 1;
	for (int i = 0; i < n; i++){
		if (a[i] == n - 1)
			cout << cur++ << " ";
		else
			cout << a[i] << " ";
	}
	puts("");

	return 0;
}