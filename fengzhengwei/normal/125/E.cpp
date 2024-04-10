#include<bits/stdc++.h>
#define ll long long
#define ld long double
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
int n,m,k;
const int xx=5005;
struct nod{int x,y,z,id;bool operator<(const nod&w)const{return z<w.z;};};
vector<nod>v1,v2;
vector<int>res;
int fa[xx],val[100005];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int ryz;// 
int get(int x)
{
	res.clear();
	for(int i=1;i<=n;i++)fa[i]=i;
	int t1=0,t2=0,tt=0,vv=0;
	for(int i=1;i<=m;i++)
	{
		nod a;int vis=0;
		if((t1<v1.size()&&t2<v2.size()&&v1[t1].z+x<v2[t2].z)||t2==v2.size())a=v1[t1++],vis=1;
		else if((t1<v1.size()&&t2<v2.size()&&v1[t1].z+x==v2[t2].z)&&ryz)a=v1[t1++],vis=1,ryz--;
		else a=v2[t2++];
		if(find(a.x)==find(a.y))continue;
		res.push_back(a.id);
		a.x=find(a.x);a.y=find(a.y);
		tt++;vv+=vis;
		fa[a.x]=a.y;
	}
	if(tt!=n-1)puts("-1"),exit(0);
	return vv;
}
signed main(){// 
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		a=read(),b=read(),c=read();val[i]=c;
		if(a==1||b==1)v1.push_back((nod){a,b,c,i});
		else v2.push_back((nod){a,b,c,i});
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	if((k==0&&n>1)||v1.size()<k)return puts("-1"),0;
	int l=-1e6,r=1e6,ans;
//	puts("qweqweq");
	if(get(1e6)>k)return puts("-1"),0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(get(mid)<=k)ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(get(ans)==k)
	{
		cout<<n-1<<'\n';
		for(int i=0;i<res.size();i++)cout<<res[i]<<' ';
		puts("");return 0;
	}
	l=0,r=1e6;
	while(l<=r)
	{
		int mid=l+r>>1;
		ryz=mid;
		int w;
		if((w=get(ans))==k)
		{
			cout<<n-1<<'\n';
			for(int i=0;i<res.size();i++)cout<<res[i]<<' ';
			puts("");return 0;
		}
		if(w<k)l=mid+1;
		else r=mid-1;
	}
	return 0;
}