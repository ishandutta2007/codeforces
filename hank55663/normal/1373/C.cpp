#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		char c[1000005];
		scanf("%s",c+1);
		int pre[1000005];
		pre[0]=0;
		for(int i = 1;c[i]!=0;i++){
			if(c[i]=='-')pre[i]=pre[i-1]-1;
			else pre[i]=pre[i-1]+1;
		}
		map<int,int> m;
		for(int i = 1;c[i]!=0;i++){
			if(pre[i]<0&&m.find(-pre[i])==m.end()){
				m[-pre[i]]=i;
			}
		}
		LL ans=0;
		for(auto it:m){
			ans+=it.y;
		}
		ans+=strlen(c+1);
		printf("%lld\n",ans);
	}
	return 0;
}