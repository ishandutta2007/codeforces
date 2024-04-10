#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;

int arr[100020];

void Main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){ cin >> arr[i]; }
	int ptr = 1, ans = 0;
	while (ptr <= n){
		int st = ptr, ed = ptr+1;
		while (ed <= n){
			if (arr[ed-1] <= arr[ed]){ ed += 1; }
			else{ break; }
		}
		ans = max(ans, ed-st);
		ptr = ed;
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}