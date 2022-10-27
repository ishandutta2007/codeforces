#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int pd = -1, ph = -1, ans = 0;
	for(int i = 1; i <= m; i++){
		int d, h;
		cin >> d >> h;
		if(pd == -1){
			ans = max(ans, h + d - 1);
		}else{
			if(abs(ph - h) > d - pd){
				cout << "IMPOSSIBLE" << '\n';
				exit(0);
			}
			ans = max(ans, (h + ph + d - pd)/2);
		}
		pd = d;
		ph = h;
	}
	ans = max(ans, ph + n - pd);
	cout << ans << '\n';

	return 0;
}