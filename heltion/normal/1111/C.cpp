#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxk 120000
int a[maxk], k;
map<int, int> mp;
LL A, B;
LL n(int L, int R){
	int p = lower_bound(a, a + k, L) - a, q = lower_bound(a, a + k, R) - a;
	int ret = q - p + mp[R];
	//cout << L << " " << R << " " << ret<< endl; 
	return ret;
}
LL f(int L, int R){
	LL nn = n(L, R);
	if(nn == 0) return A;
	LL ret = nn * B * (R - L + 1);
	if(L < R){
		int M = L + (R - L) / 2;
		ret = min(ret, f(L, M) + f(M + 1, R));
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	LL n;
	cin >> n >> k >> A >> B;
	for(int i = 0; i < k; i += 1){
		cin >> a[i];
		mp[a[i]] += 1;
	}
	sort(a, a + k);
	cout << f(1, 1 << n);
}