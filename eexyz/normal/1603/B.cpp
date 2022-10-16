#include<bits/stdc++.h>
using namespace std;
int x,y,i,T,gg;
int main(){
	cin>>T;
	while(T--){
		cin>>x>>y;
		if(x>y){cout<<x+y<<"\n";continue;}
		if(y%x==0){cout<<x<<"\n";continue;}
		gg=(y-(y%x)/2);
		cout<<gg<<"\n";
	}
}