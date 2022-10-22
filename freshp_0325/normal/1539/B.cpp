#include<bits/stdc++.h>
using namespace std;
int sum[100005],n,q;
char s[100005];
int main(){
	scanf("%d %d",&n,&q);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)	sum[i]=sum[i-1]+(s[i]-'a'+1);
	while(q-->0)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",sum[r]-sum[l-1]);
	}
	return 0;
}