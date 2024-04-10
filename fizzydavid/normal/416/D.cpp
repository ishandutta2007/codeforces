/*
	Author  : JZdavid
	From    : CF
	Problem : pupulation size
	Time    : 2014/8/1
	Verdict : Accepting
*/
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
class prog
{
	vector<ll> v,p;
	int num;
	public:
		void init()
		{
			num=0;
			v.clear();
			p.clear();
		}
		int size(){return num;}
		bool add(ll val)
		{
			num++;
			if(val!=-1&&v.size()<2)
			{
				v.pb(val);
				p.pb(num-1);
			}
			if(v.size()<2)return true;
			if((v[1]-v[0])%(p[1]-p[0])!=0)return false;
			ll inc=(v[1]-v[0])/(p[1]-p[0]);
			ll first=v[0]+(0-p[0])*inc;
			ll last=v[0]+(num-1-p[0])*inc;
			if(val!=-1&&val!=last)return false;
			if(first<1||last<1)return false;
			return true;
		}
};
		
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	prog p;
	p.init();
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(p.add(x)==false)
		{
			p.init();
			p.add(x);
			ans++;
		}
	}
	if(p.size()>0)ans++;
	cout<<ans;
 //	system("pause");
	return 0;
}