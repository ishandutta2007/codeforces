#include<iostream>
#include<queue>
using namespace std;
int n,q,v;
int mini[51],maxi[51];
int cap[2552][2552],cost[2552][2552];
int dis[2552];
int last[2552];
bool inq[2552];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<=n ;i++){
		mini[i]=1;
		maxi[i]=n;
	}
	for(int i=1; i<=q ;i++){
		int t,l,r,v;
		cin >> t >> l >> r >> v;
		for(int j=l; j<=r ;j++){
			if(t==1) mini[j]=max(mini[j],v);
			else maxi[j]=min(maxi[j],v);
		}
	}
	v=n+2+n*n;
	//build graph
	for(int i=1; i<=n ;i++){
		cap[0][i]=1;
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			cap[i*n+j][v-1]=1;
			cost[i*n+j][v-1]=j*2-1;
			cost[v-1][i*n+j]=-(j*2-1);
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=mini[i]; j<=maxi[i] ;j++){
			for(int k=1; k<=n ;k++){
				cap[i][j*n+k]=1;
			}
		}
	}
	int ans=0;
	int f=0;
	while(true){
		for(int i=1; i<v ;i++) dis[i]=1e9;
		dis[0]=0;
		queue<int>qq;
		qq.push(0);
		inq[0]=true;
		while(!qq.empty()){
			int cur=qq.front();
			inq[cur]=false;
			qq.pop();
			for(int i=0; i<v ;i++){
				if(cap[cur][i]>0 && dis[cur]+cost[cur][i]<dis[i]){
					dis[i]=dis[cur]+cost[cur][i];
					last[i]=cur;
					if(!inq[i]){
						inq[i]=true;
						qq.push(i);
					}
				}
			}
		}
		if(dis[v-1]==1e9){
			if(f!=n){
				cout << -1 << endl;
				return 0;
			}
			break;
		}
		f++;
		int cur=v-1;
		while(cur!=0){
			ans+=cost[last[cur]][cur];
			cap[last[cur]][cur]--;
			cap[cur][last[cur]]++;
			cur=last[cur];
		}
		
	}
	cout << ans << endl;
	return 0;
}