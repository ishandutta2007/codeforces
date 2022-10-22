#include <bits/stdc++.h>
using namespace std;

int n, x, y;
int in;
vector<int> query;
set<int> answer;

void find(vector<int>& num, int bit) {
	if (bit == 0) {
		//assert(num.size() == 1);
		answer.insert(num[0]);
		return;
	}
	else {
		if (bit >= num.size()) {
			find(num, bit/2);
		}
		else {
			cout << "? " << bit;
			for (int i = 0; i < bit; i++)
				cout << " " << num[i]+1;
			cout << endl;
			cin >> in; if (in == -1) for(;;);
			if (in == ((bit%2)?y:y^x))
				num.erase(num.begin()+bit, num.end());
			else
				num.erase(num.begin(), num.begin()+bit);
			find(num, bit/2);
		}
	}
}

void findseg(int rest, int bit) {
	if (rest == 0) return;
	int upper = bit*(1<<(rest-1));
	if (upper < query.size()) {
		cout << "? " << upper;
		for (int i = 0; i < upper; i++) {
			cout << " " << query[i]+1;
		} cout << endl;
		cin >> in; if (in == -1) for(;;);
		if (in == ((upper%2)?y:y^x))
			query.erase(query.begin()+upper, query.end());
		else
			query.erase(query.begin(), query.begin()+upper);
	}
	findseg(rest-1, bit);
}

int main() {
	ios::sync_with_stdio(0);

	cin >> n >> x >> y;
	// find size
	int bit = 1<<9;
	while (bit >= n) bit /= 2;
	//cerr << "bit: " << bit << endl;
	int init = bit;
	while (bit > 0) {
		query.clear();
		for (int i = 0; i < n; i++)
			if (bit & i) query.push_back(i);
		cout << "? " << query.size();
		for (auto& q: query) cout << " " << q+1;
		cout << endl;
		cin >> in; if (in == -1) for(;;);
		if (in == ((query.size()%2)?y:y^x)) break;
		bit /= 2;
	}
	//cerr << "init: " << init << "  bit: " << bit << endl;
	int rest = log2(init/bit);
	//cerr << "findseg: " << endl;
	findseg(rest, bit);
	// query should be seg. binary search on query and bit is before query
	//cerr << "query: "; for (auto& q: query) //cerr << q+1 << " ";
	//cerr << endl;
	vector<int> next;
	for (int i = query[0]-bit; i < query[0]; i++) 
		next.push_back(i);
	//cerr << "findquery: " << endl;
	find(query, bit);
	//cerr << "findnext: " << endl;
	find(next, bit);

	cout << "!";
	for (auto& ans: answer) {
		cout << " " << ans+1;
	} cout << endl;
	
	return 0;
}