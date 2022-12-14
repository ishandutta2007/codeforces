#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> v[300010];
int n,q;
int s[300010],head=0,tail=0,op,x,ans=0;
int begin[300010];
bool b[300010];
int num[300010];
int main()
{
	n=read();
	q=read();
	for(int i=1;i<=q;i++)
	{
		op=read(); x=read();
		switch(op)
		{
		    case(1):
			{
				v[x].push_back(++head);
				ans++;
				break;
			}	
		    case(2):
			{
				for(int i=begin[x];i<v[x].size();i++)
				{
					if(!b[v[x][i]])
					{
						b[v[x][i]]=1;
						ans--;
					}
				}
				begin[x]=v[x].size();
				break;
			} 
		 	default:{
		 		
		 		for(int i=tail+1;i<=x;i++)
		 		{
		 			if(!b[i])
		 			{
		 				b[i]=1;
		 				ans--;
		 			}
		 		}
		 		tail=max(tail,x);		
		 	}	
		}
		cout<<ans<<endl;	
	}
	return 0;
}