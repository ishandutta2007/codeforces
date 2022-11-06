#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
long long a=0;
int main()
{
	cin>>a;
	int num=0;
	bool jin=0;
	while(a)
	{
		if(!jin && (a%10==9)) num+=9;
		else if(a<10)
		{
			if(jin)num+=a-1;
			else num+=a;
		}
		else if(!jin)
		{
			jin=true;
			num+=(a%10+10);
		}
		else num+=(a%10+9);
		a/=10;
	}
	printf("%d",num);
	return 0;
}