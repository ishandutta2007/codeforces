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
const long long mod=1000010007;
const long long inf=mod*mod;
int c[510000];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	long long sum=0;
	for(int i=0;i<a;i++){
		scanf("%d",c+i);
		sum+=c[i];
	}
	std::sort(c,c+a);
	int left=0;
	int right=mod;
	while(left+1<right){
		int M=(left+right)/2;
		long long cur=0;
		for(int i=0;i<a;i++){
			if(c[i]<M)cur+=M-c[i];
		}
		if(b<cur){
			right=M;
		}else left=M;
	}
	int q1=left;
	left=0;
	right=mod;
	while(left+1<right){
		int M=(left+right)/2;
		long long cur=0;
		for(int i=0;i<a;i++){
			if(c[i]>M)cur+=c[i]-M;
		}
		if(b<cur){
			left=M;
		}else right=M;
	}
	int q2=right;
	if(q1>q2)q1=q2;
	if(q2-q1==0&&sum%a)q2++;
	printf("%d\n",q2-q1);
}