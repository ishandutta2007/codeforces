/*input
5 6
1 2
2 3
3 2
3 1
2 1
4 5
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> s;
vector<bool> apl(500);
vector<bool> stacke(500);
vector<int> gra[500];
int n, m;
int negalf = -1, negalt = -1;

bool find(int d) {
	apl[d] = true;
	stacke[d] = true;
	s.push_back(d);

	for (auto && x : gra[d]) {
		if (d == negalf and x == negalt)
			continue;

		if (stacke[x]){
	        s.push_back(x);
			return true;
		}

		if (!apl[x]) {
			if (find(x))
				return true;
		}
	}

	stacke[d] = false;
	s.pop_back();
	return false;
}

void ieskok() {
	s.clear();
	fill(apl.begin(), apl.end(), false);
	fill(stacke.begin(), stacke.end(), false);

	for (int i = 0; i < n; i++) {
		if (!apl[i]) {
			if (find(i))
				break;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		gra[a - 1].push_back(b - 1);
	}

	ieskok();

	vector<int> ss = s;

	if (ss.size() == 0) {
		cout << "YES\n";
		return 0;
	}

	for (int i = 0; i < ss.size(); i++) {
		negalf = ss[i];
		negalt = ss[(i + 1) % ss.size()];
		ieskok();

		if (s.size() == 0) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";

	return 0;
}