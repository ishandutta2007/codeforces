#include<bits/stdc++.h>
using namespace std;
const int magic=1000;
int n,m,a[222222],b[222222],pos[222222],res,lb,rb,tp,x,y,xx,yy,sz;
int bit[222][333333];
void add(int p,int id,int x)
{
	while(p<=sz)
	{
		bit[id][p]+=x;
		p+=p&(-p);
	}
}
int query(int p,int id)
{
	int res=0;
	while(p>=1)
	{
		res+=bit[id][p];
		p-=p&(-p);
	}
	return res;
}
const int maxn=1000;
char buffer[maxn],*S,*T;
inline char Get_Char()
{
    if(S==T)
    {
        T=(S=buffer)+fread(buffer,1,maxn,stdin);
        if(S==T) return EOF;
    }
    return *S++;
}

int read()
{
    char c;
    int re=0;
    for(c=Get_Char();c<'0'||c>'9';c=Get_Char());
    while(c>='0'&&c<='9')
           re=(re<<1)+(re<<3)+(c-'0'),c=Get_Char();
    return re;
}
int main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++) pos[a[i]]=i;
	sz=1;
	while(sz<n) sz*=2;
	for (int i=0;i<(n+magic-1)/magic;i++)
	{
		for (int j=i*magic+1;j<=n && j<=(i+1)*magic;j++)
		{
			add(pos[b[j]],i,1);
		}
	}
	while(m--)
	{
		tp=read();
		if (tp==1)
		{
			x=read();y=read();xx=read();yy=read();
			res=0;
			if (yy-xx<=magic)
			{
				for (int i=xx;i<=yy;i++) 
				{
					if (pos[b[i]]>=x && pos[b[i]]<=y) res++;
				}
			}
			else
			{
				lb=(xx-1)/magic+1;rb=(yy-1)/magic-1;
				for (int i=lb;i<=rb;i++) res+=(query(y,i)-query(x-1,i));
				int rx=lb*magic,ry=(rb+1)*magic+1;
				for (int i=xx;i<=rx;i++) 
				{
					if (pos[b[i]]>=x && pos[b[i]]<=y) res++;
				}
				for (int i=ry;i<=yy;i++)
				{
					if (pos[b[i]]>=x && pos[b[i]]<=y) res++;
				}
			}
			printf("%d\n",res);
		}
		else
		{
			x=read();y=read();
			if ((x-1)/magic==(y-1)/magic)
			{
				swap(b[x],b[y]);
			}
			else
			{
				add(pos[b[x]],(x-1)/magic,-1);
				add(pos[b[y]],(x-1)/magic,1);
				add(pos[b[y]],(y-1)/magic,-1);
				add(pos[b[x]],(y-1)/magic,1);
				swap(b[x],b[y]);
			}
		}
	}
	return 0;
}