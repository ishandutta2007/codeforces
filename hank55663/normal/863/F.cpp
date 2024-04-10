#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
int val[205][205];
int upper[205];
int lower[205];
int f[205][205];
int Flow(int s,int t){
	int res=0;
	int flow=0;
	do{
		flow=0;
		queue<pii> q;
		while(!q.empty())
		q.pop();
		q.push(mp(s,1e9));
		int fa[205];
		int vis[205];
		MEM(vis);
		vis[s]=1;
		while(!q.empty()){
			pii p=q.front();
			q.pop();
			vis[p.x]=1;
			if(p.x==t){
				flow=p.y;
				break;
			}
			for(int i=0;i<205;i++)
			if(val[p.x][i]-f[p.x][i]>0){
				if(vis[i])
				continue;
				fa[i]=p.x;
				q.push(mp(i,min(p.y,val[p.x][i]-f[p.x][i])));
			} 
		}
		int k=t;
		while(k!=s){
			f[fa[k]][k]+=flow;
			f[k][fa[k]]-=flow;
			k=fa[k];
		}
		res+=flow;
	//	printf("%d",flow);
	}while(flow!=0);
	return res;
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		upper[i]=n;
		lower[i]=1;
	}
	while(q--){
		int op,l,r,v;
		scanf("%d %d %d %d",&op,&l,&r,&v);
		for(int i=l;i<=r;i++){
			if(op==1){
				lower[i]=max(lower[i],v);
			}
			else{
				upper[i]=min(upper[i],v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(lower[i]>upper[i]){
			printf("-1\n");
			return 0;
		}
	}
	int ans=0,last=0;
	for(int i=1;last!=n;i+=2){
		MEM(val);
		MEM(f);
		for(int j=1;j<=n;j++)
		val[0][j]=(i+1)/2;
		for(int j=n+1;j<=2*n;j++){
			val[j][2*n+1]=1;
		}
		for(int j=1;j<=n;j++)
			for(int k=n+1;k<=2*n;k++)
				if(lower[k-n]<=j&&upper[k-n]>=j)
				val[j][k]=1;
		int flow=Flow(0,2*n+1);
		ans+=i*(flow-last);
	//	printf("%d",flow);
	//	printf("\n");
		last=flow;
	}
	printf("%d\n",ans);
}
/*3 2 6 5 4 1
1 3 2 6 5 4*/