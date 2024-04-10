#include<iostream>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<queue>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,kind[MN+5],mark[MN*10+5],num=0,tot=0,T=MN+1;
queue<string> q1,q2;
queue<int> s1,s2,a1,a2;
string st[MN+5],ans[MN*5+5][2];

int Check(int x)
{
	int t=st[x].length(),res=0;
	if(st[x][0]=='0') return -1;
	for(int i=0;i<t;++i)
		if(st[x][i]<'0'||st[x][i]>'9') return -1;
		else res=res*10+(char)st[x][i]-'0';
	mark[res]=1;
	if(res<=0||res>n) return -1;
	else return res;
}

int solve()
{
	while(mark[T]) ++T;
	return T;	
}

void Add(string a,string b)
{
	++num;
	ans[num][0]=a;
	ans[num][1]=b;	
}

string Format(int t)
{
	stringstream stream;  
    stream<<t;return stream.str();	
}

int main()
{
	n=read();int flag=0,F=0;string ff;
	for(int i=1;i<=n;++i) 
		cin>>st[i],tot+=(kind[i]=read());
	for(int i=1;i<=n;++i)
	{
		int K=Check(i);flag|=(K==-1);
		if(K==-1)
		{
			if(kind[i]) q1.push(st[i]);
			else q2.push(st[i]);
			continue;	
		}
		if(K<=tot&&kind[i]) continue;
		if(K>tot&&!kind[i]) continue;
		if(!F&&kind[i]) F=i;
		if(kind[i]) a1.push(i); else a2.push(i);	
	}
	for(int i=1;i<=n;++i) if(!mark[i]) 
		if(i<=tot) s1.push(i); else s2.push(i);
	if(!flag)
	{
		if(!F)return 0*puts("0");
		int t=solve();ff=Format(t);
    	Add(st[F],ff);s2.push(Check(F));
		st[F]=ff;a1.pop();
	}
	//return 0;
	while(a1.size()||a2.size())
	{
		while(a1.size()&&s1.size())
		{
			int x=a1.front(),y=s1.front();
		//	cout<<x<<"->"<<y<<endl;
			a1.pop();s1.pop();
			Add(st[x],Format(y));s2.push(Check(x));
		}
		while(a2.size()&&s2.size())
		{
			int x=a2.front(),y=s2.front();
		//	cout<<x<<"->"<<y<<endl;
			a2.pop();s2.pop();	
			Add(st[x],Format(y));s1.push(Check(x));
		}
	}
//	return 0;
	while(q1.size())
		Add(q1.front(),Format(s1.front())),s1.pop(),q1.pop();	
	while(q2.size())
		Add(q2.front(),Format(s2.front())),s2.pop(),q2.pop();
	if(!flag)
	{
		int x=s1.front();s1.pop();
		Add(ff,Format(x));	
	}
	cout<<num<<endl;
	for(int i=1;i<=num;++i)
		cout<<"move "<<ans[i][0]<<" "<<ans[i][1]<<endl;
	return 0;
}