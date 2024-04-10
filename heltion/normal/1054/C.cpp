#include<bits/stdc++.h>
#define maxn 1200
using namespace std;
int l[maxn], r[maxn], ans[maxn];
int s[maxn], t[maxn];
bool vis[maxn];
void no(){
	cout << "NO";
	exit(0);
}
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> l[i];
	for(int i = 1; i <= n; i += 1) cin >> r[i];
	int a = n;
	while(true){
		int tot = 0, v = 0;
		for(int i = 1; i <= n; i += 1){
			s[i] = t[i] = 0;
			if(l[i] == 0 && r[i] == 0){
				tot += 1;
				if(vis[i] == false){
					v += 1;
					s[i] = t[i] = 1;
					ans[i] = a;
					vis[i] = true;
				}
			}
		}
		if(tot == n) break;
		if(v == 0) no();
		for(int i = 1; i <= n; i += 1) s[i] += s[i - 1];
		for(int i = n; i >= 1; i -= 1) t[i] += t[i + 1];
		for(int i = 1; i <= n; i += 1) if(vis[i] == false){
			l[i] -= s[i];
			r[i] -= t[i];
			if(l[i] < 0 || r[i] < 0) no();
		}
		a -= 1;
	}
	cout << "YES\n";
	for(int i = 1; i <= n; i += 1) cout << ans[i] << " ";
}