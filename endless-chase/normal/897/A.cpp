#include<iostream>
#include<string>
using namespace std; 
int n,m,l,r;
string s;
char c,ch;
int main()
{
	cin>>n>>m>>s;
	for (int i=1;i<=m;i++)
	{
		getchar();
		scanf("%d %d %c %c",&l,&r,&c,&ch);
		for (int j=l-1;j<=r-1;j++)
		{
			if (s[j]==c) s[j]=ch;
		}
	}
	cout<<s<<endl;
	return 0;
}