#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		int Sum=0;
		for(int i=1;i<=n;i++){
			int x;scanf("%d",&x);
			Sum=Sum+(x-1);
		}
		if(Sum%2==0) printf("maomao90\n");
		else printf("errorgorn\n");
	}
	
	return 0;
}