#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

vector <vector <int> > graf;
vector <int> vel;

int rek(int cvor, int rod) {
	int ret = 1;
	for(int sus : graf[cvor]) {
		if(sus == rod) continue;
		ret += rek(sus, cvor);
	}
	return vel[cvor] = ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		graf.clear();
		vel.clear();
		int n;
		cin >> n;
		graf.resize(n, vector <int>());
		vel.resize(n);
		int a, b;
		REP(i, n - 1) {
			cin >> a >> b;
			a--; b--;
			graf[a].push_back(b);
			graf[b].push_back(a);
		}
		rek(0, -1);
		bool nasao = 0;
		int cvor = 0, rod = -1;
		while(!nasao) {
			nasao = 1;
			for(int sus : graf[cvor]) {
				if(sus == rod) continue;
				if(vel[sus] > n / 2) {
					nasao = 0;
					rod = cvor;
					cvor = sus;
					break;
				}
			}
		}
		int drugi = -1;
		for(int sus : graf[cvor]) {
			if(sus == rod) continue;
			if(vel[sus] == n / 2) {
				drugi = sus;
				break;
			}
		}
		if(drugi == -1 || n % 2) {
			cout << cvor + 1 << " " << graf[cvor][0] + 1 << "\n";
			cout << cvor + 1 << " " << graf[cvor][0] + 1 << "\n";
		}
		else {
			int treci;
			if(graf[drugi][0] == cvor) treci = graf[drugi][1];
			else treci = graf[drugi][0];
			cout << drugi + 1 << " " << treci + 1 << "\n";
			cout << cvor + 1 << " " << treci + 1 << "\n";
		}
	}
	return 0;
}