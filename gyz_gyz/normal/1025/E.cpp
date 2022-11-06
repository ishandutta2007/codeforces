#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 100
#define K 15000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,tot,s,t,tp,ls,vl,ww;bool v[N][N];
int x[N],y[N],X[N],Y[N],tt[N],pt[3];
int dl[N*N],dx[N*N],dy[N*N],fr[N*N];
int wx[K],wy[K],wX[K],wY[K];
void bfs(int i,int vs){
	s=t=1;dl[s]=0;dx[s]=x[i];dy[s]=y[i];
	if((dx[t]==vs)||((!vs)&&(dx[t]==X[i])&&(dy[t]==Y[i])))return;
	for(;s<=t;s++){
		if(!v[dx[s]+1][dy[s]]){t++;
			dx[t]=dx[s]+1;dy[t]=dy[s];dl[t]=dl[s]+1;
			v[dx[t]][dy[t]]=1;fr[t]=s;
			if((dx[t]==vs)||((!vs)&&(dx[t]==X[i])&&(dy[t]==Y[i]))){
				rep(j,2,t)v[dx[j]][dy[j]]=0;return;
			}
		}
		if(!v[dx[s]-1][dy[s]]){t++;
			dx[t]=dx[s]-1;dy[t]=dy[s];dl[t]=dl[s]+1;
			v[dx[t]][dy[t]]=1;fr[t]=s;
			if((dx[t]==vs)||((!vs)&&(dx[t]==X[i])&&(dy[t]==Y[i]))){
				rep(j,2,t)v[dx[j]][dy[j]]=0;return;
			}
		}
		if(!v[dx[s]][dy[s]+1]){t++;
			dx[t]=dx[s];dy[t]=dy[s]+1;dl[t]=dl[s]+1;
			v[dx[t]][dy[t]]=1;fr[t]=s;
			if((dx[t]==vs)||((!vs)&&(dx[t]==X[i])&&(dy[t]==Y[i]))){
				rep(j,2,t)v[dx[j]][dy[j]]=0;return;
			}
		}
		if(!v[dx[s]][dy[s]-1]){t++;
			dx[t]=dx[s];dy[t]=dy[s]-1;dl[t]=dl[s]+1;
			v[dx[t]][dy[t]]=1;fr[t]=s;
			if((dx[t]==vs)||((!vs)&&(dx[t]==X[i])&&(dy[t]==Y[i]))){
				rep(j,2,t)v[dx[j]][dy[j]]=0;return;
			}
		}
	}
	rep(j,2,t)v[dx[j]][dy[j]]=0;
}
void wr(int i){
	if(fr[i]){wr(fr[i]);tot++;
		wx[tot]=dx[fr[i]];wy[tot]=dy[fr[i]];
		wX[tot]=dx[i];wY[tot]=dy[i];
	}
}
void wrs(int i){
	v[x[i]][y[i]]=0;
	x[i]=dx[t];y[i]=dy[t];
	v[x[i]][y[i]]=1;wr(t);
}
int main(){
	scanf("%d%d",&n,&m);
	if(n==1){printf("0");return 0;}
	rep(i,0,n+1)v[i][0]=v[i][n+1]=v[0][i]=v[n+1][i]=1;
	rep(i,1,m){
		scanf("%d%d",&x[i],&y[i]);
		v[x[i]][y[i]]=1;
	}
	rep(i,1,m){
		scanf("%d%d",&X[i],&Y[i]);
		tt[X[i]]++;tt[X[i]-1]++;
	}tp=1;
	rep(i,2,n-1)if(tt[i]<tt[tp])tp=i;
	rep(i,1,m){ls=0;vl=inf;
		rep(j,1,m)if(x[j]!=tp){
			bfs(j,tp);if((dx[t]==tp)&&(dl[t]<vl))vl=dl[t],ls=j;
		}
		if(!ls)break;bfs(ls,tp);wrs(ls);
	}
	rep(i,1,m){ls=0;vl=0;
		rep(j,1,m)if((X[j]!=tp)&&(X[j]!=tp+1)&&((x[j]!=X[j])||(y[j]!=Y[j]))){
			bfs(j,0);if((dx[t]==X[j])&&(dy[t]==Y[j])&&(abs(X[j]-tp)>vl))vl=abs(X[j]-tp),ls=j;
		}
		if(!ls)break;bfs(ls,0);wrs(ls);
	}
	rep(i,1,m)if(x[i]==tp){bfs(i,tp+1);wrs(i);}
	rep(i,1,m){
		if((X[i]==tp-1)&&(x[i]==tp+1)){bfs(i,0);wrs(i);}
		if((X[i]==tp)||(X[i]==tp+1))pt[++ww]=i;
	}
	if((ww==2)&&(X[pt[1]]==x[pt[2]])&&(Y[pt[1]]==y[pt[2]])){bfs(pt[2],tp);wrs(pt[2]);}
	rep(i,1,ww){bfs(pt[i],0);wrs(pt[i]);}
	printf("%d\n",tot);
	rep(i,1,tot)printf("%d %d %d %d\n",wx[i],wy[i],wX[i],wY[i]);
}