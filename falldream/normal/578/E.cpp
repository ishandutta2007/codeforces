#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<set>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[MN+5];int n,q[MN+5],a[MN+5],top,res,num1=0,num2=0,ne[MN+5];
set<int> s[2];
vector<int> v[4];

int Solve(int x)
{
	top=res=0;int p=0;
	for(int i=1;i<=n;++i) if(st[i]=='L') s[0].insert(i); else s[1].insert(i);
	while(top<n)
	{
		set<int>::iterator it=s[x].lower_bound(p);
		if(it==s[x].end()) ++res,p=0;
		else q[++top]=p=*it,s[x].erase(it),x^=1;
	}
	return res;
}
bool b[MN+5];
inline void Print(int x){for(;x;x=ne[x]) printf("%d ",x);}
int main()
{
	scanf("%s",st+1);n=strlen(st+1);
	for(int i=1;i<=n;++i) if(st[i]=='L') ++num1; else ++num2;
	if(num1==num2)
	{
		if(Solve(0)<Solve(1)) Solve(0); else Solve(1);
		printf("%d\n",res);
		for(int i=1;i<=n;++i) printf("%d ",q[i]);
	}
	else 
	{
		for(int i=1;i<=n;++i) a[i]=st[i]=='R';
		if(num1>num2) for(int i=1;i<=n;++i) a[i]^=1;
		for(int i=1;i<=n;++i) s[a[i]].insert(i); 
		for(int i=1;i<=n;++i) if(!b[i])
		{
			++res;s[a[i]].erase(s[a[i]].find(i));b[i]=1;
			int num=1,p=i,x=a[i]^1,last=i;
			set<int>::iterator it;
			while((it=s[x].lower_bound(p))!=s[x].end())
			{
				p=*it;s[x].erase(p);++num;
				ne[last]=p;last=p;b[p]=1;
				x^=1;	
			}
			v[a[i]*2+(num&1)].push_back(i);
		//	cout<<i<<" "<<num<<" "<<a[i]<<endl;
		}
		printf("%d\n",res-1);
		for(int i=0;i<v[2].size();++i) Print(v[2][i]);
		while(v[3].size()||v[1].size())
		{
			if(v[3].size()) Print(v[3][v[3].size()-1]),v[3].pop_back();
			if(v[1].size()) Print(v[1][v[1].size()-1]),v[1].pop_back();	
		}
		for(int i=0;i<v[0].size();++i) Print(v[0][i]);
	}
	return 0;
}