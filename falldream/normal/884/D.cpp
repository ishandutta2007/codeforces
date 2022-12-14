#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
priority_queue<long long,vector<long long>,greater<long long> >q;
int n;long long ans=0;
int main()
{
	n=read();if(n%2==0) q.push(0);
	for(int i=1;i<=n;++i) q.push(read());
	while(q.size()>1)
	{
		long long tot=0;
		for(int j=1;j<=3;++j) tot+=q.top(),q.pop();
		ans+=tot;q.push(tot);	
	}
	printf("%lld\n",ans);
	return 0;
}