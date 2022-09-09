#include<bits/stdc++.h>
#define maxn 120
using namespace std;
int a[maxn];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	a[n + 1] = 1001;
	int ms = 0, s = 1;
	for(int i = 1; i <= n + 1; i += 1, ms = max(ms, s))
		if(a[i] == a[i - 1] + 1) s += 1;
		else s = 1;
	cout << max(ms - 2, 0);
}