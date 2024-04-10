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
#define N 1000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,s[N];bool p[N][N],a[N][N],b[N][N];
int gcd(int x,int y){
	if(!x)return y;return gcd(y%x,x);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&s[i]);
	rep(i,1,n)rep(j,1,n)if(gcd(s[i],s[j])>1)p[i][j]=1;
	rep(i,1,n)a[i][i]=b[i][i]=1;
	rep(i,1,n){
		rep(j,i+1,n)rep(k,j-i,j-1)if(p[k][j]&&b[k][j-1]&&a[k][j-i])a[j][j-i]=1;
		rep(j,1,n-i)rep(k,j+1,j+i)if(p[k][j]&&a[k][j+1]&&b[k][j+i])b[j][j+i]=1;
	}
	rep(i,1,n)if(a[i][1]&&b[i][n]){printf("Yes");return 0;}
	printf("No");
}