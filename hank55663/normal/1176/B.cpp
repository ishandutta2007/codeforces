#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		int n;
		scanf("%d",&n);
		int cnt[3]={0,0,0};
		for(int i = 0;i<n;i++){
			int x;
			scanf("%d",&x);
			cnt[x%3]++;
		}
		int ans=min(cnt[1],cnt[2]);
		cnt[1]-=ans;
		cnt[2]-=ans;
		ans+=cnt[0]+cnt[1]/3+cnt[2]/3;
		printf("%d\n",ans);
	}
}
/*
aaaa
aaba
abaa
baaa
baba
*/