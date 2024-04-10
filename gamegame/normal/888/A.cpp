#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int n,m;
int a[200001],b[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	int ans=0;
	for(int i=2 ;i<n ;i++){
		if(a[i]>a[i-1] && a[i]>a[i+1]) ans++;
		else if(a[i]<a[i-1] && a[i]<a[i+1]) ans++;
	}
	cout << ans << endl;
}