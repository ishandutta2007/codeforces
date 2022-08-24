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

	int n = nxt(), q = nxt();
	bool changed = false;
	int a[2];
	a[0] = a[1] = 0;

	while (q--){
		int t = nxt();
		if (t == 1){
			int x = nxt();
			a[0] += x;
			a[1] += x;
			if (x % 2)
				changed = !changed;
		} else {
			if (changed){
				a[0]--;
				a[1]++;
			} else {
				a[0]++;
				a[1]--;
			}
			changed = !changed;
		}
		for (int i = 0; i < 2; i++){
			while (a[i] < 0)
				a[i] += n;
			while (a[i] >= n)
				a[i] -= n;
		}
	}

	vector<int> b(n);
	for (int i = 0; i < n; i++){
		b[(i + a[i % 2]) % n] = i;
	}
	for (int i = 0; i < n; i++){
		if (i)
			printf(" ");
		printf("%d", b[i] + 1);
	}
	puts("");

	return 0;
}