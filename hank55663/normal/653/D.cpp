#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pb(x) push_back(x)
#define x first
#define y second
#define N 100005
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define pi 3.14159265359
typedef long long LL	;
using namespace std;
const int mod = 1e9+7;
LL c[305][305];
LL f[305][305];
int BFS(int s,int t,int n){
	queue<int> q;
	q.push(s);
	int p[305];
	int visit[305];
	LL flow[305];
//	flow[s]=1e9;
	memset(p,0,sizeof(p));
	memset(visit,0,sizeof(visit));
	memset(flow,0,sizeof(flow));
	flow[s]=1e9;
	while(!q.empty()){
		int a=q.front();q.pop();
	//	printf("%d\n",a);
		if(a==t)
		break;
		for(int i=1;i<=n;i++)
		if(c[a][i]>f[a][i]&&visit[i]==0){
			visit[i]=1;
			p[i]=a;
			q.push(i);
			flow[i]=min(flow[a],c[a][i]-f[a][i]);
		}
	}
	if(flow[t]==0)
	return 0;
	for(int i=t;i!=s;i=p[i]){
		f[p[i]][i]+=flow[t];
		f[i][p[i]]-=flow[t];
	}
	return flow[t];
}
int main(){
	int n,m,x;
	scanf("%d %d %d",&n,&m,&x);
	vector<pair<int,pii> > v;
	for(int i=0;i<m;i++)
	{
		int a,b,p;
		scanf("%d %d %d",&a,&b,&p);
		v.pb(mp(p,mp(a,b)));
	}
	int ans=0;
	while(1){
		int flow=BFS(1,n,n);
		if(flow==0)
		break;
		ans+=flow;
	}
	long double mi=0,ma=1e7;
	while(1){
		if(ma-mi<1e-12)
		break;
		long double mid=(ma+mi)/2;
		int sum=0;
		memset(f,0,sizeof(f));
		memset(c,0,sizeof(c));
		for(vector<pair<int,pii> >::iterator it=v.begin();it!=v.end();it++)
		c[it->y.x][it->y.y]=(long double)it->x/mid;
		while(1){
			int flow=BFS(1,n,n);
			if(flow==0)
			break;
			sum+=flow;
		}
		if(sum>=x)
		mi=mid;
		else
		ma=mid;
	}
	printf("%.10llf\n",(double)(ma*x));
}