#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
multiset<int> s;
int n,a[505];
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main()
{
	n=read();
	for(int i=1;i<=n*n;++i) s.insert(read());
	for(int i=1;i<=n;++i)
	{
		set<int>::iterator it=s.end();--it;
		a[i]=*it;s.erase(it);printf("%d ",a[i]);
		for(int j=1,k;j<i;++j) k=gcd(a[i],a[j]),s.erase(s.find(k)),s.erase(s.find(k));	
	}
	return 0;
}