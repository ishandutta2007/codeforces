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
int p[210000];
int v[210000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",p+i);p[i]--;
	}
	int ret=0;
	int par=-1;
	int sec=-1;
	for(int i=0;i<a;i++){
		if(v[i])continue;
		int at=i;
		vector<int>vis;
		v[at]=2;
		vis.push_back(at);
		while(1){
			int to=p[at];
			if(v[to]==1)break;
			if(v[to]==2){
				if(to!=at){
					ret++;
					p[at]=-1;
					sec=at;
				}else{
					if(!~par){
						par=at;
					}else{
						ret++;
						p[at]=par;
					}
				}
				break;
			}
			v[to]=2;
			at=to;
			vis.push_back(to);
		}
		for(int j=0;j<vis.size();j++){
			v[vis[j]]=1;
		}
	}
	for(int i=0;i<a;i++){
		if(p[i]==-1){
			if(~par)p[i]=par;
			else p[i]=sec;
		}
	}
	printf("%d\n",ret);
	for(int i=0;i<a;i++){
		if(i)printf(" ");
		printf("%d",p[i]+1);
	}
	printf("\n");
}