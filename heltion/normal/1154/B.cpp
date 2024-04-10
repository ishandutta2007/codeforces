#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void no(const char *s = "NO"){cout << s;exit(0);} 
constexpr int maxn = 120;
int a[maxn];
int main(){
	ios::sync_with_stdio(false); 
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> a[i];
	sort(a, a + n);
	n = unique(a, a + n) - a;
	if(n > 3) no("-1");
	if(n == 1) no("0");
	if(n == 2){
		if((a[0] + a[1]) & 1) cout << a[1] - a[0];
		else cout << (a[1] - a[0]) / 2;
	}
	else{
		if(a[1] - a[0] == a[2] - a[1]) cout << a[1] - a[0];
		else no("-1");
	}
}