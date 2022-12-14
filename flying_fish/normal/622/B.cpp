
#include <bits/stdc++.h>
using namespace std;
int a,b,d;char c;
int main(){
	cin>>a>>c>>b>>d;
	if(b+d>=60){b+=d;a+=b/60;b%=60;if(a>=24)a%=24;}
	else{b+=d;a+=b/60;}
	if(a<10){if(b<10){cout<<"0"<<a<<":"<<"0"<<b;}else {cout<<"0"<<a<<":"<<b;}}
	else{if(b<10){cout<<a<<":"<<"0"<<b;}else {cout<<a<<":"<<b;}}
	return 0;
}