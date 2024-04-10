#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int l,r,u,d,n;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	cout << "YES\n";
	for(int i=1; i<=n ;i++){
		cin >> l >> u >> r >> d;
		cout << (l&1)*2+(u&1)+1 << endl;
	}
}