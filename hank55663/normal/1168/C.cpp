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
#define next Next
int go[300005][20];
vector<int> v[20];
int a[300005];
vector<int> next[300005];
int n;
int GO(int x,int y){
	if(go[x][y]!=-1)return go[x][y];
	if(a[x]&(1<<y))return go[x][y]=x;
	int Min=n+1;
	for(auto it:next[x]){
		Min=min(Min,GO(it,y));
	}
	return go[x][y]=Min;
}
int main(){
	MEMS(go);
	int q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j = 0;j<20;j++){
			if(a[i]&(1<<j))
				v[j].pb(i);
		}
	}	
	//printf("?\n");
	for(int i = 0;i<20;i++){
		
		for(int j = 0;j+1<v[i].size();j++){
			//printf("%d %d %d %d\n",i,j,v[i].size(),v[i][j]);
			//printf("%d\n",v[i][j+1]);
			next[v[i][j]].pb(v[i][j+1]);
			//printf("?\n");
		}
	//	printf("%d\n",i);
	}
//	printf("?\n");
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		int Min=n+1;
		for(int i = 0;i<20;i++){
			if(a[y]&(1<<i)){
				Min=min(Min,GO(x,i));
			}
		}
		if(Min<=y){
			printf("Shi\n");
		}
		else{
			printf("Fou\n");
		}
	}
}