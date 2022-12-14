#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#define MN 100000
#define N 131072
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct data{int a,b,c,d,id,val;}s[MN+5];
struct Que{int x;
	bool operator <(const Que&y)const{return s[x].val>s[y.x].val;}
};
priority_queue<Que> q;set<pair<int,int> > st[N*2+5];
int n,rk[MN+5],from[MN+5],C[MN+5],cnt=0;
bool cmpx(int x,int y){return s[x].c<s[y].c;}
bool cmpy(int x,int y){return s[x].d<s[y].d;}
void Add(int x,int v)
{
//	cout<<"Add"<<x<<" "<<v<<endl;
	s[x].val=v;
	q.push((Que){x});
}

int Query(int x,int y)
{
	set<pair<int,int> >::iterator it=st[x].lower_bound(make_pair(y,0));	
	if(it!=st[x].end()) return it->second;
	else return 0;
}

int Get(int l,int y)
{
//	cout<<"get"<<l<<" "<<y<<endl;
	int r=n,k=0;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) {k=Query(l+1,y);if(k)return k;}
		if( r&1) {k=Query(r-1,y);if(k)return k;}
	}
	return -1;
}

void Insert(int x,int y,int d){for(x+=N;x;x>>=1)st[x].insert(make_pair(y,d));	}
void Erase(int x,int y,int d){for(x+=N;x;x>>=1)st[x].erase(st[x].lower_bound(make_pair(y,d)));}

int main()
{
	n=read();
	for(int i=1;i<=n;++i) s[i].a=read()+1,s[i].b=read()+1,s[i].c=read()+1,s[i].d=read()+1,s[i].id=rk[i]=i;
	++n;s[n]=(data){1,1,1,1,n,0};rk[n]=n;
//	for(int i=1;i<=n;++i) cout<<s[i].a<<" "<<s[i].b<<" "<<s[i].c<<" "<<s[i].d<<endl;
	sort(rk+1,rk+n+1,cmpx);
	for(int i=1;i<=n;++i) C[i]=s[rk[i]].c,s[rk[i]].c=i;
	for(int i=1;i<=n;++i) s[i].a=lower_bound(C+1,C+n+1,s[i].a)-C;
	sort(rk+1,rk+n+1,cmpy);
	for(int i=1;i<=n;++i) C[i]=s[rk[i]].d,s[rk[i]].d=i;
//	for(int i=1;i<=n;++i) cout<<D[i]<<endl;
	for(int i=1;i<=n;++i) s[i].b=lower_bound(C+1,C+n+1,s[i].b)-C;
	for(int i=1;i<=n;++i) if(i!=n-1) Insert(s[i].c,s[i].d,i),s[i].val=1e9;
//	for(int i=1;i<=n;++i) cout<<s[i].a<<" "<<s[i].b<<" "<<s[i].c<<" "<<s[i].d<<endl;
	Add(n-1,0); 
	while(!q.empty())
	{
		int y=q.top().x;
		int x=Get(s[y].a,s[y].b);
		if(x==-1) {q.pop();continue;}
		Add(x,s[y].val+1);from[x]=s[y].id;
		if(x==n) break;Erase(s[x].c,s[x].d,x);
	}
	if(s[n].val==1e9) return 0*puts("-1");
	printf("%d\n",s[n].val);
	for(int i=from[n];i;i=from[i]) printf("%d ",i);
	return 0;
}