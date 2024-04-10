#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1E5+10;
int read() 
{ 	
    int a=0;char b=1,c; 
    do if((c=getchar())==45)b=-1;while(!(c&16)); 
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16); 
    return a*b; 
} 
void write(int x) 
{
    if(x<0)putchar('-'),x=-x; 
    char a[10],s=0; 
    do a[s++]=x%10|48;while(x/=10); 
    do putchar(a[--s]);while(s);
}
int a[N<<1],v[N];
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    int n=read();
	for(int i=1,s=0;i<=n*2;++i)
	{
		char c;
		while((c=getchar())!='-'&&c!='+');
		if(c=='+')v[++s]=i;
		else
		{
			int t=read();
			if(!s){puts("NO");return 0;}
			a[v[s--]]=t,a[i]=-t;
		}
	}
	for(int i=1;i<=2*n;++i)
	{
		if(a[i]>0)
		{
			q.push(a[i]);
		}
		else
		{
			if(q.top()!=-a[i]){puts("NO");return 0;}
			q.pop();	
		} 
	}
	puts("YES");
	for(int i=1;i<=2*n;++i)if(a[i]>0)printf("%d ",a[i]);
}