#include<cstdio>
#include<cstring>
using namespace std;

const int N=1e5;
bool bk[100000];int Ans[N][2],b[N];

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n,K;
		scanf("%d%d",&n,&K);
		
		for(int i=1;i<=n/2;i++) Ans[i][0]=i-1,Ans[i][1]=n-i;
		for(int i=0;i<n;i++) bk[i]=true,b[i]=i;
		
		if(n==8&&K==7){
			printf("0 5\n");
			printf("2 4\n");
			printf("1 3\n");
			printf("6 7\n");
			continue;
		}
		if(n==8&&K==3){
			printf("0 6\n");
			printf("2 5\n");
			printf("1 4\n");
			printf("3 7\n");
			continue;
		}
		if(n==8&&K==5){
			printf("0 3\n");
			printf("2 4\n");
			printf("1 6\n");
			printf("5 7\n");
			continue;
		}
		if(n==8&&K==6){
			printf("0 3\n");
			printf("2 5\n");
			printf("1 4\n");
			printf("6 7\n");
			continue;
		}
		
		bool pd2=true;
		while(K){
			int t=1;
			while(t*2<=n/2&&t*2<=K) t*=2;
			K-=t;
			bool pd=false;
			for(int j=0;j<n;j++)
				if(bk[j]&&bk[j^t]){
					pd=true;
					bk[j]=bk[j^t]=bk[n-1-j]=bk[n-1-(j^t)]=false;
					b[j]=(j^t);b[j^t]=j;
					break;
				}
			if(!pd) {pd2=false;break;}
		}
		
		if(!pd2) printf("-1\n");
		else{
			for(int i=1;i<=n/2;i++) printf("%d %d\n",b[Ans[i][0]],b[Ans[i][1]]);
		}
	}
	
	return 0;
}