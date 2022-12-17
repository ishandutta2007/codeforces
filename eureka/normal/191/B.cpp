#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<cstdio>

using namespace std;

const int N = 110000;
typedef long long lld;
int a[N];
int in[N];
lld sum[N];
lld n, k, s;

int id(int num){
	int i = upper_bound(a+1, a+1+n, num, greater<int>()) - a - 1;
	return i;
}

int main(){
	cin >> n >> k >> s;
	for (int i=1; i<=n; ++i) {
		scanf("%d", &a[i]);
		in[i] = a[i];
	}
	sort(a+1, a+n, greater<int>());
	sum[0] = 0;
	for (int i=1; i<=n; ++i) sum[i] = sum[i-1] + a[i];

	int ans = n;
	lld c;
	for (int i=1; i<n; ++i){
		int t = id(in[i]);
		if (t <= k) c = sum[k];
		else c = sum[k-1] + in[i];
		if (c > s){
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}