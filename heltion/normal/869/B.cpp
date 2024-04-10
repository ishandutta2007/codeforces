#include<iostream>
using namespace std;
int main(){
	long long a,b;
	cin>>a>>b;
	if(b-a>9)cout<<0;
	else{
		int ans=1;
		for(long long i=a+1;i<=b;++i){
			ans*=(i%10);
			ans%=10;
		}
		cout<<ans;
	}
}