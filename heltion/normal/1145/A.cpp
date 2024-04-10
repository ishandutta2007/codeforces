#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 16;
int a[maxn];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> a[i];
	int ans = 0;
	for(int L = 1; L <= n; L *= 2)
		for(int i = 0; i + L <= n; i += L){
			bool ok = true;
			for(int j = i + 1; j < i + L; j += 1) if(a[j] < a[j - 1]) ok = false;
			if(ok) ans = max(ans, L);	
		}
	cout << ans;
}