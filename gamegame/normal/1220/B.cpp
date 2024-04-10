#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[1001][1001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			cin >> a[i][j];
		}
	}
	ll a1=sqrt(a[1][2]*a[1][3]/a[2][3])+0.5;
	cout << a1 << ' ';
	for(int i=2; i<=n ;i++){
		cout << a[1][i]/a1 << ' ';
	}
}