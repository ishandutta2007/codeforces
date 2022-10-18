#include <bits/stdc++.h>
#define ll long long
int main(){
	ll n,p,w,d;
	std::cin>>n>>p>>w>>d;
	ll min=p/w;
	for (ll win=min;win>=0&&min-win<=120005;win--){
		ll np=p-win*w;
		if (np%d==0&&np/d+win<=n){std::cout<<win<<" "<<np/d<<" "<<n-win-np/d<<std::endl;return 0;}
	}printf("-1");
	
	return 0;
}