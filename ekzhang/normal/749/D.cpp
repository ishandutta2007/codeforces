#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 200013
int N, Q;
pair<int, int> B[MAXN];
int biggest[MAXN];
vector<int> all[MAXN];
set<pair<int, int> > s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> B[i].first >> B[i].second;
		B[i].first--;
		biggest[B[i].first] = B[i].second;
		all[B[i].first].push_back(B[i].second);
	}

	for (int i = 0; i < N; i++) {
		s.insert({biggest[i], i});
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int k; cin >> k;
		int missing[N];
		for (int j = 0; j < k; j++) {
			cin >> missing[j]; missing[j]--;
			s.erase({biggest[missing[j]], missing[j]});
		}
		auto it = s.rbegin();
		if (s.empty() || it->first == 0) {
			cout << "0 0\n";
		}
		else {
			int bidder = it->second;
			cout << bidder + 1 << ' ';
			it++;
			int second = (it == s.rend() ? 0 : it->first);
			cout << *lower_bound(all[bidder].begin(), all[bidder].end(), second) << '\n';
		}
		for (int j = 0; j < k; j++) {\
			s.insert({biggest[missing[j]], missing[j]});
		}
	}

	cout.flush();
	return 0;
}