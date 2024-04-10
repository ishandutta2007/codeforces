#include<bits/stdc++.h>
using namespace std;

int b[110];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		int tot=0;
		while(n) b[++tot]=n%10,n/=10;
		if(tot==2) printf("%d\n",b[1]);
		else{
			int Min=1e9;
			for(int i=1;i<=tot;i++)
				if(Min>b[i]) Min=b[i];
			printf("%d\n",Min);
		}
	}
	
	return 0;
}