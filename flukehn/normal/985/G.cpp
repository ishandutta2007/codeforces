#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long L;
const int N=2e5+11;
vector<int> g[N],d1[N],d2[N];
int h2[N],h1[N];
int n,m;
L A,B,C,G1[N],G2[N];
L an;
int U[N],V[N],D[N],sz;
//unordered_map<L,bool> e[N];
int v[N];
int bb[4];

int main(){
	//freopen("girls.in","r",stdin);
	//freopen("girls.out","w",stdout);
#ifndef ONLINE_JUDGE
	freopen("b.in","r",stdin);
#endif
	cin>>n>>m>>A>>B>>C;
	int i,j,k,x,y,a,b;
	for(i=0;i<n;++i){
		int t=n-1-i;
		an+=(L)t*(t-1)/2*A*i;
		an+=(L)i*t*B*i;
		an+=(L)i*(i-1)/2*C*i;
	}
	//cerr<<an<<endl;
	for(i=0;i<m;++i){
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		an-=(A*x+B*y)*(n-y-1)+(L)(n+y)*(n-y-1)/2*C;
		an-=(A*x+C*y)*(y-x-1)+(L)(x+y)*(y-x-1)/2*B;
		an-=(B*x+C*y)*(x)+(L)x*(x-1)/2*A;
		U[i]=x,V[i]=y;
		++D[x],++D[y];
		++h1[x];
		++h2[y];
		G1[x]+=y*C;
		G2[y]+=x*A;
		d1[x].push_back(y);
		d2[y].push_back(x);
	}
	//cerr<<an<<endl;
	for(i=0;i<n;++i){
		an+=B*i*h1[i]*h2[i]+G1[i]*h2[i]+G2[i]*h1[i];
		an+=(L)(h1[i]-1)*h1[i]/2*A*i+(L)h2[i]*(h2[i]-1)/2*C*i;
		sort(d1[i].begin(),d1[i].end());
		sort(d2[i].begin(),d2[i].end());
		
		for(j=h1[i]-1;j>=0;--j){
			an+=B*d1[i][j]*(h1[i]-j-1);
			an+=C*d1[i][j]*j;
		}
		for(j=0;j<h2[i];++j){
			an+=A*d2[i][j]*(h2[i]-j-1);
			an+=B*d2[i][j]*j;
		}
		//an+=(L)h[i]*(h[i]-1)/2*A*i;
		//an+=(L)hh[i]*(hh[i]-1)/2*C*i;
	}
	for(i=0;i<m;++i){
		x=U[i],y=V[i];
		if(D[x]<D[y])swap(x,y);
		if(D[x]==D[y]&&x>y)swap(x,y);
		g[x].push_back(y);
		
		//uv[sz++]=(L)x*n+y;
		//uv[sz++]=(L)y*n+x;
	}
	//sort(uv,uv+sz);
	for(i=0;i<n;++i){
		int D=g[i].size();
		//cerr<<"D="<<D<<endl;
		for(j=0;j<D;++j)v[g[i][j]]=i+1;
		for(j=0;j<D;++j){
			x=g[i][j];
			for(k=0;k<g[x].size();++k){
				y=g[x][k];
				if(v[y]!=i+1)continue;
				//if(!e[x][y]&&!e[y][x])continue;
				//cerr<<x<<" "<<y<<" "<<i<<endl;
				bb[0]=i,bb[1]=x,bb[2]=y;
				sort(bb,bb+3);
				an-=A*bb[0]+B*bb[1]+C*bb[2];
			}
		}
	}
	cout<<an<<endl;
}