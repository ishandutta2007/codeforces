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
char st[505];
int num=0,n,m,Rt[505],s[20][10],q[505],top,a[505][1<<16],A[1<<16],B[1<<16],P[1<<16];
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
void FWT(int*a,int l,int r,int val,int Kind)
{
	if(l==r) return;int mid=l+r>>1;
	FWT(a,l,mid,val,Kind);FWT(a,mid+1,r,val,Kind);
	for(int i=0;i<=mid-l;++i) 
	{
		if(Kind==0) R(a[i+l],1LL*val*a[mid+1+i]%mod);
		else R(a[mid+1+i],1LL*val*a[i+l]%mod);
	}
}
void Work(int*a,char op,int*b)
{
//	cout<<"Work"<<op<<" "<<sizeof(P)<<endl;
//	for(int i=0;i<1<<m;++i) printf("%d %d %d\n",i,a[i],b[i]);
	memcpy(P,a,sizeof(P));memset(a,0,sizeof(P));
	if(op=='&'||op=='?')
	{
		memcpy(A,P,sizeof(A));
		memcpy(B,b,sizeof(B));
		FWT(A,0,(1<<m)-1,1,0);
		FWT(B,0,(1<<m)-1,1,0);
		for(int i=0;i<1<<m;++i) A[i]=1LL*A[i]*B[i]%mod;
		FWT(A,0,(1<<m)-1,mod-1,0);
		for(int i=0;i<1<<m;++i)  a[i]=A[i];
	}
	if(op=='|'||op=='?')
	{
		memcpy(A,P,sizeof(A));
		memcpy(B,b,sizeof(B));
		FWT(A,0,(1<<m)-1,1,1);
		FWT(B,0,(1<<m)-1,1,1);
		for(int i=0;i<1<<m;++i) A[i]=1LL*A[i]*B[i]%mod;
		FWT(A,0,(1<<m)-1,mod-1,1);
		for(int i=0;i<1<<m;++i) R(a[i],A[i]);
	}
}
inline int Stat(int x,int v)
{
	int res=0;
	for(int i=1;i<=m;++i) res+=(s[i][x]^v)<<(i-1);
	return res;	
}
void GetVal(int*a,char v)
{
	//cout<<"GetVal"<<v<<endl;
	for(int i=0;i<4;++i)
	{
		if(v=='a'+i||v=='?') R(a[Stat(i+1,1)],1);
		if(v=='A'+i||v=='?') R(a[Stat(i+1,0)],1);	
	}
}

int Solve(int l,int r)
{
//	cout<<"Solve"<<l<<" "<<r<<endl;
	int x=++num;
	if(st[l]=='(') 
	{
		int id=Solve(l+1,Rt[l]-1);	
		memcpy(a[x],a[id],sizeof(a[id]));
	}
	else 
	{
		GetVal(a[x],st[l]);
		Rt[l]=l;
	}
	for(int rt=Rt[l]+2,R;rt<=r;rt=R+2)
	{
		if(st[rt]=='(') R=Rt[rt];
		else R=rt;int id=Solve(rt,R);
		Work(a[x],st[rt-1],a[id]);
	}
	return x;
}

int main()
{
	scanf("%s",st+1);n=strlen(st+1);m=read();
	for(int i=1;i<=m;++i) 
		for(int j=1;j<=5;++j) s[i][j]=read();	
	for(int i=1;i<=n;++i) 
		if(st[i]=='(') q[++top]=i;
		else if(st[i]==')') Rt[q[top--]]=i;
	int id=Solve(1,n),stat=0;
	for(int i=1;i<=m;++i) stat+=s[i][5]<<(i-1);
//	for(int i=0;i<1<<m;++i) printf("a[%d]=%d\n",i,a[id][i]);
	printf("%d\n",a[id][stat]);
	return 0;
}