#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[105];
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		cout<<"? ";
		for(int j=1;j<n;j++)cout<<"1 ";
		cout<<i<<endl;
		int x;
		cin>>x;
		if(x==0){
			a[n]=n+2-i;
			break;
		}
	}
	if(!a[n])a[n]=1;
	for(int i=1;i<a[n];i++){
		cout<<"? ";
		for(int j=1;j<n;j++)cout<<i+1<<' ';
		cout<<1<<endl;
		int x;
		cin>>x;
		a[x]=a[n]-i;
	}
	for(int i=1;i<=n-a[n];i++){
		cout<<"? ";
		for(int j=1;j<n;j++)cout<<"1 ";
		cout<<i+1<<endl;
		int x;
		cin>>x;
		a[x]=a[n]+i;
	}
	cout<<"! ";
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<endl;
}