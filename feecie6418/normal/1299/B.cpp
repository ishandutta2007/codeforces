#include<bits/stdc++.h>
using namespace std;
int n,x[100005],y[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	if(n&1)return puts("No"),0;
	for(int i=1;i<=n/2;i++){
		if((x[i]+x[i+n/2])!=(x[1]+x[1+n/2]))return puts("No"),0;
		if((y[i]+y[i+n/2])!=(y[1]+y[1+n/2]))return puts("No"),0;
	}
	puts("Yes");
}