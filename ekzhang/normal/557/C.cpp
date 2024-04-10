#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }


typedef pair<int, int> pii;
#define MAXN 100013
#define len first
#define nrg second

int N;
pii leg[MAXN];
int ans = 0;
int su = 0;
multiset<int, greater<int> > cur;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> leg[i].first;
	}
	for (int i = 0; i < N; i++) {
		cin >> leg[i].second;
		su += leg[i].nrg;
	}

	sort(leg, leg + N);

	int start = 0;
	int finish = 0;
	int kc = 0;
	while (start < N) {
		if (leg[start].len != leg[finish].len) {
			int amt = min((int) cur.size(), finish - start - 1);
			int c = 0;
			for (auto it = cur.begin(); amt; amt--, it++) {
				c += *it;
			}
			ans = max(ans, c + kc);

			kc = 0;
			for (int i = start; i < finish; i++) {
				cur.insert(leg[i].nrg);
			}
			start = finish;
		}
		else {
			kc += leg[finish].nrg;
			finish++;
		}
	}
	cout << su - ans << endl;
	return 0;
}