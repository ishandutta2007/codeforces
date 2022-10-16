#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int cst;
struct node
{
	int x,y,ans,i;
	bool operator<=(const node&w)const
	{
		return (y==w.y?x<w.x:y<w.y)||(x==w.x&&y==w.y);
	}
}e[1000005];
map<int,int>mm;
int rd[400005];
int maxx[400005];
node val[400005];
int ls[400005];
int rs[400005];
int nd(node p)
{
	++cst;
	rd[cst]=rand();
	val[cst]=p;
	maxx[cst]=val[cst].x;
	return cst;
}
void update(int x)
{
	maxx[x]=min(maxx[ls[x]],maxx[rs[x]]);
	maxx[x]=min(maxx[x],val[x].x);
}
int merge(int x,int y)
{
	if(!x||!y)return x+y;
	if(rd[x]<rd[y])
	{
		rs[x]=merge(rs[x],y);
		update(x);
		return x;
	}
	ls[y]=merge(x,ls[y]),update(y);
	return y;
}
void split(int k,node a,int &x,int &y)
{
//	cout<<k<<endl;
	if(!k)return x=y=0,void();
	if(val[k]<=a)
	{
		x=k;
		split(rs[x],a,rs[x],y);
		update(x);
	}
	else 
	{
		y=k;
		split(ls[y],a,x,ls[y]);
		update(y);
	}
}
int n,m;
multiset<pair<int,int> >s;
bool cmp(node a,node b)
{
	return a.x<b.x;
}
void print(int x)
{
	if(ls[x])print(ls[x]);
	cout<<val[x].i<<" "<<val[x].x<<" "<<val[x].y<<" "<<val[x].ans<<endl;
	if(rs[x])print(rs[x]);
}
bool cmp2(node a,node b)
{
	return a.i<b.i;
}
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("b.out","w",stdout);
	maxx[0]=2147483647;
	srand(191981);
	n=read();
	m=read();
	int root=0;
	for(int i=1;i<=n;i++)
	{
		int x=read(),t=read();e[i].x=x,e[i].y=x+t,e[i].i=i;
	}
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int x=e[i].x;
		mm[x]=i;
		int a,b;
		split(root,e[i],a,b);
		root=merge(a,merge(nd(e[i]),b));
	}
//	cout<<"qweqe"<<endl;
//	print(root);
//	cout<<"qweqe"<<endl;
	for(int i=1;i<=m;i++)
	{
		int p,b;
		p=read();
		b=read();
		int x,y;
//		cout<<endl;
//		cout<<root<<" RT1"<<endl;
//		print(root);
//		cout<<endl;
		split(root,(node){1000000000,p-1},x,y);
//		cout<<x<<" "<<y<<endl;
//		cout<<"X:"<<endl;
//		print(x);
//		cout<<endl;
//		cout<<"Y:"<<endl;
//		print(y);
//		cout<<endl;
		int now=mm[maxx[y]];
//		cout<<maxx[y]<<endl;
		if(maxx[y]>p||!y)s.insert(make_pair(p,b)),root=merge(x,y);
		else 
		{
			e[now].ans++;
			root=merge(x,y);
			split(root,e[now],x,y);
			int z;
			split(x,(node){e[now].x-1,e[now].y},x,z);
			root=merge(x,y);
			e[now].y+=b;
			multiset<pair<int,int> >::iterator it=s.lower_bound(make_pair(e[now].x,0)),it1;
			while(it!=s.end())
			{
				if((*it).first>e[now].y)break;
				it1=it;
				e[now].y+=(*it).second;
				it++;e[now].ans++;
				s.erase(it1);
			}
			int a,b;
			split(root,e[now],a,b);
			root=merge(a,merge(nd(e[now]),b));
		}
//		cout<<endl;
//		cout<<root<<" RT2"<<endl;
//		print(root);
//		cout<<endl;
	}
	sort(e+1,e+n+1,cmp2);
	for(int i=1;i<=n;i++)
	{
		cout<<e[i].ans<<" "<<e[i].y-e[i].x<<"\n";
	}
	return 0;
}