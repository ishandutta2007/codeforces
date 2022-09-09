#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
typedef long long LL;
LL a[maxn];
int main(){
	ios::sync_with_stdio(false);
	LL n, m, s = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i += 1) cin >> a[i];
	sort(a, a + n, greater<int>());
	for(int i = 1; i < n; i += 1){
		if(a[i] > 1 && a[i] >= a[i - 1]){
			s += a[i] - max(a[i - 1] - 1, 1LL);
			a[i] = max(a[i - 1] - 1, 1LL);
			
		}
		if(a[i - 1] > 1) s += a[i];
	}
	cout << s;
}