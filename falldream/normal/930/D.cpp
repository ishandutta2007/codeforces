#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<pair<int,int> > v1,v2;
int n,mn[MN+5],mx[MN+5],Mn[MN+5],Mx[MN+5];long long ans=0;
inline int Calc(int x){return (x+1000000)/2-500000;}
void Solve(vector<pair<int,int> >&v,int b)
{
	if(!v.size()) return;
	sort(v.begin(),v.end());
//	for(int i=0;i<v.size();++i)cout<<v[i].first<<" "<<v[i].second<<endl;
	for(int i=0;i<v.size();++i) 
		mn[i]=i?min(mn[i-1],v[i].second):v[i].second,
		mx[i]=i?max(mx[i-1],v[i].second):v[i].second;
	Mx[v.size()]=-1e9;Mn[v.size()]=1e9;
	for(int i=v.size();i--;) 
		Mx[i]=max(Mx[i+1],v[i].second),
		Mn[i]=min(Mn[i+1],v[i].second);
	for(int i=0,j;i<v.size();i=j+1)
	{
		for(j=i;j+1<v.size()&&v[j+1].first==v[i].first;) ++j;
		if(j+1==v.size()) return;
		int l=Mn[j+1],r=Mx[j+1];
		l=max(l,mn[j]),r=min(r,mx[j]);
		++l;--r;
	//	cout<<v[i].first<<" "<<v[j+1].first<<" "<<l<<" "<<r<<endl;
		if(l<=r) ans+=1LL*(v[j+1].first-v[i].first)/2*(Calc(r+b)-Calc(l-1+b));
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int x=read(),y=read();
		if((x+y)&1) v1.push_back(make_pair(x+y,y-x));
		else v2.push_back(make_pair(x+y,y-x)); 	
	}
	Solve(v1,0);Solve(v2,1);cout<<ans;
	return 0;
}