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

inline void insert(vector<int>& dg, int x, int pos){
	while (x){
		while (dg.size() <= pos){
			dg.push_back(0);
		}
		dg[pos] += x % 2;
		x >>= 1;
		pos++;
	}
}

inline void simplify(vector<int>& dg){
	for (int i = 0; i < dg.size(); i++){
		if (dg[i] > 1){
			if (i + 1 == dg.size())
				dg.push_back(0);
			dg[i + 1] += dg[i] / 2;
			dg[i] %= 2;
		}
	}
	while (!dg.empty() && dg.back() == 0)
		dg.pop_back();
}

int main(){

	int n = nxt();
	long long k = nxt();
	vector<int> a(n + 1);
	vector<int> pos, neg;
	for (int i = 0; i <= n; i++){
		a[i] = nxt();
		if (a[i] > 0)
			insert(pos, a[i], i);
		else
			insert(neg, -a[i], i);
	}

	simplify(pos);
	simplify(neg);
	while (pos.size() < neg.size())
		pos.push_back(0);
	while (pos.size() > neg.size())
		neg.push_back(0);
	int i = (int)pos.size() - 1;
	while (pos[i] == neg[i] && i >= 0){
		i--;
	}
	assert(i >= 0);
	if (pos[i] < neg[i]){
		for (int j = 0; j <= n; j++)
			a[j] = -a[j];
		pos.swap(neg);
	}

	int pp = 0;
	for (int i = 0; i < (int)pos.size(); i++){
		if (pos[i] + pp >= neg[i]){
			pos[i] = pos[i] + pp - neg[i];
			pp = 0;
		} else {
			pos[i] = pos[i] + pp + 2 - neg[i];
			pp = -1;
		}
	}

	while (!pos.empty() && pos.back() == 0)
		pos.pop_back();
	assert(!pos.empty());

	// for (int i = 0; i < (int)pos.size(); i++){
	// 	cerr << pos[(int)pos.size() - i - 1];
	// }
	// cerr << "\n";
	// for (int i = n; i >= 0; i--){
	// 	cerr << a[i] << "*x^" << i << " + ";
	// }
	// cerr << "0\n";

	int l = (int)pos.size() - 1;
	int r = 0;
	while (pos[r] == 0)
		r++;
	if (abs(l - r) > 40){
		cout << "0\n";
		return 0;
	}
	long long s = 0;
	for (int i = l; i >= r; i--){
		s = s * 2 + pos[i];
	}

	int ans = 0;
	while (s <= k * 10 && r >= 0){
		if (r <= n && abs(a[r] - s) <= k && (r != n || a[r] - s != 0))
			ans++;
		r--;
		s <<= 1;
	}

	printf("%d\n", ans);

	return 0;
}