#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int p[11000][4];
int mat[110][110];
int main(){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<c;i++){
		scanf("%d%d",&p[i][0],&p[i][1]);
		p[i][1]--;
		if(p[i][0]==3){
			scanf("%d%d",&p[i][2],&p[i][3]);
			p[i][2]--;
		}
	}
	for(int i=c-1;i>=0;i--){
		if(p[i][0]==3){
			mat[p[i][1]][p[i][2]]=p[i][3];
		}else if(p[i][0]==2){
			int tmp=mat[a-1][p[i][1]];
			for(int j=a-1;j>0;j--){
				mat[j][p[i][1]]=mat[j-1][p[i][1]];
			}
			mat[0][p[i][1]]=tmp;
		}else{
			int tmp=mat[p[i][1]][b-1];
			for(int j=b-1;j>0;j--){
				mat[p[i][1]][j]=mat[p[i][1]][j-1];
			}
			mat[p[i][1]][0]=tmp;
		}
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(j)printf(" ");
			printf("%d",mat[i][j]);
		}
		printf("\n");
	}
}