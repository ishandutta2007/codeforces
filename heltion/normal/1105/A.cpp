#include<bits/stdc++.h>
using namespace std;
#define maxn 1200
int a[maxn]; 
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	int ans = 1E9, anst = 0;
	for(int t = 1; t <= 100; t += 1){
		int pans = 0;
		for(int i = 1; i <= n; i += 1){
			if(a[i] < t) pans += t - 1 - a[i];
			else if(a[i] > t) pans += a[i] - t - 1;
		}
		if(pans < ans) ans = pans, anst = t;
	}
	cout << anst << " " << ans;
}