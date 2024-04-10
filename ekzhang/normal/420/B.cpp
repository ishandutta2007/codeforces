#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100013
#define MAXM 100013

int N, M;
int inRoom[MAXN];
int isLeader[MAXN];
int event[MAXM];
int onlyOne = -1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		inRoom[i] = -1;
		isLeader[i] = -1;
	}

	for (int i = 0; i < M; i++) {
		string s; int p;
		cin >> s >> p; p--;
		event[i] = p;
		if (inRoom[p] == -1) {
			// this is first event recorded
			if (s[0] == '+') {
				inRoom[p] = 0;
			}
			else {
				inRoom[p] = 1;
			}
		}
	}

	int atLeast = 0; // this many people in room
	for (int i = 0; i < N; i++) {
		if (inRoom[i] == -1) {
			// we don't know anything about this guy
			isLeader[i] = 1;
		}
		if (inRoom[i] == 1) {
			atLeast++;
		}
	}

	for (int i = 0; i < M; i++) {

		// if guy joins, lmao
		// either he's not leader or everyone else
		// isn't leader (except untracked), we win either way
		if (inRoom[event[i]] == 0) {
			atLeast++;
			inRoom[event[i]] = 1;
			if (atLeast - 1) {
				isLeader[event[i]] = 0;
			}
			else {
				if (onlyOne != -1) {
					if (onlyOne == event[i]) {
						continue;
					}
					// ok no possible leaders
					isLeader[onlyOne] = 0;
					break;
				}
				onlyOne = event[i];
				for (int j = 0; j < N; j++) {
					if (isLeader[j] == -1 && event[i] != j) isLeader[j] = 0;
				}
			}
		}
		else if (inRoom[event[i]] == 1) {
			atLeast--;
			inRoom[event[i]] = 0;
			if (atLeast) {
				isLeader[event[i]] = 0;
			}
			else {
				if (onlyOne != -1) {
					if (onlyOne == event[i]) {
						continue;
					}
					isLeader[onlyOne] = 0;
					break;
				}
				onlyOne = event[i];
				for (int j = 0; j < N; j++) {
					if (isLeader[j] == -1 && event[i] != j) isLeader[j] = 0;
				}
			}
		}
		else {
			throw domain_error("crapp!");
		}
	}

	int k = 0;
	vector<int> ans;
	for (int i = 0; i < N; i++) {
		if (isLeader[i] == -1 && i != onlyOne) {
			error(i);
			throw domain_error("crap v2");
		}
		if (isLeader[i] != 0) {
			k++;
			ans.push_back(i+1);
		}
	}

	cout << k << endl;
	for (int x : ans) {
		cout << x << ' ';
	}

	cout << endl;
	return 0;
}