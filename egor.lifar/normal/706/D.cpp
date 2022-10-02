#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>


using namespace std;


#define next next1
#define prev prev1
#define add add1
#define delete delete1
int q;
string s[200001];
int x[200001];
string bits[200001];
int uk = 0;
int next[10000001][2];
int prev[10000001];
int cnt[10000001];
int root = 0;
map<string, int> where;


string getbits(int x) {
	string s;
	for (int i = 0; i < 32; i++) {
		if (x & 1) {
			s += "1";
		} else {
			s += "0";
		}
		x >>= 1;
	}
	reverse(s.begin(), s.end());
	return s;
}


void add(string s, int t) {
	int cur = root;
	for (int i = 0; i < (int)s.size(); i++) {
		if (next[cur][s[i] - '0']) {
			cur = next[cur][s[i] - '0'];
			cnt[cur]+= t;
		} else {
			uk++;
			next[cur][s[i] - '0'] = uk;
			prev[uk] = cur;
			cur = uk;
			cnt[cur]+= t;
		}
	}
	where[s] = cur;
}


void delete(string s) {
	int cur = where[s];
	while (cur) {
		cnt[cur]--;
		cur = prev[cur];
	}
}


int getnum(string a) {
	int ans = 0;
	for (int i = 0; i < 32; i++) {
		ans *= 2;
		ans += a[i] - '0';
 	}
 	return ans;
}


int findans(string s) {
	int cur = root;
	string ans;
	for (int i = 0; i < (int)s.size(); i++) {
		if (next[cur][1 - (s[i] - '0')] && cnt[next[cur][1 - (s[i] - '0')]]) {
			cur = next[cur][1 - (s[i] - '0')];
			ans += '1';
		} else {
			cur = next[cur][s[i] - '0'];
			ans += '0';
		}
	}
	// /cout << ans << endl;
	return getnum(ans);
}


int main() {
	cin >> q;
	add(getbits(0), 1);
	for (int i = 0; i < q; i++) {
		cin >> s[i];
		scanf("%d", &x[i]);
		bits[i] = getbits(x[i]);
		//cout << bits[i] << endl;
		add(bits[i], 0);
	}
	for (int i = 0; i < q; i++) {
		if (s[i] == "+") {
			add(bits[i], 1); 
		} else {
			if (s[i] == "-") {
				delete(bits[i]);
			} else {
				printf("%d\n", findans(bits[i]));
			}
		}
	}
    return 0;
}