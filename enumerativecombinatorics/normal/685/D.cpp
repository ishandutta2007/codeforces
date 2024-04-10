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
int r[110000];
int c[110000];
pair<int,int>p[110000];
pair<int,int>ev[210000];
long long ret[110000];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		scanf("%d%d",r+i,c+i);
		ev[i*2+1]=make_pair(r[i],i+1);
		ev[i*2]=make_pair(r[i]+b,-i-1);
		p[i]=make_pair(c[i],r[i]);
	}
	std::sort(p,p+a);
	std::sort(ev,ev+a*2);
	int last=-mod;
	set<pair<int,pair<int,int> > > S;
	for(int i=0;i<a*2;i++){
	//	printf("%d: %d %d\n",i,ev[i].first,ev[i].second);
		if(i==0||ev[i].first!=ev[i-1].first){
			long long ks=ev[i].first-last;
			int las=-mod;
			int cnt=0;
			for(set<pair<int,pair<int,int> > >::iterator it=S.begin();it!=S.end();it++){
				if(it==S.begin()||((*it).first!=las)){

					if(cnt)ret[cnt]+=((long long)(*it).first-las)*ks;
					las=(*it).first;
				}
				cnt+=(*it).second.first;
			}
			last=ev[i].first;
		}
		if(ev[i].second>0){
			S.insert(make_pair(c[ev[i].second-1],make_pair(1,ev[i].second)));
			S.insert(make_pair(c[ev[i].second-1]+b,make_pair(-1,ev[i].second)));
		}else{
			S.erase(make_pair(c[-ev[i].second-1],make_pair(1,-ev[i].second)));
			S.erase(make_pair(c[-ev[i].second-1]+b,make_pair(-1,-ev[i].second)));
		}
	}
	for(int i=1;i<=a;i++){
		if(i!=1)printf(" ");
		printf("%I64d",ret[i]);
	}
	printf("\n");
}