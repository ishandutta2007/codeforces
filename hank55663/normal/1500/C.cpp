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
int mod;
LL vala[1505],valb[1505];
int a[1505][1505],b[1505][1505];
int rnum[1505];
int vis[1505];
int vis2[1505];
vector<int> v1[1505];
vector<int> v2[1505];
int degree[1505];
bool solve(){
	mod=rand()%1000000000+1000000000;
	while(true){
		int ok=1;
		for(int i = 2;i*i<=mod;i++){
			if(mod%i==0)ok=0;
		}
		if(ok)break;
		mod++;
	}
	int n,m;
	scanf("%d %d",&n,&m);


	MEM(vala),MEM(valb);
	MEMS(rnum);
	for(int i = 0;i<n;i++){
		for(int j =0;j<m;j++){
			scanf("%d",&a[i][j]);
			vala[i]=(vala[i]*(n+10)+a[i][j])%mod;
		}
	}
	int ok=1;
	for(int i = 0;i<n;i++){
		for(int j =0;j<m;j++){
			scanf("%d",&b[i][j]);
			if(b[i][j]!=a[i][j])ok=0;
			valb[i]=(valb[i]*(n+10)+b[i][j])%mod;
		}
	}
	if(ok){
		printf("0\n");
		return true;
	}
	for(int i = 0;i<n;i++){
		for(int j=0;j<n;j++){
			if(vala[i]==valb[j]&&!vis[j]){
				int ok=1;
				for(int k = 0;k<m;k++){
					if(a[i][k]!=b[j][k]){
						ok=0;
						break;
					}
				}
				if(ok){
					rnum[i]=j,vis[j]=1;
					break;
				}
			}
		}
		if(rnum[i]==-1){
			printf("-1\n");
			return true;
		}
	}
	for(int i = 0;i<n-1;i++){
		int x,y;
		for(int j =0;j<n;j++){
			if(rnum[j]==i)x=j;
			if(rnum[j]==i+1)y=j;
		}
		for(int j=0;j<m;j++){
			if(a[x][j]<a[y][j])v2[j].pb(x);
			if(a[x][j]>a[y][j])v1[x].pb(j),degree[j]++;
		}
	}
	vector<int> ans;
	queue<int> q;
	for(int i = 0;i<m;i++){
		if(degree[i]==0)q.push(i);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		ans.pb(x);
		for(auto it:v2[x]){
			if(!vis2[it]){
				vis2[it]=1;
				for(auto it2:v1[it]){
					if(--degree[it2]==0)q.push(it2);
				}
			}
		}
	}
	reverse(ans.begin(),ans.end());
	for(int i = 0;i<n-1;i++){
		int x,y;
		for(int j =0;j<n;j++){
			if(rnum[j]==i)x=j;
			if(rnum[j]==i+1)y=j;
		}
		int ok=0;
		if(x<y)ok=1;
		//printf("%d\n",ok);
		for(auto j:ans){
		//	printf("%d %d %d\n",j,a[x][j],a[y][j]);
			if(a[x][j]<a[y][j])ok=1;//v2[j].pb(x);
			if(a[x][j]>a[y][j])ok=0;//v1[x].pb(j),degree[j]++;
		}
		//printf("%d\n",i);
		if(!ok){
			printf("-1\n");
			return true;
		}
	}
	printf("%d\n",ans.size());
	for(auto it:ans)printf("%d ",it+1);
	printf("\n");
}
int main(){
	int t=1;//000000;
   
	while(t--)solve();
}