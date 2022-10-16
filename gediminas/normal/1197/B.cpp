#include <bits/stdc++.h>

using namespace std;
/*input
4
1 3 4 2

*/
/*input
3
3 1 2

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
		int n;
		cin >> n;
		vector<long long> a(n);

		for (auto &&i : a) {
			cin >> i;
		}

		bool did = true;
		for (int i = 1; i < n; ++i) {
			if(a[i-1] < a[i]){
				if(!did){
					cout << "NO";
					exit(0);
				}
			}else{
				did = false;
			}
		}
		cout << "YES";
}