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
		a[i] = nxt() - n + 1 + i;
	sort(all(a));
	reverse(all(a));
	for (int i = 0; i < n; i++){
		a[i] += i;
	}
	for (int i = 0; i < n - 1; i++){
		if (a[i] < a[i + 1]){
			puts(":(");
			return 0;
		}
	}
	reverse(all(a));
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	puts("");

	return 0;
}