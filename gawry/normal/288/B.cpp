#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,t[8],ans=0;
const int MOD=1000000007;
void go(int next){
	if(next==k){
		int b[8]={},cur=0,nr=3;
		while(b[cur]<3){
			++b[cur];
			cur=t[cur];
		}
		if(b[0]==1)return;
		for(int i=0;i<k;i++)if(!b[i]){
			cur=i;
			bool seen=false;
			++nr;
			while(!b[cur]){
				b[cur]=nr;
				cur=t[cur];
			}
			if(b[cur]==nr)return;
		}
//		for(int i=0;i<k;i++)printf("%d ",t[i]);puts("");
		++ans;
	}else for(t[next]=0;t[next]<k;t[next]++){
		go(next+1);
	}
}
main(){
	scanf("%d %d",&n,&k);
	go(0);
	for(int i=0;i<n-k;i++)ans=(long long)ans*(n-k)%MOD;
	printf("%d\n",ans);
}