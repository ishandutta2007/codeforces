#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int N;
int L[MAXN], R[MAXN];

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> L[i] >> R[i];
		L[i] --;
		R[i] --;
	}
	vector<string> ends;
	for(int i = N - 1; i >= 0; i--) {
		string cur = "";
		while(cur.size() < L[i]) {
			if(ends.empty()) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			cur += ends.back();
			ends.pop_back();
		}

		if(cur.size() > R[i]) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		
		ends.push_back("(" + cur + ")");
	}
	while(!ends.empty()) {
		cout << ends.back();
		ends.pop_back();
	}
	cout << '\n';
	return 0;
}