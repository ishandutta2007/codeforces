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

int n, w, ans, p=1e9+7;
int a[300000], b[300000], kmp[500000];
long long pp[300000], ha[300000], h;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	srand((int)time(NULL));
	cin >> n >> w;
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	for (int i=0; i<w; i++) scanf("%d", &b[i]);
	pp[0]=1;
	for (int i=n-1; i>0; i--) a[i]-=a[i-1];
	for (int i=w-1; i>0; i--) b[i]-=b[i-1];
	if (w==1) cout << n;
	else {
		vector<int> v;
		for (int i=1; i<w; i++) v.push_back(b[i]);
		v.push_back(2000000000+100);
		for (int i=1; i<n; i++) v.push_back(a[i]);
		for (int i=1; i<v.size(); i++) {
			kmp[i]=kmp[i-1]+1;
			while (kmp[i]>1&&v[i]!=v[kmp[i]-1]) kmp[i]=kmp[kmp[i]-2]+1;
			if (kmp[i]==1&&v[i]!=v[0]) kmp[i]=0;
			if (kmp[i]>=w-1) ans++;
		}
		cout << ans;
	}
	return 0;
}