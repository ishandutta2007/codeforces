#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define maxn 105
using namespace std;
char inp[300];

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	scanf("%s",inp);
	int maxlen=0;
	int nowlen=0;
	bool flag=false;
	int sum=0;
	for(int i=0;i<strlen(inp);i++)
	{
		if(inp[i]=='(' || inp[i]==')' || inp[i]=='_')
			if(!flag) maxlen=max(maxlen,nowlen),nowlen=0;
			else if(nowlen) sum++,nowlen=0;
			
		if(inp[i]=='(') flag=true,nowlen=0;
		
		if(inp[i]!='(' && inp[i]!=')' &&inp[i]!='_') 
		{
			nowlen++;
			if(i==n-1) maxlen=max(maxlen,nowlen);
		}

		if(inp[i]==')') flag=false;
	} 
	printf("%d %d\n",maxlen,sum);
	return 0;
}