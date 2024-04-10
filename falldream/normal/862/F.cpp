#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#define MN 100000
#define N 131072
#define K 65
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[MN+5];set<int> s;
int lt[MN+5],rt[MN+5],n,m,L[MN+5],ans,top,q[MN+5],TT[N*2+5];
struct data{int lnum,len,rnum,ans;
	data operator +(const data&b)
	{
		data c;c.len=len+b.len;
		c.ans=max(max(ans,b.ans),rnum+b.lnum);
		c.lnum=lnum+(lnum==len?b.lnum:0);
		c.rnum=b.rnum+(b.rnum==b.len?rnum:0);
		return c;		
	}
}T[K+1][N*2+5],data1,data0;

void GetStr(int id)
{
	static int len=1;
	scanf("%s",st+len);int L=strlen(st+len);	
	lt[id]=len;rt[id]=len+L-1;len+=L;
}

int lcp(int l,int r,int L,int R)
{
	int ml=min(r-l+1,R-L+1);
	for(int i=0;i<ml;++i)	
		if(st[l+i]!=st[L+i]) return i;
	return ml;
}

void ModifyMx(int x,int v){for(TT[x+=N]=v;x>>=1;)TT[x]=max(TT[x<<1],TT[x<<1|1]);}
int QueryMx(int l,int r)
{
	int res=0;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) res=max(res,TT[l+1]);
		if( r&1) res=max(res,TT[r-1]);
	}
	return res;
} 

void Modify(data*T,int x){for(x+=N;x>>=1;)T[x]=T[x<<1]+T[x<<1|1];}
data Query(data*T,int l,int r)
{
	data L=(data){0,0,0,0},R=(data){0,0,0,0};
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) L=L+T[l+1];
		if( r&1) R=T[r-1]+R;	
	}
	return L+R;
} 

int main()
{
	data1=(data){1,1,1,1};data0=(data){0,1,0,0};
	n=read();m=read();
	for(int i=1;i<=n;++i) GetStr(i),TT[i+N]=rt[i]-lt[i]+1;
	for(int i=N;i;--i) TT[i]=max(TT[i<<1],TT[i<<1|1]);
	for(int i=2;i<=n;++i) 
	{
		L[i]=lcp(lt[i],rt[i],lt[i-1],rt[i-1]);
		if(L[i]>K) s.insert(i);
		for(int j=1;j<=K;++j)
			if(j<=L[i]) T[j][i+N]=data1;
			else T[j][i+N]=data0;
	}
	for(int i=1;i<=K;++i)for(int j=N;j;--j) T[i][j]=T[i][j<<1]+T[i][j<<1|1];
	for(int i=1;i<=m;++i)
		if(read()==1)	
		{
			int l=read(),r=read(),last;q[top=0]=l;ans=QueryMx(l,r);	
			if(l==r){printf("%d\n",ans);continue;}
			for(int j=1,k;j<=K;++j) if((k=Query(T[j],l+1,r).ans)>0) ans=max(ans,j*(k+1));
			for(set<int>::iterator it=s.lower_bound(l+1);it!=s.end()&&*it<=r;++it)
			{
				int x=*it;//cout<<"get"<<x<<endl;
				if(q[top]!=x-1){while(top) ans=max(ans,(last-q[top-1]+1)*L[q[top]]),--top;q[0]=x-1;}
				while(top&&L[x]<=L[q[top]]) ans=max(ans,(x-q[top-1])*L[q[top]]),--top; 
				q[++top]=x;last=x;
			}	
			while(top) ans=max(ans,(last-q[top-1]+1)*L[q[top]]),--top;
			printf("%d\n",ans);
		}
		else 
		{
			int x=read();
			if(x>1&&L[x]>K) s.erase(s.lower_bound(x));
			if(x<n&&L[x+1]>K) s.erase(s.lower_bound(x+1));	
			GetStr(x);
			if(x>1) L[x]=lcp(lt[x],rt[x],lt[x-1],rt[x-1]); 
			if(x<n) L[x+1]=lcp(lt[x],rt[x],lt[x+1],rt[x+1]);
	//		cout<<"Modify"<<x<<" "<<L[x]<<" "<<L[x+1]<<endl;
			if(x>1&&L[x]>K) s.insert(x);
			if(x<n&&L[x+1]>K) s.insert(x+1);
			if(x>1) for(int j=1;j<=K;++j) T[j][x+N]=L[x]>=j?data1:data0,Modify(T[j],x);
			if(x<n) for(int j=1;j<=K;++j) T[j][x+1+N]=L[x+1]>=j?data1:data0,Modify(T[j],x+1);
			ModifyMx(x,rt[x]-lt[x]+1);
		}
	return 0;
}