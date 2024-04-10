// Who needs long templates? :)
//    ? :)

/*---------------------------------+
|      TEXHOKYOK 2017 OTOP 1     |
+----------------------------------+
|              3AAA E            |
+---------------------------------*/

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

const int infinity = 1234567890;
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

#define stoi stoite

inline string itos(int i) {
	string res = "";
	while (i != 0) {
		res += '0' + (i % 10);
		i /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

inline int stoi(string s) {
	if (s.empty() || s.size() > 7 || s[0] == '0') {
		return -1;
	}
	for (char c : s) {
		if (!('0' <= c && c <= '9')) {
			return -1;
		}
	}
	int ans = 0;
	for (char c : s) {
		ans *= 10;
		ans += (c - '0');
	}
	if (itos(ans) != s) {
		return -1;
	}
	return ans;
} 

signed main() {
	#ifdef DEBUG
		stdin = freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<string> samples;
	vector<string> tests;
	for (int i = 0; i < n; i++) {
		string name; int type; cin >> name >> type;
		if (type == 0) {
			tests.push_back(name);
		} else {
			samples.push_back(name);
		}
	}
	vector<int> intNameS, intNameT;
	vector<char> busy(n, false);
	for (string s: samples) {
		int iName = stoi(s);
		intNameS.push_back(iName);
		if (1 <= iName && iName <= n) {
			busy[iName-1] = true;
		}
	}
	for (string t: tests) {
		int iName = stoi(t);
		intNameT.push_back(iName);
		if (1 <= iName && iName <= n) {
			busy[iName-1] = true;
		}
	}
	vector<int> freeS, freeT;
	vector<int> misS, misT;
	int sSz = (int)samples.size(), tSz = (int)tests.size();
	for (int i = 0; i < n; i++) {
		if (!busy[i]) {
			if (i < sSz) {
				freeS.push_back(i);
			} else {
				freeT.push_back(i - sSz);
			}
		}
	}
	for (int i = 0; i < sSz; i++) {
		if (sSz+1 <= intNameS[i] && intNameS[i] <= n) {
			misS.push_back(i);
		}
	}
	for (int i = 0; i < tSz; i++) {
		if (1 <= intNameT[i] && intNameT[i] <= sSz) {
			misT.push_back(i);
		}
	}
	vector< pair<string, string> > actions;
	while (!misS.empty() || !misT.empty()) {
		if (freeS.empty() && freeT.empty()) {
			assert(misS.size() == misT.size());
			int who = misS.back();
			int val = stoi(samples[who]) - 1 - sSz;
			actions.emplace_back(samples[who], "temp");
			samples[who] = "temp";
			misS.pop_back();
			freeT.push_back(val);
			continue;
		}
		if (!freeS.empty() && !misS.empty()) {
			int fs = freeS.back(), ms = misS.back();
			int val = stoi(samples[ms]) - 1 - sSz;
			string nMs = itos(fs + 1);
			actions.emplace_back(samples[ms], nMs);
			samples[ms] = nMs;
			freeS.pop_back();
			misS.pop_back();
			freeT.push_back(val);
			continue;
		}
		if (!freeT.empty() && !misT.empty()) {
			int ft = freeT.back(), mt = misT.back();
			int val = stoi(tests[mt]) - 1;
			string nMt = itos(ft + sSz + 1);
			actions.emplace_back(tests[mt], nMt);
			tests[mt] = nMt;
			freeT.pop_back();
			misT.pop_back();
			freeS.push_back(val);
			continue;
		}
		assert(false);
	}
	for (int i = 0; i < sSz; i++) {
		int intVal = stoi(samples[i]);
		if (1 <= intVal && intVal <= sSz) {
			continue;
		}
		string nName = itos(freeS.back() + 1);
		freeS.pop_back();
		actions.emplace_back(samples[i], nName);
	}
	for (int i = 0; i < tSz; i++) {
		int intVal = stoi(tests[i]);
		if (sSz+1 <= intVal && intVal <= n) {
			continue;
		}
		string nName = itos(freeT.back() + sSz + 1);
		freeT.pop_back();
		actions.emplace_back(tests[i], nName);
	}
	cout << actions.size() << "\n";
	for (auto it : actions) {
		cout << "move " << it.first << " " << it.second << "\n";
	}
	return 0;
}