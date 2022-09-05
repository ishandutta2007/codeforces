#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
#define y0 qgoiqoeinfoiqwef
#define y1 vmpoqmeppjofaqoi
#define yn qoigmnioqonfopiq
int n,st=-1<<30,ed=1<<30;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		string s;
		char is;int x;
		cin>>s;
		scanf("%d %c",&x,&is);
		if(is=='N')
		{
			if(s[0]=='<')s[0]='>';else s[0]='<';
			if(s[1]=='=')s[1]=' ';else s[1]='=';
		}
		if(s[0]=='<')
		{
			if(s[1]=='=')ed=min(ed,x);else ed=min(ed,x-1);
		}
		else if(s[0]=='>')
		{
			if(s[1]=='=')st=max(x,st);else st=max(st,x+1);
		}
	}
	if(st>ed)cout<<"Impossible";else cout<<st;
	return 0;
}