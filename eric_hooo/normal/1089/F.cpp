#include<iostream>
#include<cstdio>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<deque>
#include<utility>
#include<cctype>
#include<bitset>
#include<stdio.h>
#include<time.h>
#define ll long long
#define mp make_pair
using namespace std;
const int INF=1e9;
/*--------main part---------*/
inline int read(){
    int X = 0,w = 0 ;
	char ch = 0;
    while(!isdigit(ch)) {w |= ch == '-';ch = getchar();}
    while(isdigit(ch)) X = (X<<3) + (X<<1) + (ch ^ 48),ch = getchar();
    return w ? -X : X;
}
int n,m,i,j,a[100005];
int np[100005];
vector<int> p,f;
int excgcd(int n,int m,int &x,int &y)
{
	if (m==0)
	{
		x=1;
		y=0;
		return n;
	}
	int ans=excgcd(m,n%m,y,x);
	y=y-n/m*x;
	return ans;
}
int main()
{
	for(i=2;i<=100000;i++)
	{
		if(!np[i])
		{
			p.push_back(i);
			for(j=i+i;j<=100000;j+=i)
			{
				np[j]=1;
			}
		}
	}
	cin>>n;
	int t=n;
	for(i=0;i<p.size() and (p[i]*p[i])<=t;i++)
	{
		while(t%p[i]==0)
		{
			f.push_back(p[i]);
			t/=p[i]; 
		}
	}
	if(t>1)
	{
		f.push_back(t);
	}
	sort(f.begin(),f.end());
	f.resize(unique(f.begin(),f.end())-f.begin());
	if (f.size()<2)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	while(true)
	{
		int x=f[0],y=f[1],xx,yy;
		excgcd(x,y,xx,yy);
		xx*=-1;yy*=-1;
		xx+=n/x;
		while(xx<0)
		{
			xx+=n/x;
			yy-=n/y;
		}
		while(yy<0)
		{
			xx-=n/x;
			yy+=n/y;
		}
		if(xx>=0 and yy>=0)
		{
			vector<int> s1,s2;
			if(xx>0)
			{
				s1.push_back(xx);
				s2.push_back(n/x);
			}
			if(yy>0)
			{
				s1.push_back(yy);
				s2.push_back(n/y);
			}
			cout<<s1.size()<<endl;
			for(i=0;i<s1.size();i++)
			{
				cout<<s1[i]<<' '<<s2[i]<<endl;
			}
			return 0;
		}
	}
	return 0;
}