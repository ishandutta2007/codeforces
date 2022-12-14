#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,s[MN+5],a[MN+5],rev=0,lpos=1,rpos,Q;
int main()
{
	rpos=n=read();Q=read();
	for(int i=1;i<=n;++i) a[i]=1,s[i]=i;
	for(int i=1;i<=Q;++i)
	{
		//cout<<lpos<<" "<<rpos<<" "<<rev<<endl;
	//	for(int j=lpos;j<=rpos;++j) printf("%d %d\n",a[j],s[j]);
		int op=read();
		if(op==2)
		{
			int l=read()+1,r=read();	
			if(rev) l=rpos+1-l,r=rpos+1-r,swap(l,r);
			else l+=lpos-1,r+=lpos-1;
		//	cout<<"Query"<<l<<" "<<r<<endl;
			printf("%d\n",s[r]-s[l-1]);
		}
		else 
		{
			int p=read();	
			if(p<=(rpos-lpos+1)>>1)
			{
				if(rev)
				{
					for(int i=1;i<=p;++i)
						a[rpos-p-i+1]+=a[rpos-p+i];
					rpos-=p;
					for(int i=1;i<=p;++i) s[rpos-p+i]=s[rpos-p+i-1]+a[rpos-p+i];
				}	
				else 
				{
					for(int i=1;i<=p;++i)
						a[lpos+p+i-1]+=a[lpos+p-i];
					lpos+=p;s[lpos-1]=0;
					for(int i=1;i<=p;++i) s[lpos+i-1]=s[lpos+i-2]+a[lpos+i-1];
				}
			}
			else
			{
				p=rpos-lpos+1-p;
				if(rev)
				{
					for(int i=1;i<=p;++i)
						a[lpos+p+i-1]+=a[lpos+p-i];
					lpos+=p;s[lpos-1]=0;
					for(int i=1;i<=p;++i) s[lpos+i-1]=s[lpos+i-2]+a[lpos+i-1];
				}
				else
				{
					for(int i=1;i<=p;++i)
						a[rpos-p-i+1]+=a[rpos-p+i];
					rpos-=p;
					for(int i=1;i<=p;++i) s[rpos-p+i]=s[rpos-p+i-1]+a[rpos-p+i];
				}	
				rev^=1;
			}
		}
	}
	return 0;
}