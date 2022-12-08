#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,a,b,c;
	cin>>T;
	while(T--) {
		cin>>a>>b>>c;
		if((a+2ll*b+3ll*c)%2==0)puts("0");
		else puts("1");
	}
}