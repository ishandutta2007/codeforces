#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int A,B,C;
		scanf("%d%d%d",&A,&B,&C);
		
		printf("%lld %d %d\n",A+(ll)B*1000000000,B,C);
	}
	
	return 0;
}