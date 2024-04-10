#include<bits/stdc++.h>
using namespace std;
#define maxn 31
int a[maxn];
void no(){
	cout << "NO";
	exit(0);
}
int main(){
	int n, k;
	cin >> n >> k;
	if(k > n) no();
	for(int i = 0; i < maxn; i += 1) if((1 << i) & n) k -= a[i] = 1;
	if(k < 0) no();
	for(int i = 30; i; i -= 1){
		int h = min(k, a[i]);
		a[i - 1] += h * 2;
		a[i] -= h;
		k -= h;
	}
	cout << "YES" << endl;
	for(int i = 0; i <= maxn; i += 1)
		for(int j = 0; j < a[i]; j += 1) cout << (1 << i) << " ";
}