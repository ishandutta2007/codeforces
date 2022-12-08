#include<bits/stdc++.h>
using namespace std;
int main() {
	long long a,b,c,t,k;
	cin>>a>>b>>c;
	cout<<"First"<<endl;
	cout<<int(1e9)<<endl;
	cin>>t;
	if(t==1)a+=1e9,cout<<(k=2ll*a-b-c)<<endl;
	if(t==2)b+=1e9,cout<<(k=2ll*b-a-c)<<endl;
	if(t==3)c+=1e9,cout<<(k=2ll*c-a-b)<<endl;
	cin>>t;
	if(t==1)a+=k;
	if(t==2)b+=k;
	if(t==3)c+=k;
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
	if(a>b)swap(a,b);
	cout<<b-a<<endl;
	return 0;
}