#include<bits/stdc++.h>
using namespace std;
void work(string s){
	int a=stoi(s.substr(0,2));
	int b=stoi(s.substr(3,2));
	a%=12;
	double y=6*b;
	double x=30*a+b*0.5;
	cout<<x<<" "<<y<<endl;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	string s;
	while(cin>>s)work(s);
}