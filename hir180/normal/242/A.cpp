#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int x,y,m,n,sum=0;
	int w[100000][2];
	scanf("%d %d %d %d",&x,&y,&m,&n);
	for(int i=m;i<=x;i++){
		for(int j=n;j<=y;j++){
			if(i>j){
				w[sum][0]=i;
				w[sum][1]=j;
				sum++;
			}
		}
	}
	printf("%d\n",sum);
	for(int i=0;i<sum;i++){
		printf("%d %d\n",w[i][0],w[i][1]);
	}
	scanf("%d",&x);
	return 0;
}