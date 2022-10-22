#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
map<int,bool> M;
int n,a[1005],sum[1005];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
		M.clear();
		for(int i=1;i<=n;++i)
		{
			if(M[a[i]])
				{
					puts("Yes");
					goto shuijiao;
				}
			M[a[i]]=true;
		}
		puts("No");
		shuijiao:;
	}
	return 0;
}