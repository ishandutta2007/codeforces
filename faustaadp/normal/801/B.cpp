#include<bits/stdc++.h>
using namespace std;
long long i;
bool b;
string s1,s2;
int main()
{
	cin>>s1>>s2;
	for(i=0;i<s1.length();i++)
	{
		if(s2[i]>s1[i])
			b=1;
	}
	if(b==0)
		cout<<s2<<endl;
	else
		cout<<-1<<endl;
}