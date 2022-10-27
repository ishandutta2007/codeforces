#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 2e5 + 25;
int p[N], le_inc[N], le_dec[N], ri_inc[N], ri_dec[N], le_mx[N], ri_mx[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	le_inc[0] = le_dec[0] = 0;
	for(int i = 1; i <= n; i++){
		le_inc[i] = le_dec[i] = 1;
		if(p[i - 1] > p[i])le_inc[i] += le_inc[i - 1];
		else le_dec[i] += le_dec[i - 1];
	}
	ri_inc[n + 1] = ri_dec[n + 1] = 0;
	for(int i = n; i >= 1; i--){
		ri_inc[i] = ri_dec[i] = 1;
		if(p[i] < p[i + 1])ri_inc[i] += ri_inc[i + 1];
		else ri_dec[i] += ri_dec[i + 1];
	}
	le_mx[0] = 0;
	for(int i = 1; i <= n; i++){
		le_mx[i] = max({le_mx[i - 1], le_inc[i], ri_inc[i]});
	}
	ri_mx[n + 1] = 0;
	for(int i = n; i >= 1; i--){
		ri_mx[i] = max({ri_mx[i + 1], le_inc[i], ri_inc[i]});
	}
	int ans = 0;
	for(int i = 2; i < n; i++){
		if(p[i - 1] > p[i] || p[i] < p[i + 1])continue;
		if(le_dec[i] == ri_dec[i] && (le_dec[i]&1)){
			int mxlen = max({le_mx[i - le_dec[i]], ri_mx[i + ri_dec[i]], le_inc[i - le_dec[i] + 1], ri_inc[i + ri_dec[i] - 1]});
			if(mxlen < le_dec[i])ans++;
		}
	}
	cout << ans << '\n';


	return 0;
}