#include<stdio.h>
#include<algorithm>
using namespace std;
int SQ=600;
int b[300000];
long long c[601][601];
long long ans[300000];
pair<pair<int,int> ,int> query[300000];
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",b+i);
	}
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int p,q;
		scanf("%d%d",&p,&q);
		query[i]=make_pair(make_pair(p-1,q),i);
	}
	std::sort(query,query+n);
	int at=a-1;
	for(int i=n-1;i>=0;i--){
		while(at>=query[i].first.first){
			for(int j=1;j<SQ;j++){
				c[j][at%j]+=b[at];
			}
			at--;
		}
		if(query[i].first.second<SQ){
			ans[query[i].second]=c[query[i].first.second][query[i].first.first%query[i].first.second];
		}else{
			for(int j=query[i].first.first;j<a;j+=query[i].first.second)ans[query[i].second]+=b[j];
		}
	}
	for(int i=0;i<n;i++)printf("%I64d\n",ans[i]);
}