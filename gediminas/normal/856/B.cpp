/*input
2
3
aba
baba
aaab
2
aa
a

*/
#include <bits/stdc++.h>

using namespace std;

int countt = 0;

struct node {
	int nr;
	node *tol[26] = {};
	node() {
		nr = countt++;
	}
};

void banga(node *dab, string tt = "") {
	if (dab == NULL)
		return;

	cout << dab->nr << " " << tt << endl;

	for (int i = 0; i < 26; i++)
		banga(dab->tol[i], tt + char('a' + i));
}

// 0 - neimti, 1 - imti
void dfs(int dab, vector<int> gra[], bool apl[], int din[][2]) {
	//cout << dab << endl;
	apl[dab] = true;

	din[dab][0] = 0;
	din[dab][1] = 1;

	for (auto && x : gra[dab]) {
		if (!apl[x]) {
			dfs(x, gra, apl, din);
			din[dab][0] += max(din[x][0], din[x][1]);
			din[dab][1] += din[x][0];
		}
	}

	//cout << -dab << endl;
}

int main () {
	int t;
	cin >> t;

	while (t--) {
		countt = 0;
		int n;
		cin >> n;
		node *pagr = new node();

		for (int i = 0; i < n; i++) {
			string a;
			cin >> a;
			node *dab = pagr;

			for (int i = 0; i < a.size(); i++) {
				if (dab->tol[a[i] - 'a'] == NULL)
					dab->tol[a[i] - 'a'] = new node();

				dab = dab->tol[a[i] - 'a'];
			}
		}

		//banga(pagr);

		vector<int> gra[countt];

		for (int i = 0; i < 26; i++) {
			if (pagr->tol[i] == NULL)
				continue;

			for (int j = 0; j < 26; j++) {
				if (pagr->tol[i]->tol[j] == NULL)
					continue;

				queue<pair<node *, node *> > bang;
				bang.push(make_pair(pagr->tol[i]->tol[j], pagr->tol[j]));

				while (!bang.empty()) {
					node *dab = bang.front().first;
					node *sim = bang.front().second;
					bang.pop();

					if (sim == NULL)
						continue;

					gra[dab->nr].push_back(sim->nr);
					gra[sim->nr].push_back(dab->nr);

					for (int kk = 0; kk < 26; kk++) {
						if (dab->tol[kk] != NULL)
							bang.push(make_pair(dab->tol[kk], sim->tol[kk]));
					}
				}
			}
		}

		int din[countt][2] = {};
		bool apl[countt] = {};
		int ats = 0;
		apl[0] = true;

		for (int i = 1; i < countt; i++) {
			if (!apl[i]) {
				dfs(i, gra, apl, din);
				ats += max(din[i][0], din[i][1]);
			}
		}

		cout << ats << "\n";
	}


	return 0;
}