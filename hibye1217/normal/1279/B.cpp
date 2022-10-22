#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		int n, s;
		cin >> n >> s;
		int a[100020] = {0};
		ll sum=0, mx=0, mxp=0;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			if (sum <= s){
				if (mx < a[i]){
					mx = a[i];
					mxp = i;
				}
			}
			sum += a[i];
		}
		if (sum <= s) cout << "0\n";
		else cout << mxp << '\n';
	}
}