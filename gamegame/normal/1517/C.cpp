#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n;
int a[501][501];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;
		a[i][i]=x;
	}
	for(int i=2; i<=n ;i++){
		int mn=1;
		for(int j=1; i-1+j<=n+1 ;j++){
			if(a[i+j-2][j]<a[i+mn-2][mn]) mn=j;
		}
		//cout << mn << endl;
		for(int j=1; i+j<=n+1 ;j++){
			if(j<mn) a[i+j-1][j]=a[i+j-2][j];
			else a[i+j-1][j]=a[i+j-1][j+1];
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=i ;j++){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}