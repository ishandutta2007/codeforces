#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using pii = pair<int, int>;
void no(){cout << "NO"; exit(0);}
constexpr int maxk = 100;
int c[maxk];
int main(){
	int n, k, ans = 0;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i += 1){
		int d;
		scanf("%d", &d);
		c[d % k] += 1;
	}
	for(int i = 0; i <= k / 2; i += 1) if(i == 0 or 2 * i == k) ans += c[i] / 2;
	else ans += min(c[i], c[k - i]);
	printf("%d", ans << 1);
}