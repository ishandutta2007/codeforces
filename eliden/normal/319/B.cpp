#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 1e5;
int n, a[sz], l[sz], r[sz];
bool inq[sz];
int main()
{
	scanf("%d",&n);
	queue<pair<int,int>> q;
	rep(i,0,n)
	{
		scanf("%d",&a[i]);
		l[i]=i-1;
		r[i]=i+1;
		inq[i]=false;
		if(i>0 && a[i-1]>a[i])
		{
			q.push(make_pair(1,i));
			inq[i] = true;
		}
	}
	int t=0;
	while(!q.empty())
	{
		t=q.front().first;
		int i = q.front().second;
		//debug(i);
		q.pop();
		if(r[i]<n)
			l[r[i]]=l[i];
		if(l[i]>=0)
			r[l[i]]=r[i];
		if(r[i]<n && !inq[r[i]] && a[l[i]]>a[r[i]])
		{
			q.push(make_pair(t+1,r[i]));
			inq[r[i]]=true;
		}
	}
	printf("%d\n",t);
}