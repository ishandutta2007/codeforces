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
int n,a[1001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int q;
		cin>>q;
		a[q]=i;
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}