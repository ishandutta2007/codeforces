#include<iostream>
using namespace std;
long long int n;
bool ok(int i){
	return (i>0 && i<=n);
}
int main(){
	long long int d,a,b,c,ans=0,tar;
	cin >> n >> a >> b >> c >> d;
	for(int i=1; i<=n ;i++){
		tar=a+b+i;
		if(ok(tar-a-c) && ok(tar-b-d) && ok(tar-d-c)){
			ans+=n;
		}
	}
	cout << ans << endl;
}