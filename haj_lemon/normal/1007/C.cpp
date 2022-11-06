#include<bits/stdc++.h>
using namespace std;
long long n,a,b,x=1,y=1,no=1;
int main(){
	cin>>n;
	while (no){
		cout<<a+x<<' '<<b+y<<endl;
		fflush(stdout);
		cin>>no;
		if (no==1){a+=x;x=min(x*2,n-a);}
		if (no==2){b+=y;y=min(y*2,n-b);}
		if (no==3){x=max(1ll,x/2);y=max(1ll,y/2);}
	}
	return 0;
}