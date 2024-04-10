#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
auto no = [](){cout<<"No";exit(0);};
auto read = [](){LL x;cin>>x;return x;}; 
#define maxn 120000
vector<LL> v;
LL b[maxn];
int main(){
	ios::sync_with_stdio(false);
	LL n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i += 1) cin >> b[i];
	for(int i = 1; i < n; i += 1) v.push_back(b[i + 1] - b[i] - 1);
	sort(v.begin(), v.end(), greater<LL>());
	LL ans = b[n] - b[1] + 1;
	for(int i = 0; i + 1 < k; i += 1) ans -= v[i];
	cout << ans;
}