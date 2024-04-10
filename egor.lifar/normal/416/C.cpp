#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set> 


using namespace std;


int n, k;
long long ans = 0;
pair< pair<int, int>, int> p[1000];
int r[1000];
bool b[1000];
vector< pair<int, int> > v;


int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first.second >> p[i].first.first;
		p[i].second = i;
	}
	sort(p, p + n);
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> r[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		int a = -1;
		for (int j = 0; j < k; j++) {
			if (r[j] >= p[i].first.second && !b[j]) {
				if (a == -1 || (a != -1 && r[a] > r[j])) {
					a = j;
				}
			}
		}
		if (a != -1) {
			b[a] = true;
			ans += p[i].first.first;
			v.push_back(make_pair(p[i].second + 1, a + 1));
		}
	}
	cout << v.size() << ' ' << ans << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << endl;
	}
    return 0;
}