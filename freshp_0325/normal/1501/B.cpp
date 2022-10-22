#include<bits/stdc++.h>
using namespace std;
int a[200005],n,T;
int main(){
	cin>>T;
	while(T-->0)
	{
		cin>>n;
		for(int i=1;i<=n;++i)	cin>>a[i];
		a[n+1]=0;
		for(int i=n;i;--i)	a[i]=max(a[i],a[i+1]-1);
		for(int i=1;i<=n;++i)	cout<<(a[i]?1:0)<<' ';
		cout<<endl;
	}
	return 0;
}