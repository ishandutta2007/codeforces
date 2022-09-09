#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int maxn = 320000;
void no(){ cout << "NO"; exit(0); }
LL a[maxn]; 
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	LL sum = 0;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + n + 1, greater<LL>());
	int m;
	cin >> m;
	while(m --){
		int q;
		cin >> q;
		cout << sum - a[q] << endl;
	}
}