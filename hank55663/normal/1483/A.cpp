#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define index Index
using namespace std;
bool solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	int cnt[100005];
	fill(cnt,cnt+n+1,0);
	vector<vector<int> > v;
	for(int i = 0;i<m;i++){
		int k;
		scanf("%d",&k);
		vector<int> tmp;
		for(int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			tmp.pb(x);
		}
		if(k==1)cnt[tmp[0]]++;
		v.pb(tmp);
	}
	for(int i = 1;i<=n;i++){
		if(cnt[i]>(m+1)/2){
			printf("NO\n");
			return true;
		}
	}
	printf("YES\n");
	for(int i =0;i<m;i++){
		if(v[i].size()==1)printf("%d ",v[i][0]);
		else{
			int ok=0;
			for(auto it:v[i]){
				if(cnt[it]<(m+1)/2){
					printf("%d ",it);
					cnt[it]++;
					ok=1;
					break;
				}
			}
			assert(ok);
		}
	}
	printf("\n");
	return true;
}
int main(){
	int t=1;//000000;
	scanf("%d",&t);
	while(t--)solve();
}