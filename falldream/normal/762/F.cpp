#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#define MN 1000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
unsigned long long ha[MN+5];vector<unsigned long long> v[MN+5];map<unsigned long long,int> mp,mp2;
int n,m,head[MN+5],Head[MN+5],fa[MN+5],cnt=0,f[MN+5][15],F[1<<12],size[MN+5],son[MN+5],q[MN+5],ans=0,now,P[15];
struct edge{int to,next;}e[MN*3+5];
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
inline void ins(int*H,int f,int t)
{
	e[++cnt]=(edge){t,H[f]};H[f]=cnt;
	e[++cnt]=(edge){f,H[t]};H[t]=cnt;
}

int pow(int x,int k)
{
	//cout<<"pow"<<x<<" "<<k<<endl;
	int sum=1;
	for(;k;k>>=1,x=1LL*x*x%mod)
		if(k&1) sum=1LL*sum*x%mod;
	return sum;	
}

void GetHa(int x,int f)
{
	ha[x]=0;size[x]=1;v[x].clear();fa[x]=f;
	for(int i=Head[x];i;i=e[i].next)
		if(e[i].to!=f) 
		{
			GetHa(e[i].to,x);
			v[x].push_back(ha[e[i].to]);
		}
	son[x]=v[x].size();
	sort(v[x].begin(),v[x].end());
	for(int i=0;i<v[x].size();++i) ha[x]=ha[x]*23333+v[x][i];
	ha[x]=ha[x]*2333+size[x];
}

void Solve(int x,int fat)
{
//	cout<<"Solve"<<x<<" "<<fat<<endl;
	int num=0;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fat) Solve(e[i].to,x),++num;
	for(int i=1;i<=m;++i)
	{
		if(!son[i]){f[x][i]=1;continue;}	
		if(num<son[i]){f[x][i]=0;continue;}
		for(int k=0;k<1<<son[i];++k)F[k]=0;
		F[0]=1;int top=0;
		for(int j=Head[i];j;j=e[j].next) if(e[j].to!=fa[i]) q[++top]=e[j].to,++mp2[ha[e[j].to]];
	//	cout<<"begin"<<x<<" -> "<<i<<endl;
	//	for(int i=1;i<=top;++i) cout<<q[i]<<" ";cout<<endl;
		for(int j=head[x];j;j=e[j].next)
			if(e[j].to!=fat)
			{						
				for(int s=(1<<top)-1;~s;--s) 
					for(int k=1;k<=top;++k) if(f[e[j].to][q[k]])
							if(!(s&(1<<k-1))) R(F[s|(1<<k-1)],1LL*F[s]*f[e[j].to][q[k]]%mod);
		//		for(int j=0;j<1<<top;++j) cout<<x<<" "<<i<<" "<<j<<" aft "<<e[j].to<<" = "<<F[j]<<endl;
			}
	//	for(int j=0;j<1<<top;++j) cout<<x<<" "<<i<<" "<<j<<" "<<F[j]<<endl;
		f[x][i]=F[(1<<top)-1];
		for(int j=1;j<=top;++j) 
		{
			//if(mp2[ha[q[j]]]) cout<<"?"<<" "<<mp2[ha[q[j]]];if(mp2[ha[q[j]]]>1) cout<<"!";
			if(mp2[ha[q[j]]]) f[x][i]=1LL*f[x][i]*pow(P[mp2[ha[q[j]]]],mod-2)%mod,mp2[ha[q[j]]]=0;
		}
	}
//	for(int i=1;i<=m;++i) cout<<x<<" "<<i<<" "<<f[x][i]<<endl;
	R(ans,f[x][now]);
}

int main()
{
	n=read();P[0]=1;
	for(int i=1;i<=12;++i) P[i]=1LL*P[i-1]*i%mod;
	for(int i=1;i<n;++i) ins(head,read(),read());
	m=read();
	for(int i=1;i<m;++i) ins(Head,read(),read());
	for(int i=1;i<=m;++i) 
	{
		GetHa(i,0);	
		if(mp[ha[i]]) continue;
		memset(f,0,sizeof(f));mp[ha[i]]=1;
	//	cout<<"BeginSolve"<<i<<endl;
		now=i;Solve(1,0);
	}
	printf("%d\n",ans);
	return 0;
}