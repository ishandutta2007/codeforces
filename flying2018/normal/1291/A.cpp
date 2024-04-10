#include<iostream>
#include<cstdio>
#include<cstring>
#define N 3010
using namespace std;
char str[N];
bool get_[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",str+1);
		while(n && (str[n]-'0')%2==0) --n;
		if(!n){puts("-1");continue;}
		int sum=0,all=n;
		for(int i=1;i<=n;i++) sum+=str[i]-'0',get_[i]=true;
		if(sum%2==0){for(int i=1;i<=n;i++) putchar(str[i]);puts("");continue;}
		bool can=false;
		for(int i=2;i<=n;i++)
		if((str[i]-'0')==0) get_[i]=false,all--;
		for(int i=1;!can && i<n;i++)
		if((str[i]-'0')%2) get_[i]=false,all--,can=true;
		if(can && all){for(int i=1;i<=n;i++)if(get_[i])putchar(str[i]);puts("");continue;}
		else{puts("-1");continue;}
	}
	return 0;
}