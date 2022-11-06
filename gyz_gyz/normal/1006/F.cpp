#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
int n,m;ll k,ans,a[50][50];
struct pr{int x,y;ll z;}x;
bool operator<(const pr &x,const pr &y){
	if(x.x==y.x)if(x.y==y.y)return x.z<y.z;
	else return x.y<y.y;else return x.x<y.x;
}
map<pr,int>mp;
void f(pr x){
	if(x.x+x.y==(n+m+1)/2){
		mp[x]++;return;
	}
	if(x.x<n){
		x.x++;x.z^=a[x.x][x.y];f(x);
		x.z^=a[x.x][x.y];x.x--;
	}
	if(x.y<m){
		x.y++;x.z^=a[x.x][x.y];f(x);
		x.z^=a[x.x][x.y];x.y--;
	}
}
void g(int x,int y,ll z){
	if(x+y==(n+m+1)/2+1){pr X;
		X.x=x-1;X.y=y;X.z=k^z;
		if(mp.count(X))ans+=mp[X];
		X.x=x;X.y=y-1;
		if(mp.count(X))ans+=mp[X];return;
	}
	if(x>1)g(x-1,y,z^a[x-1][y]);
	if(y>1)g(x,y-1,z^a[x][y-1]);
}
int main(){
	scanf("%d%d%I64d",&n,&m,&k);
	rep(i,1,n)rep(j,1,m)scanf("%I64d",&a[i][j]);
	if((n==1)&&(m==1)){printf("%d\n",a[1][1]==k);return 0;}
	x.x=x.y=1;x.z=a[1][1];f(x);g(n,m,a[n][m]);
	printf("%I64d\n",ans);
}