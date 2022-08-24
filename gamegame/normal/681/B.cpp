#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	int a[4]={0,1234567,123456,1234};
	cin >> n;
	bool ok=false;
	for(int i=0; i<=n/a[1] ;i++){
		for(int j=0; j<=(n-i*a[1])/a[2] ;j++){
			if((n-i*a[1]-j*a[2])%1234==0){
				ok=true;
			}
		}
	}
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}