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
int dis[405][405];
vector<int> v[405];
bool solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=n;i++){
		for(int j =1;j<=n;j++){
			dis[i][j]=1e9;
		}
		dis[i][i]=0;
	}
	/*set<pii> s;
	for(int i = 1;i<n;i++){
		int x=i+1,y=rand()%i+1;
		v[x].pb(y);
		v[y].pb(x);
		dis[x][y]=dis[y][x]=1;
		s.insert(mp(x,y));
	}
	for(int i = n-1;i<m;i++){
		int x,y;
		while(true){
			x=rand()%n+1;
			while(true){
				y=rand()%n+1;
				if(y!=x)break;
			}
			if(x>y)swap(x,y);
			if(s.find(mp(x,y))==s.end()){
				s.insert(mp(x,y));
				break;
			}
		}
	//	int x,y;
	//	scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
		dis[x][y]=dis[y][x]=1;
	}*/
	for(int i = 0;i<m;i++){
			int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
		dis[x][y]=dis[y][x]=1;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int k =1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	const int mod=998244353;
//	printf("%d %d\n",dis[1][1],dis[2][1]);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			int tot=0;
			for(int k=1;k<=n;k++){
				if(dis[i][k]+dis[j][k]==dis[i][j])tot++;//printf("?%d %d %d?\n",i,j,k);
			}
			if(tot!=dis[i][j]+1){
				printf("0 ");
			}
			else{
				int vis[405];
				fill(vis,vis+n+1,0);
				int arr[405];
				int index=0;
				LL ans=1;
				for(int k = 1;k<=n;k++){
					if(dis[i][k]+dis[j][k]==dis[i][j]);
					else{//arr[index++]=k,vis[k]=1;
					int tot=0;
					for(auto it:v[k]){
						if(dis[i][it]+1==dis[i][k]&&dis[j][it]+1==dis[j][k])tot++;
					}
					ans=ans*tot%mod;
					//printf("?%d %d %d %d\n",i,j,k,tot);
					}
				}
				/*int tot=0;
				int now=0;
				while(now!=index){
					int x=arr[now++];//q.front();
					//q.pop();
					tot++;
					for(auto it:v[x]){
						if(!vis[it]){
							vis[it]=1;
							arr[index++]=it;
						//	q.push(it);
							int tot=0;
							for(auto it2:v[it]){
								if(dis[i][it2]+1==dis[i][it]&&dis[j][it2]+1==dis[j][it]){
									tot++;
								}
							}
							//printf("?%d %d %d %d\n",i,j,it,tot);
							ans*=tot;
							//if(ans>=1e15)
							//ans=ans%mod;
						}
					}
				}*/
				printf("%lld ",ans);
			
			}
		}
		printf("\n");
	}
}
/*
5 5
2 8
*/
int main(){
		//MEMS(dp);
	int t=1;0000;//000000;//000000;
    //scanf("%d",&t);
    //MEMS(dp);
	while(t--)solve();
}