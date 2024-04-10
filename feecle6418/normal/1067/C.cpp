#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int main(){
	cin>>n;
	if(n<=10){
		for(int i=1;i<=n;i++)cout<<1<<' '<<i<<'\n';
		return 0;
	}
	//3+2+4+...
	int u=3,lst=3;
	cout<<"1 4\n2 3\n3 2\n";
	for(int i=1;i<=(n-5)/3;i++){
		cout<<(i*2+2)<<' '<<1<<'\n';
		cout<<(i*2+2)<<' '<<3<<'\n';
		cout<<(i*2+3)<<' '<<2<<'\n';
		lst=i*2+3;
		u+=3;
	}
	cout<<lst+1<<' '<<3<<'\n';
	cout<<lst+2<<' '<<4<<'\n';
	u+=2,u=n-u;
	while(u){
		cout<<234444-u<<' '<<234444-u<<'\n';
		u--;
	}
}