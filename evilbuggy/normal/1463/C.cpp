#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long> t(n), x(n);
		for(int i = 0; i < n; i++){
			cin >> t[i] >> x[i];
		}
		t.push_back((long long)1e14 + 5);
		long long timer = 0, posst = 0, posen = 0, ans = 0;
		for(int i = 0; i < n; i++){
			if(t[i] < timer + abs(posen - posst)){
				if(posst <= x[i] && x[i] <= posen){
					long long tm = timer + x[i] - posst;
					if(t[i] <= tm && tm <= t[i + 1]){
						ans++;
					}
				}else if(posst >= x[i] && x[i] >= posen){
					long long tm = timer + posst - x[i];
					if(t[i] <= tm && tm <= t[i + 1]){
						ans++;
					}
				}
			}else{
				if(t[i] + abs(x[i] - posen) <= t[i + 1]){
					ans++;
				}
				timer = t[i];
				posst = posen;
				posen = x[i];
			}
		}
		cout << ans << '\n';
	}

	return 0;
}