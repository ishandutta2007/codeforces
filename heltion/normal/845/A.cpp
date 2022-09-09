#include<bits/stdc++.h>
using namespace std;
#define maxn 1200
int a[maxn];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < 2 * n; i += 1) cin >> a[i];
	sort(a, a + 2 * n);
	cout << (a[n] > a[n - 1] ? "YES" : "NO"); 
}