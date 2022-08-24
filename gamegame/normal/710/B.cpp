#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n+1];
	for(int i=1; i<=n ;i++) cin >> a[i];
	sort(a+1,a+n+1);
	cout << a[(n+1)/2];
}