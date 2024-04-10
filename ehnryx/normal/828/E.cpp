#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll MAXN = 100000;
struct BITree { ll freq[MAXN+1]; BITree() { memset(freq, 0, sizeof freq); }
  void insert(int x, ll cnt=1) {
    for ( ; x <= MAXN; x += x & -x) freq[x] += cnt;
      //for (int y = argy; y <= MAXN; y += y & -y) freq[x][y] += cnt;
  }
  ll query(int x) { ll sum = 0;
    for ( ; x; x -= x & -x) sum += freq[x];
      //for (int y = argy; y; y -= y & -y) sum += freq[x][y];
    return sum; }
  void insert_range(int xl,int xr,ll cnt=1) {insert(xl,cnt); insert(xr+1,-cnt);}
  ll query_range(int xl, int xr) { return query(xr) - query(xl-1); }
  int get_nth(ll n) { int x = 1<<30; // assumes non-negative frequencies
    for (int step = x>>1; step; step >>= 1)
      if (x-step > MAXN || freq[x-step] >= n) x -= step; else n -= freq[x-step];
    return x; } };

BITree count2[4][11][10];
// letter, mod, residue

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	map<char, int> m;
	m.insert(pair<char,int>('A',0));
	m.insert(pair<char,int>('T',1));
	m.insert(pair<char,int>('G',2));
	m.insert(pair<char,int>('C',3));

	char s[100002];
	string ss, t;
	int q, len, sum;
	int type, pos, right, temp;
	char c;
	cin >> ss;
	len = ss.size();
	strcpy(s, ss.c_str());
	// fill count2 table
	for (int mod = 1; mod <= 10; mod++) {
		for (int i = 0; i < len; i++) {
			count2[m[s[i]]][mod][(i+1)%mod].insert(i+1, 1);
		}
	}

	// queries
	cin >> q;
	while (q--) {
		cin >> type;
		if (type == 1) {
			cin >> pos >> c;
			for (int mod = 1; mod <= 10; mod++) {
				count2[m[s[pos-1]]][mod][pos%mod].insert(pos, -1);
				count2[m[c]][mod][pos%mod].insert(pos, 1);
			}
			s[pos-1] = c;
		}
		else {
			cin >> pos >> right >> t;
			sum = 0;
			temp = t.size();
			for (int i = 0; i < min(right,temp); i++) {
				sum += count2[m[t[i]]][temp][(pos+i)%temp].query_range(pos, right);
			}
			cout << sum << endl;
		}
	}

	return 0;
}