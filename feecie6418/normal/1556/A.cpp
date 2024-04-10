#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		ll x,y;
		cin>>x>>y;
		if((x+y)&1)puts("-1");
		else if(x==0&&y==0)puts("0");
		else if(x==y)puts("1");
		else puts("2");
	}
}