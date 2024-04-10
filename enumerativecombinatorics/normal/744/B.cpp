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
int ret[1100];

int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		ret[i]=mod;
	}
	for(int i=0;i<10;i++){
		vector<int>v;
		for(int j=0;j<a;j++)if(j&(1<<i)){
			v.push_back(j);
		}
		if(v.size()){
			printf("%d\n",(int)v.size());
			for(int j=0;j<v.size();j++){
				if(j)printf(" ");
				printf("%d",v[j]+1);
			}
			printf("\n");fflush(stdout);
			for(int j=0;j<a;j++){
				int f;scanf("%d",&f);
				if(!(j&(1<<i)))ret[j]=min(ret[j],f);
			}
		}
		v.clear();
		for(int j=0;j<a;j++)if(!(j&(1<<i))){
			v.push_back(j);
		}
		if(v.size()){
			printf("%d\n",(int)v.size());
			for(int j=0;j<v.size();j++){
				if(j)printf(" ");
				printf("%d",v[j]+1);
			}
			printf("\n");fflush(stdout);
			for(int j=0;j<a;j++){
				int f;scanf("%d",&f);
				if((j&(1<<i)))ret[j]=min(ret[j],f);
			}
		}
	}
	printf("-1\n");
	for(int i=0;i<a;i++){
		if(i)printf(" ");
		printf("%d",ret[i]);
	}
	printf("\n");fflush(stdout);
}