#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int max,min,s=0;
	int a;
	cin>>a;
	max=min=a;
	for(int i=2;i<=n;i++){
		cin>>a;
		if(max<a)s++,max=a;
		if(min>a)s++,min=a;
	}
	cout<<s;
}