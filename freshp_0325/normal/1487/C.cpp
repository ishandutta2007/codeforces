#include<bits/stdc++.h>
using namespace std;
int n,fkc[105];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)	fkc[i]=-1*(i>((n-1)>>1)?1:-1);
		if(!(n&1))	fkc[n/2]=0;
		for(int i=n;i;--i)	for(int j=1;j<i;++j)	printf("%d ",fkc[j]);
		puts("");
	}
	return 0;
}