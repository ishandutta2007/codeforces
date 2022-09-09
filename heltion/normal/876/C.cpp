#include<bits/stdc++.h>
using namespace std;
int jiaqilai(int n){
	int ret=0;
	while(n){
		ret+=n%10;
		n/=10;
	}
	return ret;
}
int main(){
	int n,k=0;
	cin>>n;
	for(int i=max(1,n-1000);i<=n;++i){
		if(i+jiaqilai(i)==n)++k;
	}
	cout<<k<<endl;
	for(int i=max(1,n-1000);i<=n;++i){
		if(i+jiaqilai(i)==n)cout<<i<<endl;;
	}
}