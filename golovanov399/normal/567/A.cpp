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
	for (int i = 0; i < n; i++)
		a[i] = nxt();
	for (int i = 0; i < n; i++){
		if (i == 0)
			printf("%d ", a[1] - a[0]);
		else if (i == n - 1)
			printf("%d ", a[n - 1] - a[n - 2]);
		else
			printf("%d ", min(a[i + 1] - a[i], a[i] - a[i - 1]));
		printf("%d\n", max(a[i] - a[0], a[n - 1] - a[i]));
	}

	return 0;
}