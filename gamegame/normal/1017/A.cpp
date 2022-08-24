#include<iostream>
using namespace std;
int main(){
	int n;
	int ans=1;
	int a,b,c,d;
	cin >> n;
	cin >> a >> b >> c >> d;
	int sum=a+b+c+d;
	for(int i=2; i<=n ;i++){
		cin >> a >> b >> c >> d;
		if(a+b+c+d>sum) ans++;
	}
	cout << ans << endl;
}