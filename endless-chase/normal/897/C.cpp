#include<iostream>
#include<string>
using namespace std;
long long n,q,k,t,sz[111111],tt;
string s,ss,sss,ssss,s5;
char doit(long long n,long long k)
{
	if (n==0)
	{
		if (k>s5.size()) return '.';
		return s5[k-1];
	}
	if (k<=t) return s[k-1];
	if (k>t && k-t<=sz[n-1]) 
	{
		char c=doit(n-1,k-t);
		if (c!='.') return c;
	}
	k-=(t+sz[n-1]);
	if (k<=ssss.size()) return ssss[k-1];
	k-=ssss.size();
	if (k<=sz[n-1])
	{
		char c=doit(n-1,k);
		if (c!='.') return c;
	}
	k-=sz[n-1];
	if (k==1) return '\"';
	if (k==2) return '?';
	return '.';
}
int main()
{
	s="What are you doing while sending ";
	s+="\"";
	ss="What are you doing while sending ? Are you busy? Will you send ?";
	sss="What are you doing at the end of the world? Are you busy? Will you save us?";
	ssss="\"";
	ssss+="? Are you busy? Will you send ";
	ssss+="\"";
	s5="What are you doing at the end of the world? Are you busy? Will you save us?";
	tt=ss.size()+4;
	t=s.size();
	sz[0]=sss.size();
	for (int i=1;i<=100000;i++)
	{
		if (sz[i-1]*2+tt>2e18) sz[i]=2e18;
		else sz[i]=sz[i-1]*2+tt;
	}
	cin>>q;
	while(q--)
	{
		cin>>n>>k;
		cout<<doit(n,k);
	}
	return 0;
}