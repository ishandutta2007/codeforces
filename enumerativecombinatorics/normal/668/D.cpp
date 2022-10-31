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
int x[110000];
int b[110000];
int t[110000];
int z[110000];
vector<int>q[110000];
int bit[110000];
int sz;
int sum(int a,int b){
	if(a)return sum(0,b)-sum(0,a-1);
	int ret=0;
	for(;b>=0;b=(b&(b+1))-1)ret+=bit[b];
	return ret;
}
void add(int a,int b){
	for(;a<sz;a|=a+1)bit[a]+=b;
}
int z2[110000];
int ans[110000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d%d%d",b+i,t+i,x+i);
		z[i]=x[i];
	}
	std::sort(z,z+a);
	for(int i=0;i<a;i++){
		int at=lower_bound(z,z+a,x[i])-z;
		q[at].push_back(i);
	}
	for(int i=0;i<a;i++){
		if(q[i].size()){
			sz=q[i].size();
			for(int j=0;j<q[i].size();j++){
				z2[j]=t[q[i][j]];
			}
			std::sort(z2,z2+sz);
			for(int j=0;j<q[i].size();j++){
				int ind=lower_bound(z2,z2+sz,t[q[i][j]])-z2;
				if(b[q[i][j]]==1){
					add(ind,1);
				}else if(b[q[i][j]]==2){
					add(ind,-1);
				}else{
					ans[q[i][j]]=sum(0,ind);
				}
			}
			for(int j=0;j<sz;j++)bit[j]=0;
		}
	}
	for(int i=0;i<a;i++){
		if(b[i]!=3)continue;
		printf("%d\n",ans[i]);
	}
}