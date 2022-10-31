#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;

int main(){
	int a;scanf("%d",&a);
	int H,M;
	scanf("%d:%d",&H,&M);
	if(a==24){
		if(H>23){
			H%=10;
		}
	}else{
		if(H==0){
			H=1;
		}else if(H>12){
			if(H%10)H%=10;
			else H=10;
		}
	}
	if(M>=60){
		M%=10;
	}
	printf("%02d:%02d\n",H,M);
}