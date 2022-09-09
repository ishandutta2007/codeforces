#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define maxn 12000
pair<int, int> a[maxn], b[maxn];
int main(){
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> a[i].first >> a[i].second;
	for(int i = 0; i < n; i += 1) cin >> b[i].first >> b[i].second;
	sort(a, a + n);
	sort(b, b + n);
	cout << a[0].first + b[n - 1].first << " " << a[0].second + b[n - 1].second;
	return 0;
}