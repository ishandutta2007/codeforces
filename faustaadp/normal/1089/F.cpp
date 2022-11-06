#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int n;
	cin >> n;
	int tmp = n;
	int a = 0, b = 0;
	for (int i = 2; i <= sqrt(tmp); i++) {
		while(n % i == 0) {
			n /= i;
			if (a == 0) a = i; else
			if (b == 0 && a != i) b = i;
		}
	}
	
	if (n != 1) b = n;
	//8
	if (b == 0||a==0) cout << "NO\n"; 
	else {
		n=tmp;
		cout << "YES\n";
		cout<<"2\n";
		ll X=n/a;
		ll Y=n/b;
		for(ll i=b;i<=n;i+=b)
		{
			if((n-i-1)%a==0)
			{
				cout<<i/b<<" "<<Y<<"\n";
				cout<<(n-i)/a<<" "<<X<<"\n";
				return 0;
			}
		}
		//cout << a << ' ' << X << endl;
		//cout << b << ' ' << Y << endl;
	}
}