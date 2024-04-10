#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,z;scanf("%d%d",&n,&z);
		
		int Max=0;
		for(int i=1;i<=n;i++){
			int x;scanf("%d",&x);
			int t=(x|z);
			if(Max<t) Max=t;
		}
		printf("%d\n",Max);
	}
	return 0;
}