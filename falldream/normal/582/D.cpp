#include<iostream>
#include<cstring>
#include<cstdio>
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int s[3405],num=0,n,p,q,a[1005],f[2][3405][2][2][2];
char A[1005];
inline void Re(int&x,int y){x+=y;x>=mod?x-=mod:0;}
int main()
{
	p=read();q=read();scanf("%s",A+1);n=strlen(A+1);
	for(int i=1;i<=n;++i) a[n+1-i]=A[i]-'0';
	while(n)
	{
		long long x=0;
		for(int i=n;i;--i) x=x*10+a[i],a[i]=x/p,x%=p;
		for(;n&&a[n]==0;--n);s[++num]=x;
	}
	f[0][0][0][0][0]=1;
	for(int i=1,now=1,pre=0;i<=num;++i)
	{
		for(int j=0;j<i;++j) 
			for(int k=0;k<2;++k)
				for(int l=0;l<2;++l)
					for(int S=0;S<2;++S) if(f[pre][j][k][l][S])
					{
						for(int F=0;F<3;++F)
						{
							int L,R,U,D,E;
							if(!F) L=0,R=s[i]-1;
							else if(F==1) L=R=s[i];
							else if(F==2) L=s[i]+1,R=p-1;
							if(L>R) continue;
							E=R-L+1;D=1LL*(R-L+1)*(L+R)/2%mod;U=1LL*(R-L+1)*(p-1-R+p-1-L)/2%mod;
							int Nk=bool((F==2)|(k&&F==1));
							Re(f[now][j][Nk][0][0],1LL*f[pre][j][k][l][S]*D%mod);
							Re(f[now][j+S][Nk][l][S],1LL*f[pre][j][k][l][S]*E%mod);
							Re(f[now][j+1][Nk][1][1],1LL*f[pre][j][k][l][S]*U%mod); 
						}
					}
		swap(now,pre);memset(f[now],0,sizeof(f[now]));
	}
	int ans=0;
	for(int j=q;j<=num;++j)for(int k=0;k<2;++k)Re(ans,f[num&1][j][0][0][k]);
	printf("%d\n",ans);
	return 0;
}