#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
int main(){
	int n, a, m = 0;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a;
		if(a > m){
			cout << i;
			return 0;
		}
		if(a == m) m += 1;
	}
	printf("-1");
}