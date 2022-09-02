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
typedef pair<P,int> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
P1 p[100005],q[100005],r[100005];
int n,gp,k;
bool comp(const P1& x,const P1& y)
{
	if(x.first.first<y.first.first) return true;
	else if(x.first.first>y.first.first) return false;
	else
	{
		if(x.first.second>y.first.second) return true;
		else return false;
	}
}
bool comp2(const P1& x,const P1& y)
{
	if(x.first.second>y.first.second) return true;
	else if(x.first.second<y.first.second) return false;
	else
	{
		if(x.first.first>y.first.first) return true;
		else return false;
	}
}
int di[200005]={};
int main(){
	cin >> n >> gp >> k;

	for(int i=0;i<n;i++)
	{
		int a,b;
		cin >> a >> b;
		p[i]=mp(mp(b,a),i);
	}

	sort(p,p+n,comp);

	int val=INF;
	vector<int>ans;
	for(int i=0;i<gp-k;i++)
	{
		r[i]=p[i];
	}
	int m=n-gp+k;
	for(int i=gp-k;i<n;i++)
	{
		q[i-gp+k]=p[i];
	}

	sort(q,q+m,comp2);

	for(int i=0;i<k;i++)
	{
		ans.pb(q[i].second);
		val=min(val,q[i].first.first);
	}
	int val2=0;
	for(int i=0;i<k;i++)
	{
		if(val==q[i].first.first) val2=max(val2,q[i].first.second);
	}
	for(int i=k;i<m;i++)
	{
		r[gp-k+i-k]=q[i];
	}
	int z=n-k;
	sort(r,r+z,comp);
	int upper=z-1;
	for(int i=0;i<z;i++){
		if(r[i].first.first>=val)
		{
			if(r[i].first.first==val && r[i].first.second>=val2) continue;
			upper=i-1;
			break;
		}
	}

	for(int i=upper,j=0;j<gp-k;i--,j++)
	{
		ans.pb(r[i].second);
	}
	bool already=false;
	for(int i=0;i<ans.size();i++)
	{
		printf("%d%c",ans[i]+1,i==ans.size()-1?'\n':' ');
	}
	cin >> n;
}