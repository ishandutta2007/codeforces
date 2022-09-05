#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define input1(x) x=getnum()
#define input2(x,y) input1(x),y=getnum()
#define input3(x,y,z) input2(x,y),z=getnum()
#define input4(x,y,z,w) input3(x,y,z),w=getnum()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
const int size=262144;
struct SGT
{
	int a[size*2+5];
	void clear(){memset(a,0,sizeof(a));}
	inline void set(int id,int x)
	{
		id+=size-1;
		a[id]=x;id>>=1;
		while(id>0)
		{
			a[id]=min(a[id<<1],a[id<<1|1]);
			id>>=1;
		}
	}
	inline int query(int l, int r)
	{
  		l+=size-1;r+=size;
		register int ans=a[l];
  		while(l<r)
		{
			if(l&1)ans=min(ans,a[l++]);
 			if(r&1)ans=min(ans,a[--r]);
 			l>>=1;r>>=1;  
		}
		return ans;
	}
}sgt;
struct query
{
	int x1,y1,x2,y2,id;
	bool operator<(const query &tmp)const
	{
		return x2<tmp.x2;
	}
};
inline query make_query(int a,int b,int c,int d,int e)
{
	query t;
	t.x1=a;t.y1=b;t.x2=c;t.y2=d;t.id=e;
	return t;
}
int n,m,k,qn;
vector<pair<int,int> >pos;
vector<query>q;
bool ans[200111];
int main()
{
	ios_base::sync_with_stdio(false);
	input4(n,m,k,qn);
	int x,y,z,w;
	for(int i=1;i<=k;i++)
	{
		input2(x,y);
		pos.PB(MP(x,y));
	}
	for(int i=1;i<=qn;i++)
	{
		input4(x,y,z,w);
		q.PB(make_query(x,y,z,w,i));
	}
	sort(pos.begin(),pos.end());
	sort(q.begin(),q.end());
	int it=0;
	for(int i=0;i<q.size();++i)
	{
		while(it<pos.size()&&pos[it].FF<=q[i].x2)sgt.set(pos[it].SS,pos[it].FF),it++;
		ans[q[i].id]|=(sgt.query(q[i].y1,q[i].y2)>=q[i].x1);
	}
	for(int i=0;i<pos.size();++i)swap(pos[i].FF,pos[i].SS);
	for(int i=0;i<q.size();++i)swap(q[i].x1,q[i].y1),swap(q[i].x2,q[i].y2);
	sort(pos.begin(),pos.end());
	sort(q.begin(),q.end());
	it=0;sgt.clear();
	for(int i=0;i<q.size();++i)
	{
		while(it<pos.size()&&pos[it].FF<=q[i].x2)sgt.set(pos[it].SS,pos[it].FF),it++;
		ans[q[i].id]|=(sgt.query(q[i].y1,q[i].y2)>=q[i].x1);
	}
	for(int i=1;i<=qn;i++)puts(ans[i]?"YES":"NO");
	return 0;
}