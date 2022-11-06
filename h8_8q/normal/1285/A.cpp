#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

int n,l,r; 

int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		char c;
		cin>>c;
		if(c=='L')l++;
		else r++;
	}
	printf("%d",l+r+1);
	return 0;
}