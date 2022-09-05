/*
	Author  : JZdavid
	From    : CF
	Problem : 198B
	Time    : 
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
int n,k,dis[2][100111];
string s[2];
struct node
{
	int h,p,d;
};
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	cin>>s[0]>>s[1];
	queue<node>q;
	node t;
	t.h=0;t.p=0;t.d=0;
	q.push(t);
	for(int i=0;i<n;i++)dis[0][i]=dis[1][i]=INF;
	dis[0][0]=0;
	while(!q.empty())
	{
		int u=q.front().h,p=q.front().p,d=q.front().d;
//		cout<<u<<" "<<p<<" "<<d<<endl;
		q.pop();
		if(u>=n)
		{
			puts("YES");
			return 0;
		}
		if(s[p][u+1]=='-'&&d+1<dis[p][u+1])
		{
			dis[p][u+1]=d+1;
			t.h=u+1;
			t.p=p;
			t.d=d+1;
			q.push(t);
		}
		if(s[p][u-1]=='-'&&u-1>=d+1&&d+1<dis[p][u-1])
		{
			dis[p][u-1]=d+1;
			t.h=u-1;
			t.p=p;
			t.d=d+1;
			q.push(t);
		}
		if(u+k>=n||(s[1-p][u+k]=='-'&&d+1<dis[1-p][u+k]))
		{
			if(u+k<n)dis[1-p][u+k]=d+1;
			t.h=u+k;
			t.p=1-p;
			t.d=d+1;
			q.push(t);
		}
	}
	puts("NO");
// 	system("pause");
	return 0;
}