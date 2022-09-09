#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 12;
int a[maxn];
void no(){
	cout << "NO";
	exit(0);
}
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i <= n; i += 1){
		for(int j = 1; j <= n - i; j += 1) if(abs(a[j] - a[j + 1]) > 1) no();
		int k = 0;
		for(int j = 1; j <= n - i + 1; j += 1) if(a[j] > a[k]) k = j;
		for(int j = k; j <= n - i; j += 1) a[j] = a[j + 1];
	}
	cout << "YES";
}