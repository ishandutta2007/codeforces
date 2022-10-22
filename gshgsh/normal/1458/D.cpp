#include<iostream>
#include<string>
#include<cstdio>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N;string a;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a;N=a.length();map<int,int>l,r;int now=0;For(i,0,N-1)a[i]=='1'?r[now++]++:l[now--]++;
		now=0;while(l[now]||r[now])(l[now]&&r[now-1])||(!r[now]&&!l[now+1])?cout<<0,l[now--]--:(cout<<1,r[now++]--);cout<<endl;
	}
	return 0;
}