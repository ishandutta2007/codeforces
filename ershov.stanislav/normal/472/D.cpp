#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

int n;
int d[2222][2222], dd[2222], dn[2222];
bool deleted[2222];
multiset<pair<int, pair<int, int> > > msd;

bool add(int i) {
	for (int j=0; j<n; j++) if (deleted[j]) {
		if (j!=dn[i]&&d[i][j]!=d[i][dn[i]]+d[dn[i]][j]) {
			cout << "NO";
			return true;
		}
	}
	deleted[i]=true;
	for (int j=0; j<n; j++) if (!deleted[j]) {
		if (dd[j]>d[i][j]) dd[j]=d[i][j], dn[j]=i;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
		scanf("%d", &d[i][j]);
		if ((i==j&&d[i][j]!=0)||(i>j&&d[i][j]!=d[j][i])) {
			cout << "NO";
			return 0;
		}
	}
	for (int i=1; i<n; i++) dd[i]=1200000000;
	add(0);
	for (int i=0; i<n-1; i++) {
		int m=1200000000, mi=0;
		for (int j=0; j<n; j++) if (!deleted[j]&&(dd[j]<m)) m=dd[j], mi=j;
		if (m==0) {
			cout << "NO";
			return 0;
		}
		if (add(mi)) return 0;
	}
	cout << "YES";
	return 0;
}