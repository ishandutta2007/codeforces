#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

const int maxn = 100005; 
const int maxv = maxn * 100;

int v[maxn];
bitset<maxn * 100> a;

int n, x, j, rez;

int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	sort(v + 1, v + n + 1);
	if (v[1] == 1 && x > 2) {
		cout << 1;
		return 0;
	}
	j = 1;                   
	for (int i = 2; i < maxv && i < x; ++i)
		if (a[i] == 0) {
			while (j <= n && v[j] < i)
				++j;
			if (v[j] != i) {
				cout << -1;
				return 0;
			}
			++rez;
			for (int k = i + i; k < maxv; k += i)
				a[k] = 1;
		}
	cout << rez;
}