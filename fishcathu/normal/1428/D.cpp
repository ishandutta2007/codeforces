#include<cstdio>
#include<deque>
using namespace std;
const int N=2E5+1; 
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
int ans1[N],ans2[N],t;
void add(int a,int b)
{
	ans1[++t]=a,ans2[t]=b;
}
struct s
{
	int r,p;
	s(int b,int c)
	{
		r=b,p=c;
	}
};
int main()
{
	int n=read();
	deque<s>q;
	for(int i=1,k=1;i<=n;++i)
	{
		int z=read();
		if(z==1)
		{
			if(q.empty())add(i,k++);
			else
			{
				if(q.front().p==3)add(i,k++);
				add(i,q.front().r),q.pop_front();	
			}
		}
		else if(z)
		{
			if(!q.empty()&&q.back().p==3)add(i,q.back().r),q.pop_back();
			add(i,k),q.push_back(s(k++,z));
		}
	}
	if(q.empty()&&ans2[t]<=n)
	{
		write(t),putchar('\n');
		for(int i=1;i<=t;++i)write(ans2[i]),putchar(' '),write(ans1[i]),putchar('\n');
	}
	else puts("-1");
	return 0;
}