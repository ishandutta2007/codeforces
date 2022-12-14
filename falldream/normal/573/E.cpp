#include<algorithm>
#include<iostream>
#include<cstdio>
#define MB 300
#define MN 100000
#define pa pair<long long,int>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct Line{int k;long long b;int id;}q[MN/MB+5][MB+5],s[MN+5];
int n,a[MN+5],block[MN+5],top[MN/MB+5],b[MN+5];
long long res=0,ans=0,add[MN/MB+5],X[MN/MB+5],B[MN+5];

double Calc(Line a,Line b){return (double)(b.b-a.b)/(a.k-b.k);}
bool cmp(const Line&a,const Line&b){return a.k==b.k?a.b<b.b:a.k<b.k;}
void Build(int x)
{
	int l=(x-1)*MB+1,r=min(x*MB,n),num=0;top[x]=0;
	for(int i=l;i<=r;++i) if(!b[i]) s[++num]=(Line){a[i],B[i],i};
	sort(s+1,s+num+1,cmp);
	for(int i=1,j;i<=num;i=j+1)
	{
		for(j=i;j<num&&s[j+1].k==s[i].k;++j);
		while(top[x]>1&&Calc(s[j],q[x][top[x]])<=Calc(q[x][top[x]],q[x][top[x]-1])) --top[x];	
		q[x][++top[x]]=s[j];
	}
}

pa Solve(int x)
{
	int res=top[x],l=1,r=top[x]-1,mid;
	while(l<=r)
	{
		mid=l+r>>1;
		if(Calc(q[x][mid],q[x][mid+1])>=X[x]) res=mid,r=mid-1; 
		else l=mid+1;
	}
//	cout<<"Solve"<<x<<" "<<q[x][res].id<<" "<<q[x][res].k<<" "<<q[x][res].b<<endl;
	return make_pair(1LL*q[x][res].k*X[x]+1LL*q[x][res].b+add[x],q[x][res].id);
}

void Add(int r,int v)
{
	for(int i=1;i<block[r];++i) add[i]+=v;
	for(int i=(block[r]-1)*MB+1;i<=r;++i) B[i]+=v;
}

void AddX(int l,int v)
{
	for(int i=block[n];i>block[l];--i) ++X[i];
	for(int i=l;block[i]==block[l];++i) B[i]+=a[i];
}

int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),block[i]=(i-1)/MB+1;
	for(int i=1;i<=block[n];++i) X[i]=1,Build(i);
	for(int i=1;i<=n;++i)
	{
		pa mx(-1e18,0);
		for(int j=1;j<=block[n];++j) if(top[j]) mx=max(mx,Solve(j));
		res+=mx.first;b[mx.second]=1;
	//	cout<<mx.second<<" "<<mx.first<<endl;
		if(mx.first<0) break; 
		if(mx.second>1) Add(mx.second-1,a[mx.second]);
		if(mx.second<n) AddX(mx.second+1,1);
		Build(block[mx.second]);
		if(mx.second>1&&block[mx.second-1]!=block[mx.second]) Build(block[mx.second-1]);
		if(mx.second<n&&block[mx.second+1]!=block[mx.second]) Build(block[mx.second+1]); 
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}