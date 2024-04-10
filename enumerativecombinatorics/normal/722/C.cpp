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
long long sum[110000];
int p[110000];
int L[110000];
int R[110000];
int q[110000];
long long ans[110000];
int v[110000];
int UF[110000];
vector<int> ct[110000];
long long tot[110000];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
long long cur=0;
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;
	if(UF[a]>UF[b])swap(a,b);
	for(int i=0;i<ct[b].size();i++)ct[a].push_back(ct[b][i]);
	tot[a]+=tot[b];
	cur=max(cur,tot[a]);
	ct[b].clear();
	UF[a]+=UF[b];UF[b]=a;
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",p+i);
	for(int i=0;i<a;i++){
		sum[i+1]=sum[i]+p[i];
	}
	for(int i=0;i<a;i++){
		scanf("%d",q+i);q[i]--;
	}
	for(int i=0;i<a;i++){
		UF[i]=-1;
		ct[i].push_back(p[i]);
		tot[i]=p[i];
	}
	for(int i=a-1;i>=0;i--){
		ans[i]=cur;
		v[q[i]]=1;
		cur=max(cur,tot[FIND(q[i])]);
		if(q[i]&&v[q[i]-1]){
			UNION(q[i],q[i]-1);
		}
		if(q[i]<a-1&&v[q[i]+1]){
			UNION(q[i],q[i]+1);
		}
	}
	for(int i=0;i<a;i++)printf("%I64d\n",ans[i]);
}