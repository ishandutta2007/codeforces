//E? Nanndatte?
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
long long num[300005];
long long rui[300005]={};
int main(){
	int n;
	cin >> n;
	map<long long int,vector<int> > ma;
	for(int i=1;i<=n;i++)
	{
		long long int s;
		cin >> s;
		num[i]=s;
		if(ma[s].size()==2) ma[s].pop_back();
		ma[s].pb(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(num[i]>=0) rui[i]=rui[i-1]+num[i];
		else rui[i]=rui[i-1];
	}
	map<long long int,vector<int> > ::iterator it;
	long long ans=-1e16;
	long long lim[2];
	for(it=ma.begin();it!=ma.end();++it)
	{
		vector<int>ite=it->second;
		if(ite.size()==1) continue;
		int beg=ite[0];
		int en=ite[1];
		if(beg==en) continue;
		long long sum=it->first*2LL+rui[en-1]-rui[beg];
		if(sum>ans)
		{
			ans=sum;
			lim[0]=beg;
			lim[1]=en;
		}
	}

	printf("%lld",ans);
	vector<int> ret;
	for(int i=1;i<lim[0];i++) ret.pb(i);
	for(int i=lim[0];i<=lim[1];i++)
	{
		if(i==lim[0] || i==lim[1]) continue;
		if(num[i]<0) ret.pb(i);
	}
	for(int i=lim[1]+1;i<=n;i++) ret.pb(i);
	printf(" %d\n",ret.size());
	for(int i=0;i<ret.size();i++)
	{
		printf("%d%c",ret[i],i==ret.size()-1?'\n':' ');
	}
	cin >> n;
}