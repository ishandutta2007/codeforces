#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int gcd(int a,int b) {return b==0 ? a : gcd(b,a%b);};

char str[200003]={0},a;
int cur=0;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	while(scanf("%c",&a)==1)
	{
		str[cur++]=a;
		while (cur>1&&str[cur-2]==str[cur-1]) cur-=2;
	}
	str[cur]='\0';
	printf("%s\n",str);
	return 0;
}