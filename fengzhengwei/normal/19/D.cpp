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
int n;
const int xx=2e5+5;
int op[xx];
int X[xx];
int Y[xx];
int lsh[xx];
multiset<int>s[xx<<2];
int maxx[xx<<2];
void insert(int k,int l,int r,int x,int y)
{
	if(l==r)
	{
		s[k].insert(y);
//		cout<<k<<"qweqe"<<"\n";
		maxx[k]=*--s[k].end();
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)insert(k<<1,l,mid,x,y);
	else insert(k<<1|1,mid+1,r,x,y);
	maxx[k]=max(maxx[k<<1],maxx[k<<1|1]);
}
void erase(int k,int l,int r,int x,int y)
{
	if(l==r)
	{
		s[k].erase(s[k].find(y));
		if(s[k].size())maxx[k]=*--s[k].end();
		else maxx[k]=0;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)erase(k<<1,l,mid,x,y);
	else erase(k<<1|1,mid+1,r,x,y);
	maxx[k]=max(maxx[k<<1],maxx[k<<1|1]);
}
int ask(int k,int l,int r,int x,int y)
{
//	cout<<k<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<maxx[k]<<"\n";
	if(l==r)return maxx[k]<=y?l+1:l;
	if(x<=l&&maxx[k]<=y)return r+1;
	int mid=l+r>>1;
	if(x>mid)return ask(k<<1|1,mid+1,r,x,y);
	int s=ask(k<<1,l,mid,x,y);
	if(s<=mid)return s;
	s=ask(k<<1|1,mid+1,r,x,y);
//	if(s>r)cout<<"s:"<<s<<"\n";
	return s;
}
int find(int k,int l,int r,int x)
{
	if(l==r)return k;
	int mid=l+r>>1;
	if(x<=mid)return find(k<<1,l,mid,x);
	else return find(k<<1|1,mid+1,r,x);
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		char s[8];
		scanf("%s",s);
		if(s[0]=='a')op[i]=0;
		if(s[0]=='r')op[i]=1;
		if(s[0]=='f')op[i]=2;
		X[i]=read();
		Y[i]=read();
		lsh[i]=X[i];
	}
	sort(lsh+1,lsh+n+1);
	int tot=unique(lsh+1,lsh+n+1)-lsh-1;
	for(int i=1;i<=n;i++)
	{
		X[i]=lower_bound(lsh+1,lsh+tot+1,X[i])-lsh;
		if(op[i]==0)insert(1,1,n,X[i],Y[i]);
		if(op[i]==1)erase(1,1,n,X[i],Y[i]);
		if(op[i]==2)
		{
			int w=ask(1,1,n,X[i]+1,Y[i]);
//			cout<<X[i]<<" "<<w<<"\n";
//			cout<<*s[w].begin()<<"\n";
			if(w==n+1)puts("-1");
			else cout<<lsh[w]<<" "<<*s[find(1,1,n,w)].upper_bound(Y[i])<<"\n";
		}
	}
	return 0;
}