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
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define mod 1000000007
int a,b,n;

ll combi(ll v,ll c){
	int i;
	const int num=1000005;
	static ll rev[num+1],revt[num+1];
	if(rev[1]==0) {
		rev[1]=1; for(i=2;i<=num;i++) rev[i]=rev[mod%i]*(mod-mod/i)%mod;
		revt[0]=1; for(i=1;i<=num;i++) revt[i]=revt[i-1]*rev[i]%mod;
	}
	ll ret=revt[c];
	for(int i=0;i<c;i++) ret = (ret * ((v-i)%mod))%mod;
	return ret;
}

int main()
{
	scanf("%d %d %d",&a,&b,&n);
	vector<int>exc;
	queue<int>que;
	que.push(a);
	que.push(b);
	while(!que.empty())
	{
		int r=que.front();
		que.pop();
		if(r>b*n)
		{
			continue;
		}
		if(r>=a*n) exc.pb(r);
		r*=10;
		que.push(r+a);
		que.push(r+b);
	}
	exc.erase(unique(exc.begin(),exc.end()),exc.end());
	if(a==b)
	{
			int ret=0;
			for(int i=0;i<exc.size();i++)
			{
				if(exc[i]==n*a)
				{
					ret++;
				}
			}
			printf("%d\n",ret);
			return 0;
	}
	long long ret=0;
	for(int i=0;i<exc.size();i++)
	{
		if(exc[i]-a*n>=0 && (exc[i]-a*n)%(b-a)==0)
		{
			int x=(exc[i]-a*n)/(b-a);
			int y=n-x;
			ret+=combi(x+y,min(x,y));
			ret%=mod;
		}
	}
	cout << ret << endl;
	return 0;
}