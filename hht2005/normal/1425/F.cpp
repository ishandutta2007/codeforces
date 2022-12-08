#include<bits/stdc++.h>
using namespace std;
int f[1010];
int main() {
	int n,las,now,V12,V23;
	cin>>n;
	cout<<"? "<<1<<' '<<2<<endl;
	cin>>las;
	V12=las;
	for(int i=3;i<=n;i++) {
		cout<<"? "<<1<<' '<<i<<endl;
		cin>>now;
		f[i]=now-las;
		las=now;
	}
	cout<<"? "<<2<<' '<<3<<endl;
	cin>>V23;
	f[2]=V23-f[3];
	f[1]=V12-f[2];
	cout<<"!";
	for(int i=1;i<=n;i++)
		cout<<' '<<f[i];
	cout<<endl;
	return 0;
}