#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using pii = pair<int, int>;
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 200000;
int a[maxn];
int main(){
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1) scanf("%d", a + i);
	sort(a, a + n);
	for(int i = 0, j = 0; i < n; i += 1){
		while(j < n and a[j] <= a[i] + 5) j += 1;
		ans = max(ans, j - i);
	}
	printf("%d", ans);
}