#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int chk(int a,int b,int c,int d){
	if(a>c||b>d)return 0;
	printf("? %d %d %d %d\n",a,b,c,d);
	fflush(stdout);
	int ret;scanf("%d",&ret);
	return ret;
}
int val[4][2];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<4;i++){
		for(int j=0;j<2;j++){
			int left=0;
			int right=a+1;
			while(left+1<right){
				int M=(left+right)/2;
				int T,B,L,R;
				if(i==0){
					T=1;B=M;L=1;R=a;
				}else if(i==1){
					T=M;B=a;L=1;R=a;
				}else if(i==2){
					T=1;B=a;L=1;R=M;
				}else{
					T=1;B=a;L=M;R=a;
				}
				int val=chk(T,L,B,R);
				if(val>j){
					if(i%2==0){
						right=M;
					}else{
						left=M;
					}
				}else{
					if(i%2==0){
						left=M;
					}else right=M;
				}
			}
			if(i%2==0){
				val[i][j]=right;
			}else val[i][j]=left;
		}
	}
	for(int i=0;i<8;i++){
		if(chk(val[1][0],val[3][i/4],val[0][i%4/2],val[2][i%2])&&chk(val[1][1],val[3][!(i/4)],val[0][!(i%4/2)],val[2][!(i%2)])){
			printf("! %d %d %d %d %d %d %d %d\n",val[1][0],val[3][i/4],val[0][i%4/2],val[2][i%2],val[1][1],val[3][!(i/4)],val[0][!(i%4/2)],val[2][!(i%2)]);fflush(stdout);
			return 0;
		}
	}
}