#include<bits/stdc++.h>
using namespace std;
int n,i,tmm,tmmm;
string s,s1,s2;
bool b;
int main()
{
	b=1;
	cin>>n;
	cin>>s;
	while(b==1)
	{
		if(s.find("ogo")>=n)
			break;
		else
		{
			tmm=s.find("ogo");
			tmmm=tmm;
			i=1;
			while(1+1==2)
			{
				if(s[tmm+1]=='g'&&s[tmm+2]=='o')
				{
					i=i+2;
					tmm=tmm+2;
				}
				else
				break;
			}
		//	cout<<i<<endl;			
			s.replace(tmmm,i,"***");
		//	cout<<s<<endl;
			n=n-i+3;
		}
	}
	cout<<s<<endl;
}