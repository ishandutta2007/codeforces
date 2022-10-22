#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) printf("%d ",i+1);
		printf("\n");
	}
	
	return 0;
}