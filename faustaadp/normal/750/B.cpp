#include<bits/stdc++.h>
using namespace std;
long long nm,i,k,nn,t,a;
string ss,s,n,e,w;
bool b;
int main()
{
	cin>>nm;
	b=1;
	s="South";
	n="North";
	e="East";
	w="West";
	t=20000;
	for(i=1;i<=nm;i++)
	{
		cin>>a>>ss;
		//a=a%40000;
		if((t==20000&&ss!=s)||(t==0&&ss!=n)||(t<0)||(t>20000))
			b=0;
		else
		{
			if(ss==s)
			{
				t=t-a;	
			}
			else if(ss==n)
			{
				t=t+a;
			}
		}
//		cout<<t<<endl;
	}
	if(b==1&&t==20000)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}