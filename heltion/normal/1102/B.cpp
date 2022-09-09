#include<bits/stdc++.h>
using namespace std;
#define maxn 6000
int a[maxn], b[maxn], c[maxn], d[maxn];
void no(){
	cout << "NO";
	exit(0);
}
int main(){
	int n, k;
	cin >> n >> k;
	if(n < k) no();
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i <= n; i += 1) b[a[i]] += 1;
	for(int i = 1; i < maxn; i += 1) if(b[i] > k) no();
	for(int i = 1; i <= n; i += 1) c[i] = i;
	sort(c + 1, c + n + 1, [&](const int &x, const int &y){
		return a[x] < a[y];
	});
	for(int i = 1; i <= n; i += 1) d[c[i]] = (i - 1) % k + 1;
	cout << "YES" << endl;
	for(int i = 1; i <= n; i += 1) cout << d[i] << " ";
}