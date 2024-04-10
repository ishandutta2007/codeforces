#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int b,k;
int main(){
	ios::sync_with_stdio(false);
	cin >> b >> k;
	int ans=0;
	for(int i=k-1; i>=0 ;i--){
		int a;cin >> a;
		if(i==0 || b%2!=0) ans+=a;
	}
	if(ans%2) cout << "odd\n";
	else cout << "even\n";
}