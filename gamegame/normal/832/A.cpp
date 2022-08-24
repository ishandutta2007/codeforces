#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	long long n,k;
	cin >> n >> k;
	if((n/k)%2==0) cout << "NO\n";
	else cout << "YES\n";
}