#include<algorithm>
#include<iostream>
#include<cstdio>
#include<map>
#define MN 200000
#define N 262144
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool R[MN+5],C[MN+5];char op[MN+5][5];
int q,X[MN+5],Y[MN+5],L[MN+5],L2[MN+5],tot1,tot2,T1[N*2+5],T2[N*2+5];
int Query(int*T,int x){int res=0;for(x+=N;x;x>>=1)res=max(res,T[x]);return res;}
void Modify(int*T,int l,int r,int v)
{
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) T[l+1]=max(T[l+1],v);
		if( r&1) T[r-1]=max(T[r-1],v);	
	}		
}
int main()
{
	read();q=read();
	for(int i=1;i<=q;++i)
	{
		X[i]=L[i] =read();
		Y[i]=L2[i]=read();
		scanf("%s",op[i]+1);
	}
	sort(L+1,L+q+1);tot1=unique(L+1,L+q+1)-L-1;
	sort(L2+1,L2+q+1);tot2=unique(L2+1,L2+q+1)-L2-1;
	for(int i=1;i<=q;++i)
	{
		int x=lower_bound(L+1,L+tot1+1,X[i])-L;
		int y=lower_bound(L2+1,L2+tot2+1,Y[i])-L2;
		if(R[x]||C[y]) {puts("0");continue;}R[x]=C[y]=1;
		if(op[i][1]=='L') 
		{
			int t=Query(T1,y);printf("%d\n",L[x]-L[t]);
		//	cout<<"t="<<t<<endl;
			Modify(T2,max(1,t),x,y);
		}
		else 
		{
			int t=Query(T2,x);printf("%d\n",L2[y]-L2[t]);
		//	cout<<"t="<<t<<endl;
			Modify(T1,max(1,t),y,x);			
		}
	}
	return 0;
}