#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
auto read = [](){LL x; cin >> x; return x;};
auto no = [](){cout << "No"; exit(0);};
#define maxn 240000
LL a[maxn], so[maxn], se[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n = read();
	for(int i = 1; i <= n; i += 1) a[i] = read();
	for(int i = 1; i <= n; i += 1){
		so[i] = so[i - 1];
		se[i] = se[i - 1];
		if(i & 1) so[i] += a[i];
		else se[i] += a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i += 1)
		if(so[i - 1] + se[n] - se[i] == se[i - 1] + so[n] - so[i]) ans += 1;
	cout << ans;
}