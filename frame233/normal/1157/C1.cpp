// luogu-judger-enable-o2
#pragma GCC optimize(3)
#include<cstdio>
#include<cstring>
#include<algorithm>
 
typedef long long ll;
 
template <typename T>T gcd(const T &a,const T &b){return (!b)?a:gcd(b,a%b);}
template <typename T>inline T abs(const T &a){return a>0?a:-a;}
template <typename T>inline T max(const T &a,const T &b){return a<b?b:a;}
template <typename T>inline T min(const T &a,const T &b){return a<b?a:b;}
template <typename T>inline void chmax(T &a,const T &b){(a<b)&&(a=b);}
template <typename T>inline void chmin(T &a,const T &b){(a>b)&&(a=b);}
 
template <typename T>inline void read(T& x)
{
    register char ch=getchar();
    while(ch<48||ch>57) ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
}
template <typename T,typename... Args> inline void read(T& t, Args&... args)
{
    read(t);read(args...);
}
 
const int N=200005;
int a[N];
char res[N],res2[N];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	int l=1,r=n,last=0;
	int ans=0;
	while(l<=r)
	{
		if(a[l]<a[r])
		{
			if(a[l]>last)
			{
				last=a[l++];
				res[++ans]='L';
			}
			else
			{
				if(a[r]>last)
				{
					last=a[r--];
					res[++ans]='R';
				}
				else
				{
					break;
				}
			}
		}
		else if(a[l]>a[r])
		{
			if(a[r]>last)
			{
				last=a[r--];
				res[++ans]='R';
			}
			else
			{
				if(a[l]>last)
				{
					last=a[l++];
					res[++ans]='L';
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			if(a[l]>last)
			{
				int tmp=ans,t=last,_l=l,_r=r;
				memcpy(res2,res,sizeof(res2));
				while(l<=r)
				{
					if(a[l]>last)
					{
						last=a[l++];
						res[++ans]='L';
					}
					else
					{
						break;
					}
				}
				std::swap(tmp,ans),std::swap(t,last);
				l=_l,r=_r;
				while(l<=r)
				{
					if(a[r]>last)
					{
						last=a[r--];
						res2[++ans]='R';
					}
					else
					{
						break;
					}
				}
				if(tmp>=ans)
				{
					printf("%d\n%s\n",tmp,res+1);
				}
				else
				{
					printf("%d\n%s\n",ans,res2+1);
				}
				return 0;
			}
			else
			{
				break;
			}
		}
	}
	printf("%d\n%s\n",ans,res+1);
	return 0;
}