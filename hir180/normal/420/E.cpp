//IOI2014
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
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
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
struct query
{
	double ang;
	int dif;
	bool operator < (const query& q) const
	{
		if(abs(ang-q.ang) > eps) return ang < q.ang;
		else return dif > q.dif;
	}
};
vector<query>vec;
int main()
{
	srand((unsigned int)time(NULL));
	int n; double d;
	scanf("%d %lf",&n,&d);
	for(int i=0;i<n;i++)
	{
		double a,b,c;
		scanf("%lf %lf %lf",&a,&b,&c);
		double dist=sqrt(a*a+b*b);
		for(int j=1;j<=10000;j++)
		{
			if(dist-c <= j*d && j*d <= dist+c)
			{
				double deg=atan2(b,a);
				double tv=(dist*dist+(j*d)*(j*d)-c*c) / (2*dist*(j*d));
				double b=acos(tv);
				vec.pb( (query){deg-b,1});
				vec.pb( (query){deg+b,-1});
			}
		}
	}
	int m=vec.size();
	for(int i=0;i<m;i++)
	{
		vec.pb( (query){vec[i].ang+2*3.14159265,vec[i].dif});
		vec.pb( (query){vec[i].ang+4*3.14159265,vec[i].dif});
	}
	sort(vec.begin(),vec.end());
	int res=0,cur=0;
	for(int i=0;i<vec.size();i++)
	{
		res = max(res,(cur+=vec[i].dif));
	}
	cout << res << endl;
}