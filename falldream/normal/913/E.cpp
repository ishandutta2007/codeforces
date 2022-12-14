#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define MN 512
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
string f[MN+5][3];
const int Xpre=16+32+64+128,
	      Ypre=4+8+64+128,
	      Zpre=2+8+32+128;
const int n=512;
inline bool smaller(const string&a,const string&b)
{
	if(a.length()==b.length()) return a<b;
	else return a.length()<b.length();
}
struct data{string s;int x,k;
	bool operator <(const data&y)const{return smaller(y.s,s);}
};priority_queue<data> q;
inline void Add(int x,int k,string S)
{
	for(;k>=0;--k)
	{
		if(f[x][k]==""||smaller(S,f[x][k]))
			q.push((data){f[x][k]=S,x,k});	
	}
}
int main()
{
	Add(Xpre,2,"x");Add(Ypre,2,"y");Add(Zpre,2,"z");
	while(!q.empty())
	{
		while(!q.empty()&&q.top().s!=f[q.top().x][q.top().k]) q.pop();
		if(q.empty()) break;
		data t=q.top();q.pop();
		if(t.k!=2) Add(t.x,2,"("+t.s+")"); 
		if(t.k==2) Add(255-t.x,2,"!"+t.s);
		if(t.k==1)
		{
			for(int i=0;i<255;++i)
				for(int j=1;j<=2;++j) if(f[i][j]!="")
					Add(t.x&i,1,min(t.s+"&"+f[i][j],f[i][j]+"&"+t.s));	
		}
		if(t.k==0)
		{
			for(int i=0;i<255;++i) for(int j=0;j<=2;++j) if(f[i][j]!="")
				Add(t.x|i,0,min(t.s+"|"+f[i][j],f[i][j]+"|"+t.s));	
		}
	}
	for(int T=read();T;--T)
	{
		static char S[15];
		scanf("%s",S+1);int x=0;
		for(int i=8;i;--i) x=x*2+S[i]-'0';
		cout<<f[x][0]<<endl;
	}
	return 0;
}