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
const int INF=1<<28;
int main()
{
	set<int> s1,s2;
	set<pair<int,int> >s3;
	for(int i=1;i<=8;i++)
	{
		int x,y;
		cin>>x>>y;
		s1.insert(x);s2.insert(y);
		s3.insert(make_pair(x,y));
	}
	if(s1.size()==3&&s2.size()==3&&s3.size()==8)
	{
		int a=*(++s1.begin()),b=*(++s2.begin());
		if(s3.find(make_pair(a,b))==s3.end())puts("respectable");else puts("ugly");
	}
	else puts("ugly");
// 	system("pause");
	return 0;
}