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
bool pr(int a){
	for(int i=2;i*i<=a;i++){
		if(a%i==0)return false;
	}
	return true;
}
int main(){
	int a;scanf("%d",&a);
	if(a%2==0){
		if(a==2)printf("1\n");
		else printf("2\n");return 0;
	}
	if(pr(a))printf("1\n");
	else if(pr(a-2))printf("2\n");
	else printf("3\n");
}