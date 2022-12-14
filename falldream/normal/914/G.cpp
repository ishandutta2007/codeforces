#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 131072
#define mod 1000000007
#define R(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,X,a[MN],f[MN],num[MN],A[18][MN],B[18][MN],C[MN],D[MN],ans;
void Inc (int&x,int y){(x+=y)>=mod?x-=mod:0;}
void Dec (int&x,int y){(x-=y)<0?x+=mod:0;}
void AND (int&x,int&y){Inc(x,y);}
void IAND(int&x,int&y){Dec(x,y);}
void OR  (int&x,int&y){Inc(y,x);}
void IOR (int&x,int&y){Dec(y,x);}
void XOR (int&x,int&y){int t=x;Inc(x,y);Dec(t,y);y=t;}
void IXOR(int&x,int&y){int t=x;Inc(x,y);Dec(t,y);y=t;x=1LL*x*(mod+1)/2%mod;y=1LL*y*(mod+1)/2%mod;}
void FWT(int*a,int l,int r,void(*F)(int&,int&))
{
	if(l==r) return;
	int mid=l+r>>1;
	FWT(a,l,mid,F);FWT(a,mid+1,r,F);
	R(i,0,mid-l) F(a[l+i],a[mid+1+i]);
}
int main()
{
	n=read();f[1]=num[1]=1;
	R(i,2,MN-1) f[i]=(f[i-1]+f[i-2])%mod,num[i]=num[i>>1]+(i&1); 
	R(i,1,n) X=read(),++A[num[X]][X],++a[X];
	R(i,0,17) FWT(A[i],0,MN-1,OR);
	R(i,0,17) R(j,0,i) R(k,0,MN-1)Inc(B[i][k],1LL*A[j][k]*A[i-j][k]%mod);
	R(i,0,17) FWT(B[i],0,MN-1,IOR);
	R(j,0,17) R(i,0,MN-1) if(num[i]==j) Inc(C[i],1LL*B[j][i]*f[i]%mod);
	memcpy(D,a,sizeof(D));FWT(D,0,MN-1,XOR);
	R(i,0,MN-1) D[i]=1LL*D[i]*D[i]%mod;
	FWT(D,0,MN-1,IXOR);
	R(i,0,MN-1) D[i]=1LL*D[i]*f[i]%mod,a[i]=1LL*a[i]*f[i]%mod;
	FWT(D,0,MN-1,AND);FWT(a,0,MN-1,AND);FWT(C,0,MN-1,AND);
	R(i,0,MN-1) a[i]=1LL*a[i]*C[i]%mod*D[i]%mod;
	FWT(a,0,MN-1,IAND);
	for(int i=1;i<MN;i<<=1) Inc(ans,a[i]);
	printf("%d\n",ans);
}