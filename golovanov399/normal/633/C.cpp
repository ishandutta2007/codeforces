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

struct Trie{
	vector<vector<int>> to;
	int n;
	vector<int> empty;
	vector<int> end;

	Trie(){
		n = 1;
		empty.resize(26, -1);
		to.push_back(empty);
		end.push_back(-1);
	}

	void add(const string& s, int num){
		int q = 0;
		for (char c : s){
			if (to[q][c - 'a'] == -1){
				to[q][c - 'a'] = n++;
				to.push_back(empty);
				end.push_back(-1);
			}
			q = to[q][c - 'a'];
		}
		end[q] = num;
	}
};

int main(){

	Trie trie;

	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	string s;
	cin >> s;

	int m;
	cin >> m;
	vector<string> a(m);
	for (int i = 0; i < m; i++){
		cin >> a[i];
		string st = "";
		for (char c : a[i]){
			if (c >= 'A' && c <= 'Z')
				st += (char)(c - 'A' + 'a');
			else
				st += c;
		}
		reverse(all(st));
		// cerr << st << "\n";
		trie.add(st, i);
	}

	vector<int> state;
	vector<int> nums(n + 1, -1);
	state.push_back(0);
	for (int i = 0; i < n; i++){
		// cerr << i << ": ";
		bool ok = 0;
		vector<int> st1;
		for (auto p : state){
			if (trie.to[p][s[i] - 'a'] >= 0){
				st1.push_back(trie.to[p][s[i] - 'a']);
				// cerr << trie.to[p][s[i] - 'a'] << ", ";
				if (trie.end[trie.to[p][s[i] - 'a']] >= 0){
					nums[i + 1] = trie.end[trie.to[p][s[i] - 'a']];
					ok = 1;
				}
			}
		}
		if (ok){
			st1.push_back(0);
		}
		st1.swap(state);
		// cerr << "\n";
	}

	vector<int> ans;
	int i = n;
	while (i){
		ans.push_back(nums[i]);
		assert(nums[i] > -1);
		i -= a[nums[i]].length();
	}
	reverse(all(ans));
	cout.sync_with_stdio(0);
	for (int i = 0; i < (int)ans.size(); i++){
		if (i > 0)
			cout << " ";
		cout << a[ans[i]];
	}
	cout << "\n";

	return 0;
}