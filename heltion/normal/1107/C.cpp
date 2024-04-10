#include<bits/stdc++.h>
#define maxn 1200000
using namespace std;
typedef long long LL;
auto no = [](){cout << "NO"; exit(0);};
int a[maxn];
char s[maxn];
multiset<int, greater<int> > ms;
int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	cin >> s + 1;
	LL ans = 0;
	for(int i = 1; i <= n; i += 1){
		ms.insert(a[i]);
		if(s[i] != s[i + 1]){
			for(int j = 0; j < k and not ms.empty(); j += 1){
				ans += *ms.begin();
				ms.erase(ms.begin());
			}
			ms.clear();
		}
	}
	cout << ans;
}