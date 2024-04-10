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
char in[510];
int main(){
	int a;scanf("%d",&a);
	int at=0;
	while(a--){
		int b;scanf("%d%s",&b,in);
		if(in[0]=='S'){
			if(at+b>20000){
				printf("NO\n");return 0;
			}
			at+=b;
		}else if(in[0]=='N'){
			if(at-b<0){
				printf("NO\n");return 0;
			}
			at-=b;
		}else{
			if(at==0||at==20000){
				printf("NO\n");return 0;
			}
		}
	}
	if(at==0)printf("YES\n");else printf("NO\n");
}