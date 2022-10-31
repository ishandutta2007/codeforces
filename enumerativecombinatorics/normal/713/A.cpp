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
char in[20];
int c[1<<18];
int main(){
	int a;scanf("%d",&a);
	while(a--){
		scanf("%s",in);
		long long b;
		scanf("%I64d",&b);
		if(in[0]=='+'){
			int now=0;
			for(int i=0;i<18;i++){
				if(b%2)now+=(1<<i);
				b/=10;
			}
			c[now]++;
		}else if(in[0]=='-'){
			int now=0;
			for(int i=0;i<18;i++){
				if(b%2)now+=(1<<i);
				b/=10;
			}
			c[now]--;
		}else{
			int now=0;
			for(int i=0;i<18;i++){
				if(b%2)now+=(1<<i);
				b/=10;
			}
			printf("%d\n",c[now]);
		}
	}
}