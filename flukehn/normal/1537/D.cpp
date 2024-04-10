#include<bits/stdc++.h>
using namespace std;
const int N=2000+11;
int F(int n){
	int ans=!(n%2);
	while(n%4==0)n/=4;
	if(n==2)ans^=1;
	return ans;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int ans=F(n);
		puts(ans?"Alice":"Bob");
	}
}