#include<bits/stdc++.h>
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
const int xx=2.4e5+5;
//-----------------------------------------------------------------------------------------------------------------------------------
vector<int>v[xx];//() 
int n,mn[xx<<2],ad[xx<<2],a[xx];
void add(int x,int y){mn[x]+=y,ad[x]+=y;}
void pd(int k){if(!ad[k])return;add(k<<1,ad[k]);add(k<<1|1,ad[k]);ad[k]=0;}
int ask(int k,int l,int r)
{
	if(l==r)return l;
	pd(k);
	int mid=l+r>>1;
	if(mn[k]==mn[k<<1|1])return ask(k<<1|1,mid+1,r);
	return ask(k<<1,l,mid);
}
void ch(int k,int l,int r,int x,int y)
{
	if(l==r)return mn[k]=y,void();
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)ch(k<<1,l,mid,x,y);
	else ch(k<<1|1,mid+1,r,x,y);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
void ch(int k,int l,int r,int x,int y,int z)
{
	if(x>y)return;
	if(x<=l&&r<=y)return add(k,z);
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)ch(k<<1,l,mid,x,y,z);
	if(mid<y)ch(k<<1|1,mid+1,r,x,y,z);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
struct pr
{
	int x,y;
	pr(){}
	pr(int a,int b):x(a),y(b){}
};
//-----------------------------------------------------------------------------------------------------------------------------------
pr s1[xx],s2[xx];// , 
int L[xx],R[xx],s3[xx],vis[xx],t1,t2,t3;//01 
int f[xx][20],dep[xx],LL[xx],RR[xx],lg[xx];
ll r[xx],l[xx];//(sum1()) 
ll sum[xx],val[xx];//val,val 
ll rf[xx][20],lf[xx][20],S[xx];
ll get(ll x){return x*(x-1)/2;}
int id[xx];
void dfs(int x,int y)
{
//	cout<<x<<" "<<y<<"\n";

	if(x<=n)LL[x]=x,RR[x]=x;
	else LL[x]=1e9,RR[x]=-1e9;
	val[x]=1;if(!vis[x]&&x>n)val[x]+=get(v[x].size())-1;// 
	f[x][0]=y;dep[x]=dep[y]+1;
	for(int i=1;i<20;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=0;i<v[x].size();i++)dfs(v[x][i],x),LL[x]=min(LL[x],LL[v[x][i]]),RR[x]=max(RR[x],RR[v[x][i]]),sum[x]+=sum[v[x][i]];
	sum[x]+=val[x];
	for(int i=0;i<v[x].size();i++)l[i]=r[i]=0;
	for(int i=0;i<v[x].size();i++)
	{
		id[v[x][i]]=i;
		if(i)l[i]=l[i-1],l[i]+=sum[v[x][i-1]],S[v[x][i]]=S[v[x][i-1]];
		S[v[x][i]]+=sum[v[x][i]];
		if(!vis[x])l[i]+=get(i);
		lf[v[x][i]][0]=l[i];
		if(!vis[x])l[i]-=get(i);
	}
	for(int i=v[x].size()-1;i>=0;i--)
	{
		if(i!=v[x].size()-1)r[i]=r[i+1],r[i]+=sum[v[x][i+1]];
		if(!vis[x])r[i]+=get(v[x].size()-1-i);
		rf[v[x][i]][0]=r[i];
		if(!vis[x])r[i]-=get(v[x].size()-1-i);
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------
pr lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]!=dep[y])x=f[x][lg[dep[x]-dep[y]]];
	for(int i=lg[x];i>=0;i--)(f[x][i]^f[y][i])?(x=f[x][i],y=f[y][i]):0;
	return pr(x,y);
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	memset(mn,0x3f,sizeof(mn));
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)L[i]=R[i]=a[i];
	int cst=n;
	for(int i=1;i<=n;i++)
	{
		int now=i;
		int last=t3+1;
		while(t1&&s1[t1].x<a[i])ch(1,1,n,s1[t1].y,last-1,-s1[t1].x),last=s1[t1--].y;
		ch(1,1,n,last,t3,a[i]);
		s1[++t1]=pr(a[i],last);
		last=t3+1;
		while(t2&&s2[t2].x>a[i])ch(1,1,n,s2[t2].y,last-1,s2[t2].x),last=s2[t2--].y;
		ch(1,1,n,last,t3,-a[i]);
		s2[++t2]=pr(a[i],last);
		while(mn[1]==i)
		{
			int id=ask(1,1,n),p=s3[id];
			if(id==t3&&!vis[p]&&v[p].size()&&((R[*--v[p].end()]==R[p]&&R[p]+1==L[now])||(L[*--v[p].end()]==L[p]&&L[p]-1==R[now])))
			{
				v[p].push_back(now);
				L[p]=min(L[p],L[now]);
				R[p]=max(R[p],R[now]);
				now=p;
				ch(1,1,n,t3,1e9);
				t3--;
			}
			else 
			{
				p=++cst;
				L[p]=L[now];
				R[p]=R[now];
				for(int i=id;i<=t3;i++)
				{
					v[p].push_back(s3[i]);
					L[p]=min(L[p],L[s3[i]]);
					R[p]=max(R[p],R[s3[i]]);
					ch(1,1,n,i,1e9);
				}
				v[p].push_back(now);
				now=p;
				if(t3-id+1>2)vis[p]=1;
				t3=id-1;
			}
		}
		s3[++t3]=now;
		while(t1&&s1[t1].y>t3)t1--;
		while(t2&&s2[t2].y>t3)t2--;
		ch(1,1,n,t3,i);
	}
//-----------------------------------------------------------------------------------------------------------------------------------
	dfs(s3[1],0);
//		for(int i=1;i<=cst;i++)cout<<i<<" sss "<<lf[i][0]<<" "<<rf[i][0]<<" "<<sum[i]<<"\n";
	for(int j=1;j<20;j++)
		for(int i=1;i<=cst;i++)
		{
			lf[i][j]=lf[i][j-1]+lf[f[i][j-1]][j-1];
			rf[i][j]=rf[i][j-1]+rf[f[i][j-1]][j-1];
		}
	
	int m=read();
	while(m--)
	{
		int l,r;
		l=read();
		r=read();
		if(l==r)cout<<1<<"\n";
		else 
		{
			pr p=lca(l,r);
			if(LL[p.x]>LL[p.y])swap(p.x,p.y);
			ll x=l,y=r;
			for(int j=20;j>=0;j--)if(f[x][j]&&f[x][j]!=s3[1]&&LL[f[x][j]]==l)x=f[x][j];
			for(int j=20;j>=0;j--)if(f[y][j]&&f[y][j]!=s3[1]&&RR[f[y][j]]==r)y=f[y][j];
			ll res=0,num=0;
			if(dep[x]<=dep[p.x])res+=sum[p.x],num++;
			else 
			{
				res+=sum[x];if(!vis[f[x][0]])res+=v[f[x][0]].size()-1-id[x]; 
				while(dep[x]!=dep[p.x])res+=rf[x][lg[dep[x]-dep[p.x]]],x=f[x][lg[dep[x]-dep[p.x]]];
			}
			if(dep[y]<=dep[p.y])res+=sum[p.y],num++;
			else 
			{
				res+=sum[y];if(!vis[f[y][0]])res+=id[y];//
//				cout<<res<<" sss "<<y<<"\n";
				while(dep[y]!=dep[p.y])res+=lf[y][lg[dep[y]-dep[p.y]]],y=f[y][lg[dep[y]-dep[p.y]]];
			}
			if(!vis[f[p.x][0]])num+=id[p.y]-id[p.x]-1,res+=get(num);
			else if(LL[f[p.x][0]]==l&&RR[f[p.x][0]]==r)res++; 
			res+=S[p.y]-S[p.x]-sum[p.y];
			
			cout<<res<<'\n';
//			cout<<LL[f[p.x][0]]<<" "<<RR[f[p.x][0]]<<"\n";
//			else cout<<min(LL[p.x],LL[p.y])<<" "<<max(RR[p.x],RR[p.y])<<"\n";
		}
	}
	return 0;
}