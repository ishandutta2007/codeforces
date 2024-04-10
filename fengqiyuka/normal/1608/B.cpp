#include<cstdio>
#include<cstring>
using namespace std;

int abs(int x){
	if(x<0) return -x;
	return x;
}
int Ans[1100000];

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n,A,B;
		scanf("%d%d%d",&n,&A,&B);
		if(A+B>n-2||abs(A-B)>1){
			printf("-1\n");
			continue;
		}
		int t=A+B+1;
		if(A>B){
			for(int i=1;i<=n-t;i++) Ans[i]=i;
			int st=n;
			for(int i=n-t+1;i<=n;i+=2) Ans[i]=st,st--;
			st=n-t+1;for(int i=n-t+2;i<=n;i+=2) Ans[i]=st,st++;
		}
		else{
			for(int i=1;i<=n-t;i++) Ans[i]=n-i+1;
			int st=1;
			for(int i=n-t+1;i<=n;i+=2) Ans[i]=st,st++;
			st=t;for(int i=n-t+2;i<=n;i+=2) Ans[i]=st,st--;
		}
		for(int i=1;i<=n;i++) printf("%d ",Ans[i]);
		printf("\n");
	}
	
	return 0;
}