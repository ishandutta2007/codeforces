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
#define sqr(X) ((X)*(X))
int p[]={0,1,2,3,4,5,6,7,8};
int x[9],y[9];
bool dp(int a,int b,int c)
{
	if((x[p[a]]-x[p[b]])*(x[p[c]]-x[p[b]])+(y[p[a]]-y[p[b]])*(y[p[c]]-y[p[b]])==0)return 1;else return 0;
}
int dis(int a,int b)
{
	return sqr(x[p[a]]-x[p[b]])+sqr(y[p[a]]-y[p[b]]);
}
int main()
{
	for(int i=1;i<=8;i++)cin>>x[i]>>y[i];
	do
	{
		if(dp(1,2,3)&&dp(2,3,4)&&dp(3,4,1)&&dis(1,2)==dis(2,3)&&dis(3,4)&&dp(5,6,7)&&dp(6,7,8)&&dp(7,8,5))
		{
			cout<<"YES\n";
			for(int j=1;j<=4;j++)cout<<p[j]<<" ";cout<<endl;
			for(int j=5;j<=8;j++)cout<<p[j]<<" ";cout<<endl;
//			system("pause");
			return 0;
		}
	}
	while(next_permutation(p+1,p+9));
 	cout<<"NO"<<endl;
//	system("pause");
	return 0;
}