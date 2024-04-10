#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int i,j,k,a,b,c,d,y,z,sum=1,maxi=0;
int x[1000000][2];
int main(){
/*(^(^(^(^(^o^)^)^)^)^) sssssssssssss('') */
	scanf("%d",&a);
	scanf("%d %d",&x[0][0],&x[0][1]);
	for(i=1;i<a;i++){
		scanf("%d %d",&x[i][0],&x[i][1]);
		if(x[i-1][0]==x[i][0] && x[i-1][1]==x[i][1]){
			sum++;
			
		}else{
			maxi=max(sum,maxi);
			sum=1;
		}
	}
maxi=max(sum,maxi);
sum=1;
	printf("%d\n",maxi);
	return 0;
}