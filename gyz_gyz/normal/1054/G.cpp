#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 2010
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int T,n,m,a[N],fr[N],d[N][N];
char S[N];bool v[N];
bitset<N>t[N],r[N];vector<int>e[N];
int ck(int t,int x){int y=1;v[x]=1;
	for(auto i:e[x])if(!v[i]&&r[t][i])y+=ck(t,i);
	return y;
}
void sol(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		t[i].reset();e[i].clear();
	}
	rep(i,1,m)r[i].reset();
	rep(i,1,m){
		scanf("%s",S+1);int x=0;
		rep(j,1,n)if(S[j]=='1'){
			x++;r[i][j]=1;
		}
		if(x>1)rep(j,1,n)if(S[j]=='1')t[j][i]=1;
	}
	rep(i,1,n)v[i]=0,a[i]=-1,fr[i]=0;a[1]=m;a[0]=-2;
	rep(i,1,n)rep(j,1,n)if(i!=j)d[i][j]=(t[i]&t[j]).count();
	rep(i,1,n){int x=0;
		rep(j,1,n)if(!v[j]&&a[j]>a[x])x=j;v[x]=1;
		rep(j,1,n)if(!v[j]&&a[j]<d[x][j]){
			a[j]=d[x][j];fr[j]=x;
		}
	}
	rep(i,2,n){
		e[i].pb(fr[i]);e[fr[i]].pb(i);
	}
	rep(i,1,m){
		rep(j,1,n)v[j]=0;
		rep(j,1,n)if(r[i][j]){
			if(ck(i,j)!=r[i].count()){
				printf("NO\n");return;
			}break;
		}
	}
	printf("YES\n");
	rep(i,2,n)printf("%d %d\n",fr[i],i);
}
int main(){
	for(scanf("%d",&T);T;T--)sol();
}