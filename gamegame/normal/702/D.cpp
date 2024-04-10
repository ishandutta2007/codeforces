#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	long long d,k,a,b,t;
	cin >> d >> k >> a >> b >> t;
	if(d<=k) cout << a*d << endl;
	else if(a*k+t>b*k) cout << a*k+b*(d-k) << endl;
	else{
		long long t1=(d-1)/k;
		cout << min(a*d+(d-1)/k*t,a*t1*k+b*(d-t1*k)+t*(t1-1)) << endl;
	}
}