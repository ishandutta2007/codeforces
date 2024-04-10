#include <bits/stdc++.h>
using namespace std;
int n,a[1005],b[1005],m,t[1005];
bool Judge(){
	m=0;
	for(int i=1;i<=n;i++)if((a[i]+b[i])%2)t[++m]=i;
	if(m!=0&&m!=n)return 1;
	if(m==n){
		for(int i=1;i<=n;i++)b[i]--;
	}//a+b 
	m=0;
	for(int i=1;i<=n;i++)if(a[i]%2)t[++m]=i;//ab 
	if(m!=0&&m!=n)return 1;
	if(m==n){
		for(int i=1;i<=n;i++)a[i]--,b[i]--;
	}
	for(int i=1;i<=n;i++)a[i]/=2,b[i]/=2;
	return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(!Judge());
	cout<<m<<'\n';
	for(int i=1;i<=m;i++)cout<<t[i]<<' ';
}