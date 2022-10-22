#include<bits/stdc++.h>
#define pii make_pair
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
map<pair<int,int>,char> mp;
int P,G,B;
signed main()
{
	int n=read(),m=read();
	for(;m--;)
	{
		char op=getchar();
		while(op!='+'&&op!='-'&&op!='?') op=getchar();
		if(op=='+')
		{
			int x=read(),y=read();
			char c=getchar();
			while(!islower(c)) c=getchar();
			mp[pii(x,y)]=c;
			if(mp[pii(y,x)]==c) ++P,++G; 
			else if(islower(mp[pii(y,x)])) ++G;
			
		}
		else if(op=='-')
		{
			int x=read(),y=read();
			if(!islower(mp[pii(y,x)])) 
			{
				mp[pii(x,y)]=' ';
				continue;
			}
			--G;
			if(mp[pii(y,x)]==mp[pii(x,y)]) --P;
			mp[pii(x,y)]=' ';
		}
		else
		{
			int x=read();
			if(P) puts("YES");
			else if(G)
			{
				if(x&1) puts("YES");
				else puts("NO");
			} 
			else puts("NO");
		}
	}
	return 0;
}