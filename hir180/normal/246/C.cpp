#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int n,m,num=0,ans=0,sum=0,i=0;
int bea[55];
bool a=false;
/*('')*/
int main(){
	scanf("%d %d",&n,&m);
	for(int t=0;t<n;t++){
		scanf("%d",&bea[t]);
	}
	sort(bea,bea+n);
	vector<int>vec;
	for(int eiei=1;eiei<=n;eiei++){
		for(int j=0;j<n+1-eiei;j++){
			printf("%d",eiei);
			for(int k=0;k<eiei-1;k++){
				printf(" %d",bea[n-1-k]);
			}
			printf(" %d",bea[j]);
			printf("\n");
			i++;
			if(i==m){
				goto end;
			}
		}
	}
end:;
		scanf("%d",&n);
		return 0;
}