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

const int N = 1111111;
int a[N];

int main(){

	int n = nxt();
	for (int i = 0; i < n; i++){
		a[nxt()]++;
	}
	for (int i = 0; i < N - 1; i++){
		a[i + 1] += a[i] / 2;
		a[i] %= 2;
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
		ans += a[i];
	printf("%d\n", ans);

	return 0;
}