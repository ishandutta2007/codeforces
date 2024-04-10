#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
int n;
int a[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	int boss=1;
	for(int i=n; i>=2 ;i--){
		cout << "? ";
		for(int j=1; j<n ;j++) cout << i << ' ';
		cout << 1 << endl;
		int res;cin >> res;
		if(res!=0){
			if(boss==1) boss=i;
			a[res]=boss+1-i;
		}
	}
	for(int i=2; i<=n ;i++){
		cout << "? ";
		for(int j=1; j<n ;j++) cout << 1 << ' ';
		cout << i << endl;
		int res;cin >> res;
		if(res!=0){
			a[res]=boss+i-1;
		}
	}
	a[n]=boss;
	cout << "! ";
	for(int i=1; i<=n ;i++) cout << a[i] << ' ';
	cout << endl;
}