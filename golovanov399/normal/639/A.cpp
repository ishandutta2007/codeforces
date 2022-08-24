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

	int n = nxt(), k = nxt(), q = nxt();
	vector<int> t(n);
	for (int i = 0; i < n; i++)
		t[i] = nxt();

	vector<int> a;
	while (q--){
		int tp = nxt(), v = nxt() - 1;
		if (tp == 1){
			a.push_back(t[v]);
			int i = (int)a.size() - 1;
			while (i > 0 && a[i] > a[i - 1]){
				swap(a[i], a[i - 1]);
				i--;
			}
			if (a.size() > k)
				a.pop_back();
		} else {
			bool ok = false;
			for (int i : a)
				if (i == t[v])
					ok = true;
			puts(ok ? "YES" : "NO");
		}
	}

	return 0;
}