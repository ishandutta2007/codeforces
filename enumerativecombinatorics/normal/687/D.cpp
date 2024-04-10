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
int UF[2100];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;
	if(UF[a]>UF[b])swap(a,b);
	UF[a]+=UF[b];UF[b]=a;
}
pair<pair<int,int>,pair<int,int> >edge[510000];
int main(){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<b;i++){
		int p,q,r;scanf("%d%d%d",&p,&q,&r);
		p--;q--;
		edge[i]=make_pair(make_pair(-r,i),make_pair(p,q));
	}
	std::sort(edge,edge+b);
	while(c--){
		int l,r;scanf("%d%d",&l,&r);l--;r--;
		for(int i=0;i<a*2;i++)UF[i]=-1;
		int ans=-1;
		for(int i=0;i<b;i++){
			if(edge[i].first.second>r||edge[i].first.second<l)continue;
			UNION(edge[i].second.first,edge[i].second.second+a);
			UNION(edge[i].second.second,edge[i].second.first+a);
			if(FIND(edge[i].second.first)==FIND(edge[i].second.first+a)){
				ans=-edge[i].first.first;break;
			}
			if(FIND(edge[i].second.second)==FIND(edge[i].second.second+a)){
				ans=-edge[i].first.first;break;
			}
			
		}
		printf("%d\n",ans);
	}
}