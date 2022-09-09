#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
const int MAXN = 1e5 + 5;
using namespace std;

char s[MAXN];

string a,b;

int main(void)
{
	scanf("%s",s);
	int n = strlen(s);
	
	a='"'; b='"';
	for(int i=0; i<n; ++i)
	{	
		bool flag=1;
		if(s[i]!='0')
			for(int j=i; s[j]!=',' && s[j]!=';' && j<n; ++j)
			{
				if(s[j]<'0' || s[j]>'9')
				{
					flag=0;
					break;
				}
			}
		else flag = s[i+1]==';' || s[i+1]==',' || i+1==n;
		if(s[i]==';' || s[i]==',') flag=0;
		
		if(flag)
		{
			for(; s[i]!=',' && s[i]!=';' && i<n; ++i) a+=s[i];
			a+=',';
		}
		else
		{
			for(; s[i]!=',' && s[i]!=';' && i<n; ++i) b+=s[i];
			b+=',';
		}
	}
	if(s[n-1]==';' || s[n-1]==',') b+=',';
	a[a.size()-1]=b[b.size()-1]='"';
	
	if(a.size()==1) a[0]='-';
	if(b.size()==1) b[0]='-';
	cout<<a<<endl<<b;
	return 0;
}