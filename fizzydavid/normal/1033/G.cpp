//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
int n,m;
ll ia[111];
int a[111];
int gettype(int a,int b,int c)
{
	if(c<a)return 0;
	if(a<=c&&c<b)return 1;
	if(b<=c&&c<2*a)return 2;
	if(max(b,2*a)<=c)return 3;
	assert(false);
}
ll ans[4];//A B F S
void addans(int c[],int coef)
{
	if(coef==0)return;
	if(c[0]>0||c[2]>1)
	{
		ans[0]+=coef;
//		ans[1]+=coef;
	}
	else if(c[2]==0)
	{
		if(c[1]&1)ans[2]+=coef+coef;
		else ans[3]+=coef+coef;
	}
	else
	{
		if(c[1]&1)ans[0]+=coef;//,ans[1]+=coef;
		else ans[2]+=coef+coef;
	}
}
void solve(int l,int r,vector<pair<int,int> > &v,bool flag)
{
	int pre=l,c[3]={};
	for(int i=0;i<v.size()&&v[i].FF<=r;)
	{
		int coef=v[i].FF-pre;
		addans(c,coef);
		int ni=i;		
		while(ni<v.size()&&v[i].FF==v[ni].FF)
		{
			int ty;
			ty=v[ni].SS;
			if(ty>0)c[ty-1]++;
			else c[-ty-1]--;
			ni++;
		}
		pre=v[i].FF;
		i=ni;
	}
	addans(c,r-pre+1);
	if(flag)
	{
		assert(c[0]==0&&c[2]==0);
		if(c[1]&1)ans[2]-=1;
		else ans[3]-=1;
	}
}
int main()
{
	cin>>n>>m;
//	n=100;m=100000;
	for(int i=1;i<=n;i++)
	{
		ia[i]=rand()*RAND_MAX+rand();
		cin>>ia[i];
	}
	for(int i=2;i<=m+m;i++)
	{
		vector<pair<int,int> > v;
		int L=max(1,i-m),R=i>>1;
		for(int j=1;j<=n;j++)
		{
			a[j]=ia[j]%i;
			int &c=a[j];
			int l,r;
			l=L;r=min(R,min(c,i-c-1));
			if(l<=r)v.PB(MP(l,1)),v.PB(MP(r+1,-1));
			l=max(L,max(i-c,(c+2)/2));r=R;
			if(l<=r)v.PB(MP(l,2)),v.PB(MP(r+1,-2));
			l=max(L,i-c);r=min(R,c/2);
			if(l<=r)v.PB(MP(l,3)),v.PB(MP(r+1,-3));
		}
		sort(v.begin(),v.end());
		solve(L,R,v,i%2==0);
	}
	cout<<ans[0]<<" "<<ans[0]<<" "<<ans[2]<<" "<<ans[3]<<endl;
	return 0;
}