/*input
3 3

*/
#include <bits/stdc++.h>

using namespace std;

int ats[100000];
int vis;
int n, k;

void create(int fr, int to, int skf, int skt) {
	if (fr + 1 >= to) {
		ats[fr] = skf;
		return;
	}

	int mid = (fr + to) / 2;

	if (vis < k) {
		vis += 2;
		create(fr, mid, skt - (mid - fr), skt);
		create(mid, to, skf, skt - (mid - fr));
	}
	else {
		create(fr, mid, skf, skf + mid - fr);
		create(mid, to, skf + mid - fr, skt);
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	vis = 1;

	create(0, n, 0, n);

	if (vis != k) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < n; i++)
		cout << ats[i] + 1 << " ";


	return 0;
}