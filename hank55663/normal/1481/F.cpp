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
using namespace std;
vector<int> v[100005];
int cnt[100005];
int d[100005];
int Max;
void dfs(int x,int f){
	d[x]=d[f]+1;
	cnt[d[x]]++;
	Max=max(Max,d[x]);
	for(auto it:v[x]){
		if(it!=f){
			dfs(it,x);
		}
	}
}
char val[100005];
int dp[100005];
int from[100005];
bool check(int n,int x){
	map<int,vector<int> > m;
	for(int i = 1;i<=n;i++){
		if(cnt[i]){
			m[cnt[i]].pb(i);
		}
	}
	dp[0]=1;
	for(auto &it:m){
		for(int j = 0;j<it.x;j++){
			int cnt=0;
			for(int k=j;k<=n;k+=it.x){
				if(dp[k])cnt=it.y.size();
				else if(cnt){
					dp[k]=1;
					cnt--;
					from[k]=it.y[cnt];
				}
			}
		}
	}
	return dp[x];
}
void solve(){
	int n,x;
	scanf("%d %d",&n,&x);
	for(int i = 2;i<=n;i++){
		int p;
		scanf("%d",&p);
		v[p].pb(i);
	}
	dfs(1,0);
	if(check(n,x)){
		printf("%d\n",Max);
		for(int i = 1;i<=n;i++)val[i]='b';
		while(x){
			val[from[x]]='a';
			x-=cnt[from[x]];
		}
		for(int i = 1;i<=n;i++){
			printf("%c",val[d[i]]);
		}
		printf("\n");
	}
	else{
		printf("%d\n",Max+1);
		for(int i = 1;i<=n;i++){
			if(x>=cnt[i]){
				x-=cnt[i];
				val[i]='a';
			}
			else{
				val[i]='b';
			}
		}
		int leaf;
		
		for(int i = n;i>=1;i--){
			if(val[i]=='b'){
				leaf=i;
				break;
			}
		}
		for(int i = 1;i<=n;i++){
			if(v[i].size()){
				printf("%c",val[d[i]]);
			}
			else{
				if(d[i]==leaf&&x){
					printf("a");
					x--;
				}
				else{
					printf("%c",val[d[i]]);
				}
			}
		}
		printf("\n");
	}
}
int main(){
    int t=1;//00000;
    //scanf("%d",&t);
    while(t--)solve();
}
/*

*/