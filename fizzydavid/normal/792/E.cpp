//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int terra=40000;
int n,a[555];
vector<int>v,tv,nv;
void solve(int a,bool fb)
{
	int d=1;
	while((a-1)/(d+1)<a/d)d++;
	d--;
	v.clear();
	int last=2e9;
	for(int i=1;i<=min(a,terra);i++)
	{
		if(a/i<last)v.PB(a/i),last=a/i;
		if(a%i==0&&a/i-1<last)v.PB(a/i-1),last=a/i-1;
	}
	for(int i=min(d,last-1);i>=1;i--)v.PB(i);
	reverse(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	if(fb)tv=v;
	else
	{
		nv.clear();
		int it=0;
		for(int i=0;i<v.size();i++)
		{
			while(it<tv.size()&&tv[it]<v[i])it++;
			if(it<tv.size()&&v[i]==tv[it])
			{
				nv.PB(v[i]);
			}
		}
		tv=nv;
	}
}
void calc(int x)
{
//	cout<<"calc:"<<x<<endl;
	ll sum=0;
	for(int i=1;i<=n;i++)sum+=(a[i]-1)/(x+1)+1;
	cout<<sum<<endl;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		solve(x,i==1);
		a[i]=x;
	}
//	for(auto i:tv)cout<<i<<endl;
	calc(tv[tv.size()-1]);
	return 0;
}