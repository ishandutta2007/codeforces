#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair

int n, k, s[111111], tr[450000], add[450000];
long long ans=0;
vector<int> v1[111111], v2[111111];

void flip(int l, int r, int a, int b, int k) {
	if (r<a||l>b) return;
	if (l<=a&&r>=b) {
		add[k]^=1;
		tr[k]=b-a+1-tr[k];
		return ;
	}
	int c=(a+b)/2;
	flip(l, r, a, c, k*2+1);
	flip(l, r, c+1, b, k*2+2);
	tr[k]=tr[2*k+1]+tr[2*k+2];
	if (add[k]) tr[k]=b-a+1-tr[k];
}

int sum(int l, int r, int a, int b, int k) {
	if (r<a||l>b) return 0;
	if (l<=a&&r>=b) return tr[k];
	int c=(a+b)/2;
	int res=sum(l, r, a, c, k*2+1)+sum(l, r, c+1, b, k*2+2);
	if (add[k]) res=min(b, r)-max(a, l)+1-res;
	return res;
}

int main() {
	cin >> n >> k;
	for (int i=0; i<n; i++) cin >> s[i];
	sort(s, s+n);
	for (int i=0; i<k; i++) {
		int l, r;
		cin >> l >> r;
		int a=lower_bound(s, s+n, l)-s, b=upper_bound(s, s+n, r)-s;
		v1[a].pb(b), v2[b].pb(a);
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<(int)v1[i].size(); j++) flip(i, v1[i][j]-1, 0, n-1, 0);
		for (int j=0; j<(int)v2[i].size(); j++) flip(v2[i][j], i-1, 0, n-1, 0);
		long long wins=i-sum(0, i-1, 0, n-1, 0)+sum(i+1, n-1, 0, n-1, 0);
		ans+=wins*(wins-1)/2;
	}
	ans=(long long)n*(long long)(n-1)*(long long)(n-2)/6-ans;
	cout << ans;
	return 0;
}