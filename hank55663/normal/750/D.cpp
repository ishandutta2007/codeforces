#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pb(x) push_back(x)
#define x first
#define y second
#define N 1000005
#define sqr(x) ((x)*(x))
#define EPS 1e-11
using namespace std;
typedef long long ll;
int X[8]={-1,-1,0,1,1,1,0,-1};
int Y[8]={0,1,1,1,0,-1,-1,-1};
struct fire{
	int n,di,x,y;
	fire(int _n,int _di,int _x,int _y):n(_n),di(_di),x(_x),y(_y){
	}
};
int m[300][300];
int visit[300][300][20];
int main(){
	int n;
	scanf("%d",&n);
	queue<fire> q;
	memset(m,0,sizeof(m));
	q.push(fire(0,0,150,150));
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		memset(visit,0,sizeof(visit));
		int aa=0;
		while(q.front().n==i){
			fire f=q.front();q.pop();
			m[f.x][f.y]=1;
			for(int j=a-1;j>0;j--){
				f.x+=X[f.di];
				f.y+=Y[f.di];
				m[f.x][f.y]=1;
			}
			if(visit[f.x+X[(f.di+1)%8]][f.y+Y[(f.di+1)%8]][(f.di+1)%8]!=1){
				visit[f.x+X[(f.di+1)%8]][f.y+Y[(f.di+1)%8]][(f.di+1)%8]=1;
				q.push(fire(f.n+1,(f.di+1)%8,f.x+X[(f.di+1)%8],f.y+Y[(f.di+1)%8]));
			}
			if(visit[f.x+X[(f.di+7)%8]][f.y+Y[(f.di+7)%8]][(f.di+7)%8]!=1){
				visit[f.x+X[(f.di+7)%8]][f.y+Y[(f.di+7)%8]][(f.di+7)%8]=1;
				q.push(fire(f.n+1,(f.di+7)%8,f.x+X[(f.di+7)%8],f.y+Y[(f.di+7)%8]));
			}
		}
	}
	int ans=0;
	for(int i=0;i<300;i++)
	for(int j=0;j<300;j++){
		ans+=m[i][j];
	}
	printf("%d\n",ans);
}