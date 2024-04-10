#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	while(n>1) {
		cout<<n<<' ';
		int s=2;
		while(n%s)s++;
		n/=s;
	}
	cout<<"1";
	return 0;
}