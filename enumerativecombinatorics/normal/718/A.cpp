#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
char in[210000];
char str[210000];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	scanf("%s",in);
	int ind=0;
	int sz=0;
	for(int i=0;i<a;i++){
		if(in[i]=='.')ind=i;
		else str[sz++]=in[i];
	}
	int one=0;
	for(int i=0;i<sz;i++){

		if(i>=ind&&str[i]>='5'&&str[i]<='9'){
			int at=i;
			while(b--){
				if(at<ind)break;
				if(str[at]>='5'&&str[at]<='9'){
					if(at==0){
						one++;
					}else{
						str[at-1]++;
						int t=at-1;
						while(str[t]>'9'){
							str[t]-=10;
							if(t==0){
								one=1;break;
							}
							else str[t-1]++;
							t--;
						}
					}
				}else break;
				sz=at;
				at--;
			}
			break;
		}
	}
	
	while(sz>ind){
		if(str[sz-1]=='0')sz--;
		else break;
	}
	if(one)printf("1");
	for(int i=0;i<sz;i++){
		if(i==ind)printf(".");
		printf("%c",str[i]);
		
	}printf("\n");
}