#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,x,a[100005],b[100005];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d %d",&n,&x);
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
		memcpy(b,a,sizeof a);
		sort(a+1,a+1+n);
		for(int i=n-x+1;i<=x;++i)	if(a[i]!=b[i])	{puts("NO");goto fail;}
		puts("YES");
		fail:;
	}
	return 0;
}