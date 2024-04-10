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
int main(){
	int a;scanf("%d",&a);
	for(int i=1;i<=10000;i++){
		int c=a*i+1;
		bool ok=false;
		for(int j=2;j*j<=c;j++){
			if(c%j==0){
				ok=true;break;
			}
		}
		if(ok){
			printf("%d\n",i);return 0;
		}
	}
}