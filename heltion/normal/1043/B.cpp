#include<bits/stdc++.h>
#define maxn 1200
using namespace std;
vector<int> v;
int a[maxn], d[maxn], n;
bool test(int k){
	for(int i = k + 1; i <= n; i += 1)
		if(d[i] != d[i - k]) return false;
	return true;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		d[i] = a[i] - a[i - 1];
	}
	for(int k = 1; k <= n; k += 1)
		if(test(k)) v.push_back(k);
	cout << v.size() << endl;
	for(int x: v) cout << x << " ";
}