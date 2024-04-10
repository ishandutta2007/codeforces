#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, h, a, b, k;
	cin >> n >> h >> a >> b >> k;
	
	for(int i = 0; i < k; i++){
		int ta, fa;
		int tb, fb;
		cin >> ta >> fa;
		cin >> tb >> fb;
		if(ta == tb){
			cout << abs(fa - fb) << '\n';
			continue;
		}
		int ans = abs(ta - tb);
		if(max(fa, fb) < a){
			ans += 2*a - fa - fb;
		}else if(min(fa, fb) > b){
			ans += fa + fb - 2*b;
		}else{
			ans += abs(fb - fa);
		}

		cout << ans << '\n';
	}

	return 0;
}