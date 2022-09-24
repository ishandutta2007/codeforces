#include<bits/stdc++.h>
using namespace std;
long long ll,rr,ww;
int main(){
	cin>>ll>>rr>>ww;
	if(ww==1){
		if(ll>1)puts("-1");
		else puts("1");
		return 0;
	}
	long double l=ll,r=rr,w=ww,s=1;
	bool flag=0;
	while(s<=r){
		if(s>=l)cout<<(long long)s<<' ',flag=1;
		s*=w;
	}
	if(!flag)puts("-1");
	return 0;
}