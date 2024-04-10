#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
			if(k%n==0){
			printf("0\n");
		}
		else{
			printf("2\n");
		}
		int ans[305][305];
		for(int i = 0;i<n;i++){
			for(int j=0;j<n;j++){
				if(k){
				ans[j][(j+i)%n]=1;
				k--;
				}
				else
				ans[j][(j+i)%n]=0;
			//	printf("%d\n",k);
			}
		}
	
		for(int i =0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}

	}
	return 0;
}