#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int last[N], chk[N], a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	memset(chk, 0, sizeof(chk));
	memset(last, 0, sizeof(last));
	for(int i = 1; i <= n; i++){
		last[a[i]] = i;
	}
	set<int> st;
	for(int i = 1; i <= n; i++){
		st.insert(last[a[i]]);
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		if(last[a[i]] == i){
			st.erase(i);
		}
		if(chk[a[i]])continue;
		chk[a[i]] = 1;

		ans += (int)st.size();
	}
	cout << ans << '\n';


	return 0;
}