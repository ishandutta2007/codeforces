#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, v[1011], v2[1011];
pair<int, int> p[2011];
vector<pair<int, int> > vi;
long long ans=0;

int main() {
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> v[i], vi.push_back(make_pair(v[i], i));
	for (int i=0; i<m; i++) {
		cin >> p[i].first >> p[i].second;
		p[i].first--, p[i].second--;
		v2[p[i].first]+=v[p[i].second];
		v2[p[i].second]+=v[p[i].first];
	}
	sort(vi.begin(), vi.end());
	for (int i=n-1; i>=0; i--) {
		ans+=v2[vi[i].second];
		for (int j=0; j<m; j++) {
			if (p[j].first==vi[i].second) v2[p[j].second]-=v[p[j].first];
			if (p[j].second==vi[i].second) v2[p[j].first]-=v[p[j].second];
		}
	}
	cout << ans;
	return 0;
}