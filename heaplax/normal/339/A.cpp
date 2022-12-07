#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
int s[101],n;
int main()
{
	for(int i=1;scanf("%d+",&s[i])==1;i++,n++);
	sort(s+1,s+n+1);
	for(int i=1;i<=n-1;i++)
		cout<<s[i]<<"+";
	cout<<s[n]<<endl;
	return 0;
}