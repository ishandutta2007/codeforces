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
set<string>S;
char in[510];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		scanf("%s",in);
		string ss=in;
		S.insert(in);
	}
	int c=0;
	for(int i=0;i<b;i++){
		scanf("%s",in);
		string ss=in;
		if(S.count(in)){
			c++;
		}
	}
	//printf("%d %d %d\n",a,b,c);
	int t=0;
	while(1){
		if(t%2==0){
			if(a==0){
				printf("NO\n");return 0;
			}
			if(c){
				c--;
				a--;b--;
			}else a--;
		}else{
			if(b==0){
				printf("YES\n");return 0;
			}
			if(c){
				c--;a--;b--;
			}else b--;
		}
		t++;
	}
}