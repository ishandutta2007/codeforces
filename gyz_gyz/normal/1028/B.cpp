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
#define N 3000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define Pi acos(-1.)
#define eps 1e-8
using namespace std;
int n,m,s1[N],s2[N];bool v[N][N][2];
void f(int x,int y,int up,int l){
	if(v[x][y][up])return;
	v[x][y][up]=1;
	if(y+up>m)return;
	if(x>=n){bool u=0;
		dep(i,l-1,0){
			if(s1[i])u=1;
			if(u)printf("%d",s1[i]);
		}printf("\n");u=0;
		dep(i,l-1,0){
			if(s2[i])u=1;
			if(u)printf("%d",s2[i]);
		}exit(0);
	}
	dep(i,18,0){
		s1[l]=i/2;s2[l]=i-s1[l];
		f(x+s1[l],y+(up+i)%10,(up+i)/10,l+1);
	}
}
int main(){
	scanf("%d%d",&n,&m);f(0,0,0,0);
}