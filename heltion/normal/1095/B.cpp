#include<bits/stdc++.h>
using namespace std;
#define maxn 120000
int a[maxn];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> a[i];	
	sort(a, a + n);
	cout << min(a[n - 2] - a[0], a[n - 1] - a[1]);
}