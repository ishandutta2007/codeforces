#include <bits/stdc++.h>
using namespace std;

vector <pair <string, int> > v;
map <string, int> mp;
int p[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
string name[1010];
int a[1010][60], point[1010];

bool cmp1(int x, int y){
	if (point[x] != point[y]) return point[x] < point[y];
	for (int i = 0; i < 50; i++){
		if (a[x][i] != a[y][i]) return a[x][i] < a[y][i];
	}
	return 0;
}

bool cmp2(int x, int y){
	if (a[x][0] != a[y][0]) return a[x][0] < a[y][0];
	return cmp1(x, y);
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			string s;
			cin >> s;
			v.push_back(make_pair(s, i));
		}
	}
	int N = 0;
	for (int i = 0; i < v.size(); i++){
		mp[v[i].first] = 0;
	}
	for (map <string, int> :: iterator it = mp.begin(); it != mp.end(); it++){
		name[N] = it->first, it->second = N++;
	}
	for (int i = 0; i < v.size(); i++){
		int player = mp[v[i].first];
		int rank = v[i].second;
		a[player][rank]++;
		if (rank < 10) point[player] += p[rank];
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < N; i++){
		if (cmp1(ans1, i)) ans1 = i;
		if (cmp2(ans2, i)) ans2 = i;
	}
	cout << name[ans1] << endl << name[ans2] << endl;
	return 0;
}