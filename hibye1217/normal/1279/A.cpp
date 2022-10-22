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
		int r, g, b;
		cin >> r >> g >> b;
		if (r > g+b+1 || g > r+b+1 || b > r+g+1) cout << "No\n";
		else cout << "Yes\n";
	}
}