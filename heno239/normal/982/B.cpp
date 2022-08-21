#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double PI = 3.14159265358979;
const double E = 2.718281828459045;
const double root2 = sqrt(2);
typedef pair<int, int> P;
typedef unsigned int ui;
int main() {
	int n;
	scanf("%d", &n);
	int w; P p[200000];
	for (int i = 0; i < n; i++) {
		scanf("%d", &w);
		p[i] = make_pair(w, i + 1);
	}
	sort(p, p + n);
	char s[400000];
	scanf(" %s", s);
	int count = -1;
	set<P> u;
	for (int i = 0; i < 2 * n; i++) {
		if (s[i] == '0') {
			count++; u.insert(p[count]);
			if(i!=2*n-1)printf("%d ", p[count].second);
			else if (i == 2 * n - 1)printf("%d", p[count].second);
		}
		else if (s[i] == '1') {
			auto itr = u.end();itr--;
			P t = P(*itr);
			if (i != 2 * n - 1)printf("%d ", t.second);
			else if (i == 2 * n - 1)printf("%d", t.second);
			u.erase(itr);
		}
	}
	return 0;
}