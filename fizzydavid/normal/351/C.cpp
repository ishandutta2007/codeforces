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
#define push_back pb
#define make_pair mp
struct S
{
	int k,v;
	bool operator<(const S &t)const{return v>t.v;}
};
priority_queue<S>pq;
int a[22],b[22],mark[22],n,m;
long long t[22],res;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	int cnt=0;
	long long cost=0;
	for(int i=0,j=0;i<3*n;i++,j=(j<n-1)?(j+1):0)
	{
		cnt--;
		S tmps;tmps.k=j,tmps.v=a[j]-b[j];
		if(!mark[j]++)pq.push(S(tmps));
		cost+=b[j];
		if(cnt<0)
		{
			S t=pq.top();
			if(!--mark[t.k])pq.pop();
			cost+=t.v;
			cnt+=2;
		}
		if((i+1)%n==0)t[i/n]=cost;
	}
	m--;
	res+=(t[2]-t[0])*(m/2)+t[1];
	cout<<res;
// 	system("pause");
	return 0;
}