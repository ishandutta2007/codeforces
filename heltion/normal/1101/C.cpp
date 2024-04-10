#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 120000
pair<int, int> p[maxn];
int a[maxn], t[maxn];
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		bool ok = false;
		for(int i = 0; i < n; i += 1) cin >> p[i].first >> p[i].second, a[i] = i;
		sort(a, a + n, [&](const int &x, const int &y){return p[x] < p[y];});\
		int m = p[a[0]].second;
		for(int i = 1; i < n; i += 1){
			if(m < p[a[i]].first){
					for(int j = 0; j < n; j += 1) t[a[j]] = j < i ? 2 : 1;
					for(int j = 0; j < n; j += 1) cout << t[j] << " ";
					ok = true;
					break;
				}
			m = max(p[a[i]].second, m);
		}
		if(ok == false ) cout << -1;
		cout << endl;
	}
}