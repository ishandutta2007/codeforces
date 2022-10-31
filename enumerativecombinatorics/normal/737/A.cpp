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
pair<int,int> p[210000];
int f[210000];
int g[210000];

int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int ret=mod;
	for(int i=0;i<a;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		p[i]=make_pair(y,x);
	}
	std::sort(p,p+a);
	for(int i=0;i<b;i++)scanf("%d",f+i);
	f[b]=c;
	std::sort(f,f+b+2);
	for(int i=0;i<b+1;i++){
		g[i]=f[i+1]-f[i];
	}
	std::sort(g,g+b+1);
	b++;
	int at=0;
	long long tn=0;
	long long al=0;
	for(int i=0;i<b;i++)tn+=g[i];
	tn*=3;
	for(int i=0;i<a;i++){
		if(g[b-1]>p[i].first)continue;
		while(at<b&&g[at]*2<=p[i].first){
			tn-=3LL*g[at];
			al+=g[at];
			at++;
		}
		long long cost=al+tn-(long long)(b-at)*p[i].first;

		//printf("%d: %d %I64d %d %d\n",i,at,tn,al,cost);
		if(cost<=d)ret=min(ret,p[i].second);
	}
	if(ret==mod)ret=-1;
	printf("%d\n",ret);
}