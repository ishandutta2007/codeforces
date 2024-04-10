#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,p,q;
	string crap;
	cin >> n;
	bool ans=false;
	for(int i=1; i<=n ;i++){
		cin >> crap >> p >> q;
		if(p<q && p>=2400){
			ans=true;
			break;
		}
	}
	if(ans) cout << "YES\n";
	else cout << "NO\n";
}