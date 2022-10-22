#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

pi2 arr[3020][3020];

void Main(){
	int t; cin >> t;
	while (t--){
		int sl; string s; cin >> sl >> s;
		for (int i = 0; i < sl; i++){
			arr[i][i] = { s[i]=='+' ? 1 : -1, 0 };
			bool flg = 1;
			for (int j = i+1; j < sl; j++){
				arr[i][j] = arr[i][j-1];
				arr[i][j].fr += s[j]=='+' ? 1 : -1;
				if (s[j-1] == '-' && s[j] == '-'){
					if (flg){ arr[i][j].sc += 1; flg = 0; }
					else{ flg = 1; }
				}
				if (s[j] == '+'){ flg = 1; }
			}
		}
		int ans = 0;
		for (int i = 0; i < sl; i++){
			for (int j = i; j < sl; j++){
				int sum = arr[i][j].fr, num = arr[i][j].sc;
				if (sum % 3 == 0){
					int cnt = -sum / 3;
					if (cnt >= 0 && cnt <= num){ ans += 1; }
					//cout << "RES " << i << ' ' << j << " -> " << sum << ' ' << num << "   " << cnt << " / " << ans << endl << flush;
				}
			}
		}
		cout << ans << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}