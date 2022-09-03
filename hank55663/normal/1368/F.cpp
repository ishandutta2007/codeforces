#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int dp[1<<20];

int main() {
	int n;
	scanf("%d",&n);
	if(n<=3){
		printf("0\n");
		fflush(stdout);
		return 0;
	}
	int ans=0,ansi;
	for(int i = 1;i<=n;i++){
		int val=n/(i+1)*i;
		if(n%(i+1)!=0)val+=n%(i+1)-1;
		val-=i;
		if(val>ans){
			ans=val;
			ansi=i;
		}
	}
	//printf("%d\n",ans);
	set<int> s;
	for(int i = 1;i<=n;i++){
		if(i%(ansi+1)!=0&&i!=n)s.insert(i);
	}
	int lamp[1005];
	MEM(lamp);
	while(s.size()>ansi){
		vector<int> v;
		for(int i = 0;i<ansi+1;i++){
			v.pb(*s.begin());
			s.erase(s.begin());
			lamp[v.back()]=1;
		}
		printf("%d",v.size());
		for(auto it:v){
			printf(" %d",it);
		}
		printf("\n");
		fflush(stdout);
		int x=1;
		scanf("%d",&x);
		for(int j=x;j<x+v.size();j++){
			int a=(j-1)%n+1;
			if(lamp[a]){
				s.insert(a);
				lamp[a]=0;
			}
		}
	}
	printf("0\n");
	fflush(stdout);
	int cnt=0;
	for(int i =1;i<=n;i++){
		cnt+=lamp[i];
	}
//	assert(cnt==ans);
	return 0;
}