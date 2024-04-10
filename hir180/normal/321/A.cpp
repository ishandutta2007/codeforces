#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int n,m;
	string str;
	cin >> n >> m >> str;
	if(!n&&!m){ puts("Yes"); return 0;}
	int f=0,s=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='U') s++;
		if(str[i]=='D') s--;
		if(str[i]=='L') f--;
		if(str[i]=='R') f++;
	}
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='U') m--;
		if(str[i]=='D') m++;
		if(str[i]=='L') n++;
		if(str[i]=='R') n--;
		int ok1=-1,ok2=-1;
		if(!f && !n) ok1=2000000000;
		if(f && n%f==0) ok1=n/f;
		if(!s && !m) ok2=2000000000;
		if(s && m%s==0) ok2=m/s;
		if((ok1==2000000000 && ok2>=0) || (ok2==2000000000 && ok1>=0) || (ok1!=-1 && ok2!=-1 && ok1==ok2 && ok1>=0)){ puts("Yes"); return 0;}
	}
	puts("No");
}