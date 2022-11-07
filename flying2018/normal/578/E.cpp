#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define N 100010
using namespace std;
char str[N];
set<int>s[2];
int ans[N],ta;
int main()
{
	scanf("%s",str+1);
	int n=strlen(str+1);
	for(int i=1;i<=n;i++) s[str[i]=='L'].insert(i);
	s[0].insert(n+1),s[1].insert(n+1);
	if(s[0].size()<s[1].size() || (s[0].size()==s[1].size() && *s[0].begin()>*s[1].begin())) swap(s[0],s[1]);
	bool p=0;
	int cnt=0,pos=-1,nxt=*s[0].begin();
	for(int i=1;i<=n;i++,p=!p)
	{
		if(nxt>n || (*s[!p].lower_bound(nxt)>n && *s[p].begin()!=nxt && *s[p].begin()<*s[!p].begin())) nxt=*s[p].begin(),++cnt;
		pos=nxt;
		s[p].erase(pos);
		nxt=*s[!p].lower_bound(pos);
		ans[++ta]=pos;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=ta;i++) printf("%d ",ans[i]);
	return 0;
}