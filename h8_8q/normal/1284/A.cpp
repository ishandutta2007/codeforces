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

const int maxn=20;
int n,m,t,x;
string ss[maxn+5],tt[maxn+5];

int main()
{
	n=read();m=read();
	for(int i=0;i<n;++i)
		cin>>ss[i];
	for(int i=0;i<m;++i)
		cin>>tt[i];
	t=read();
	for(int i=1;i<=t;++i)
	{
		x=read()-1;
		cout<<ss[x%n]+tt[x%m]<<endl;
	}
	return 0;
}