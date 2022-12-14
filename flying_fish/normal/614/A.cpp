#include<bits/stdc++.h>
using namespace std;
long double l,r,k,i,h=1;
int flag=0;
int main(){
	cin>>l>>r>>k;
	for(i=1;h<=r;i++){
		if(h>=l&&h<=r){
			flag=1;
			cout<<(long long)h<<' ';
		}
		h*=k;
	}
	if(flag==0){
		cout<<-1;
	}
	return 0;
}