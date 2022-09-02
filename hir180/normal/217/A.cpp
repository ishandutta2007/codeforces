#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int n;
int cost[101][101];
int mincost[101];
bool used[101];
int ver;	
int main(){
	scanf("%d",&n);
	ver=n;
	vector<int>p,q;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		p.pb(a);
		q.pb(b);
	}
	for(int i=0;i<ver;i++){
		for(int j=0;j<ver;j++){
			cost[i][j]=1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(p[i]==p[j] || q[i]==q[j]){
				cost[i][j]=0;
				cost[j][i]=0;
			}
		}
	}
	for(int i=0;i<ver;i++){
		used[i]=false;
		mincost[i]=50000000;
	}
	mincost[0]=0;
	int ans=0;
	while(1){
		int ryu=-1;
		for(int i=0;i<ver;i++){
			if(!used[i] && (ryu==-1 || mincost[i]<mincost[ryu])){
				ryu=i;
			}
		}
		if(ryu==-1) break;
		used[ryu]=true;
		ans+=mincost[ryu];
		for(int i=0;i<ver;i++){
			mincost[i]=min(mincost[i],cost[ryu][i]);
		}
	}
	printf("%d\n",ans);
}