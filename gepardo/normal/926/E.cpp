#include <iostream>
#include <vector>

using namespace std;

vector <int> a, nxt, pr;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n; a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	nxt.resize(n); pr.resize(n);
	for (int i = 0; i < n; i++) {
		nxt[i] = i + 1; pr[i] = i - 1;
	}
	nxt[n - 1] = -1; pr[0] = -1;
	
	int pos = 0;
	while (pos != -1) {
		if (pr[pos] == -1) {
			pr[nxt[pos]] = pos;
			pos = nxt[pos]; continue;
		}
		if (a[pr[pos]] == a[pos]) {
			pos = pr[pos]; a[pos]++;
			nxt[pos] = nxt[nxt[pos]];
		} else {
			pr[nxt[pos]] = pos;
			pos = nxt[pos];
		}
		//cout << pos << endl;
	}
	/*
	for (int i = 0; i < n; i++)
		cout << i << " : " << a[i] << " " << nxt[i] << " " << pr[i] << endl;
	*/
	int cnt = 0; pos = 0;
	while (pos != -1)
		cnt++, pos = nxt[pos];
	cout << cnt << endl;
	pos = 0;
	while (pos != -1) {
		cout << a[pos] << " ";
		pos = nxt[pos];
	}
	
	return 0;
}