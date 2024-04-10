#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct s {
	int parent;
	int count;
};

int n, m, a[100111];
vector<int> v[100111];
vector<pair<int, int> > aa;
s sets[100111];
long double ans;

int getparent(int i) {
	if (sets[i].parent==-1) return i;
	return (sets[i].parent=getparent(sets[i].parent));
}

int main() {
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> a[i], aa.push_back(make_pair(a[i], i));
	for (int j=0; j<m; j++) {
        int x, y;
		cin >> x >> y;
		x--, y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	sort(aa.begin(), aa.end());
	for (int i=0; i<n; i++) sets[i].parent=-1;
	for (int i=n-1; i>=0; i--) {
		vector<int> uni;
		int j=aa[i].second;
		for (int k=0; k<v[j].size(); k++) {
			int par=getparent(v[j][k]);
			if (sets[par].count==0) continue;
			if (par!=j) {uni.push_back(sets[par].count);
				sets[par].parent=j;
				sets[j].count+=sets[par].count;
			}
		}
		sets[j].count++;
		long double sum=0, mult=0;
		for (int k=0; k<uni.size(); k++) {
			mult+=sum*uni[k];
			sum+=uni[k];
		}
		ans+=mult*a[j]+sum*a[j];
	}
	cout << fixed << setprecision(20) << (ans*2)/n/(n-1);
	return 0;
}