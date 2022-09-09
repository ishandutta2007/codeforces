#include<bits/stdc++.h>
#define maxn 600000
using namespace std;
typedef long long LL;
void no(){cout << "NO"; exit(0);};
int a[maxn], b[maxn];
map<int, int> mp;
vector<int> ans;
int main(){
	ios::sync_with_stdio(false);
	int m, k, n, s;
	cin >> m >> k >> n >> s;
	for(int i = 1; i <= m; i += 1) cin >> a[i];
	for(int i = 1; i <= s; i += 1){
		cin >> b[i];
		mp[b[i]] += 1;
	}
	int f = mp.size();
	for(int p = 1, q = 1; p <= m; p += 1){
		while(q <= m and f){
			if(mp.count(a[q])){
				mp[a[q]] -= 1;
				if(mp[a[q]] == 0) f -= 1;
			}
			q += 1; 
		}
		//cout << p << " " << q  << endl;
		if(f) break;
		if((p - 1) / k + (m - q + 1) / k + 1 >= n){
			for(int i = 1; i <= (p - 1) % k; i += 1) ans.push_back(i);
			if(q - p > k){
				int x = q - p - k;
				for(int i = p; i <= q and x; i += 1)
					if(not mp.count(a[i]) or mp[a[i]] < 0){
						ans.push_back(i);
						if(mp.count(a[i])) mp[a[i]] += 1;
						x -= 1;
					}
			}
			cout << ans.size() << endl;
			for(int x : ans) cout << x << " ";
			return 0;
		}
		if(mp.count(a[p])){
			mp[a[p]] += 1;
			if(mp[a[p]] == 1) f += 1;
		}
	}
	cout << -1;
}