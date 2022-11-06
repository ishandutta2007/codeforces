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
#define pb push_back
#define N 200
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,ans,x,y,z;
int s[5][5][N],f[5],v[5],a[5][5],w[5];
int gf(int x){
	if(f[x]==x)return x;
	f[x]=gf(f[x]);return f[x];
}
void sol(int x,int y){
	v[f[x]]++;if(y>ans)ans=y;
	rep(i,1,x-1){
		if(a[i][x]){
			y+=s[i][x][a[i][x]--];
			if(!v[f[i]])y+=w[f[i]];sol(i,y);
			if(!v[f[i]])y-=w[f[i]];
			y-=s[i][x][++a[i][x]];
		}
	}
	rep(i,x+1,4){
		if(a[x][i]){
			y+=s[x][i][a[x][i]--];
			if(!v[f[i]])y+=w[f[i]];sol(i,y);
			if(!v[f[i]])y-=w[f[i]];
			y-=s[x][i][++a[x][i]];
		}
	}v[f[x]]--;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d%d",&x,&y,&z);
		if(x>z)swap(x,z);
		s[x][z][++a[x][z]]=y;
	}
	rep(i,1,4)f[i]=i;
	rep(i,1,4)while(a[i][i])w[i]+=s[i][i][a[i][i]--];
	rep(i,1,4)rep(j,i+1,4){
		sort(s[i][j]+1,s[i][j]+a[i][j]+1);
		while(a[i][j]>2){
			if(gf(i)!=gf(j)){
				w[f[i]]+=w[f[j]];f[f[j]]=f[i];
			}
			w[f[i]]+=s[i][j][a[i][j]--];
			w[f[i]]+=s[i][j][a[i][j]--];
		}
	}
	rep(i,1,4)gf(i);
	rep(i,1,4)sol(i,w[f[i]]);
	printf("%d",ans);
}