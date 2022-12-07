#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
int x,n;
int main()
{
	cin>>n;
	while(n--)
	{
		char s[4];
		scanf("%s",&s);
		for(int i=0;i<strlen(s);i++)
		{
			if(s[i]=='-')x--;
			if(s[i]=='+')x++;
		}
	}
	cout<<x/2<<endl;
	return 0;
}