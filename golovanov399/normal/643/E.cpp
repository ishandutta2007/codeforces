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

vector<vector<int>> a;
vector<vector<double>> p;
vector<vector<double>> old;
vector<int> pr;

const int MAGIC = 40;

void relax(itn v, int w, int pos){
	if ((int)p[v].size() <= pos + 1)
		p[v].resize(pos + 2, 1);
	
	for (int i = 0; i < 2; i++){
		if (pos + i >= MAGIC)
			break;
		old[v][i] = (1 + p[v][pos + i]) * 0.5;
		p[v][pos + i] *= (pos + i == 0) ? 0.5 : (1 + p[w][pos + i - 1]) * 0.5 / old[w][i];
	}
}

int main(){

	old.resize(1, vector<double>(2, 1));
	a.resize(1);
	p.resize(1);
	p[0].push_back(1);
	pr.push_back(-1);

	int q = nxt();
	cout << setprecision(10) << fixed;
	while (q--){
		int t = nxt();
		if (t == 1){
			int v = nxt() - 1;
			int nw = a.size();
			a.emplace_back();
			p.emplace_back(1, 1);
			old.emplace_back(2, 1);
			a[v].push_back(nw);
			pr.push_back(v);
			int pos = 0;
			int w = nw;
			while (pr[nw] > -1 && pos < MAGIC){
				nw = pr[nw];
				relax(nw, w, pos);
				pos++;
				w = nw;
			}
		} else {
			int v = nxt() - 1;
			cout << 1.0 * p[v].size() - accumulate(all(p[v]), 0.0) << "\n";
		}
	}

	return 0;
}