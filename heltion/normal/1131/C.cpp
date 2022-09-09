#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 120
int a[maxn], b[maxn];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n; i += 1){
		if(i & 1) b[n - 1 - i / 2] = a[i];
		else b[i >> 1] = a[i];
	}
	for(int i = 0; i < n; i += 1) cout << b[i] << " ";
}