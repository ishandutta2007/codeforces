#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	cin>>t;
	while(t--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a==c||b==d)cout<<abs(a-c)+abs(b-d)<<endl;
		else cout<<abs(a-c)+abs(b-d)+2<<endl;
	}
	return 0;
}