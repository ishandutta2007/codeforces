#include<iostream>
#include<string>
#include<map>
using namespace std;
int n, m;
map<string, int> mp;
int a[5010][3];
string p[5010];
int res[5010];
int ansa[1010];
int ansb[1010];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	string vname;
	cin >> vname;
	mp["?"] = 0;
	a[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		string tmp, o1name, o2name, op;
		cin >> tmp >> o1name;
		cin >> op;
		if (!cin) {
			op = "";
		}
		if (op == "AND")a[i][0] = 1;
		else if (op == "OR")a[i][0] = 2;
		else if (op == "XOR")a[i][0] = 3;
		else a[i][0] = 0;
		mp[vname] = i;
		if (a[i][0] == 0) {
			p[i] = o1name;
			vname = op;
		}
		else {
			cin >> o2name;
			a[i][1] = mp[o1name];
			a[i][2] = mp[o2name];
			cin >> vname;
		}
	}
	for (int i = 0; i < m; i++) {
		res[0] = 0;
		int suma = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j][0] == 0)res[j] = p[j][i] - '0';
			if (a[j][0] == 1)res[j] = res[a[j][1]] & res[a[j][2]];
			if (a[j][0] == 2)res[j] = res[a[j][1]] | res[a[j][2]];
			if (a[j][0] == 3)res[j] = res[a[j][1]] ^ res[a[j][2]];
			suma += res[j];
		}
		int sumb = 0;
		res[0] = 1;
		for (int j = 1; j <= n; j++) {
			if (a[j][0] == 0)res[j] = p[j][i] - '0';
			if (a[j][0] == 1)res[j] = res[a[j][1]] & res[a[j][2]];
			if (a[j][0] == 2)res[j] = res[a[j][1]] | res[a[j][2]];
			if (a[j][0] == 3)res[j] = res[a[j][1]] ^ res[a[j][2]];
			sumb += res[j];
		}
		if (suma > sumb) {
			ansa[i] = 1;
			ansb[i] = 0;
		}
		else if (sumb > suma) {
			ansa[i] = 0;
			ansb[i] = 1;
		}
		else {
			ansa[i] = 0;
			ansb[i] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		cout << ansa[i];
	}
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << ansb[i];
	}
	cout << endl;
	return 0;
}