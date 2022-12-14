#include<iostream>
#include<cstring>
#include<cstdio>
#define MX 500500
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[1005],X[55],Y[55];
int n,f[2][2][2][MX+5],d,cnt=1,fail[MX+5],c[MX+5][11],to[MX+5][11],q[MX+5],top,mark[MX+5];
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
int Solve(char*S)
{
	memset(f,0,sizeof(f));f[0][1][0][1]=1;
	for(int i=1,pre=0,now=1;i<=d;++i) 
	{
		for(int j=1;j<=cnt;++j) for(int k=0;k<2;++k) for(int l=0;l<2;++l) if(f[pre][k][l][j])
		{
		//	cout<<i-1<<" "<<l<<" "<<k<<" "<<j<<" "<<f[pre][k][l][j]<<endl;
			for(int s=0;s<10;++s)
			{
				if(s>S[i]-'0'&&k) continue;
				R(f[now][k&(s==S[i]-'0')][l|mark[to[j][s]]][to[j][s]],f[pre][k][l][j]);
			}
		}
		swap(now,pre);
		for(int j=0;j<2;++j) for(int k=0;k<2;++k) memset(f[now][j][k],0,sizeof(int)*(cnt+2));
	}
	int res=0;
	for(int j=1;j<=cnt;++j) for(int k=0;k<2;++k) R(res,f[d&1][k][1][j]);
//	cout<<"res="<<res<<endl;
	return res;
}

int main()
{
	scanf("%s",st+1);n=strlen(st+1);
	scanf("%s",X+1);scanf("%s",Y+1);d=strlen(X+1);
	for(int i=1;i<=n;++i) 
	{
		int x=1;
		for(int j=i;j<=n;++j)
		{
			int t=st[j]-'0';
			if(!c[x][t]) c[x][t]=++cnt;
			x=c[x][t];
			if(j-i+1>=d>>1) mark[x]=1;
		}
	}
	q[top=1]=1;
	for(int i=0;i<10;++i) c[0][i]=to[0][i]=1;
	for(int i=1;i<=top;mark[q[i]]|=mark[fail[q[i]]],++i)
		for(int j=0;j<10;++j)
			if(c[q[i]][j])
			{
				int x=fail[q[i]];to[q[i]][j]=c[q[i]][j];
				while(!c[x][j]) x=fail[x];
				fail[q[++top]=c[q[i]][j]]=c[x][j];
			}
			else to[q[i]][j]=to[fail[q[i]]][j];
	int flag=0;
	for(int i=1;i+(d>>1)-1<=d;++i)
	{
		for(int j=1;j+(d>>1)-1<=n;++j)	
		{
			int ok=1;
			for(int k=1;k<=d>>1;++k) if(X[i+k-1]!=st[j+k-1]) ok=0;	
			if(ok) flag=1;
		}
	}
	printf("%d\n",(Solve(Y)-Solve(X)+flag+mod)%mod);
	return 0;
}