#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200
#define mo 1000000007
using namespace std;
int n,m,x,y,z,u,U,L,S,T,ans;
int l[N][N],p[N][N][N],dl[N],a[N][N][N],b[N][N][N];
vector<int>R[N],Rw[N],A[N],Aw[N],B[N],Bw[N],G[N];
inline void upd(int &x,int y){x+=y;if(x>=mo)x-=mo;}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)b[i][i][0]=1;
	rep(i,1,n)rep(j,1,n)l[i][j]=-1;
	rep(i,1,m){
		scanf("%d%d",&x,&y);
		scanf("%d",&l[x][y]);
		if(!l[x][y])G[x].push_back(y);
		rep(j,1,l[x][y])scanf("%d",&p[x][y][j]);
	}
	rep(i,1,n)rep(j,1,n){u=0;
		rep(k,1,l[i][j]-1)if(p[i][j][k]==i&&p[i][j][k+1]==j)u=k;
		if(!u)continue;
		L=1;S=1;T=0;U=0;dl[0]=p[i][j][u];
		dep(k,u-1,1)dl[++T]=p[i][j][k],L++;
		for(;S<=T;S++){
			if(L>2*n)break;int X=dl[S-1],Y=dl[S];
			if(l[Y][X]==-1){U=1;break;}
			dep(k,l[Y][X],1)dl[++T]=p[Y][X][k],L++;
		}
		if(U)continue;
		x=dl[T];S=1;T=0;dl[0]=p[i][j][u+1];
		rep(k,u+2,l[i][j])dl[++T]=p[i][j][k],L++;
		for(;S<=T;S++){
			if(L>2*n)break;int X=dl[S-1],Y=dl[S];
			if(l[X][Y]==-1){U=1;break;}
			rep(k,1,l[X][Y])dl[++T]=p[X][Y][k],L++;
		}
		if(U)continue;
		if(L<=2*n){R[x].push_back(dl[T]);Rw[x].push_back(L);}
	}
	rep(i,1,n)rep(j,1,n)if(p[i][j][l[i][j]]==i){
		L=1;S=1;T=0;u=0;dl[0]=i;
		dep(k,l[i][j]-1,1)dl[++T]=p[i][j][k],L++;
		for(;S<=T;S++){
			if(L>2*n)break;int X=dl[S-1],Y=dl[S];
			if(l[Y][X]==-1){u=1;break;}
			dep(k,l[Y][X],1)dl[++T]=p[Y][X][k],L++;
		}
		if(u)continue;
		if(L<=2*n){A[dl[T]].push_back(j);Aw[dl[T]].push_back(L);}
	}
	rep(i,1,n)rep(j,1,n)if(p[i][j][1]==j){
		L=1;S=1;T=0;u=0;dl[0]=j;
		rep(k,2,l[i][j])dl[++T]=p[i][j][k],L++;
		for(;S<=T;S++){
			if(L>2*n)break;int X=dl[S-1],Y=dl[S];
			if(l[X][Y]==-1){u=1;break;}
			rep(k,1,l[X][Y])dl[++T]=p[X][Y][k],L++;
		}
		if(u)continue;
		if(L<=2*n){B[i].push_back(dl[T]);Bw[i].push_back(L);}
	}
	rep(le,0,2*n)rep(i,1,n)rep(j,1,n){int sz;
		sz=R[j].size()-1;
		rep(k,0,sz)upd(a[i][R[j][k]][le+Rw[j][k]],b[i][j][le]);
		sz=A[j].size()-1;
		rep(k,0,sz)upd(b[i][A[j][k]][le+Aw[j][k]],b[i][j][le]);
		sz=B[j].size()-1;
		rep(k,0,sz)upd(a[i][B[j][k]][le+Bw[j][k]],a[i][j][le]);
		sz=G[j].size()-1;
		rep(k,0,sz)upd(b[i][G[j][k]][le+1],a[i][j][le]);
	}
	rep(l,1,2*n){ans=0;
		rep(i,1,n)rep(j,1,n)upd(ans,a[i][j][l]);
		printf("%d\n",ans);
	}
}