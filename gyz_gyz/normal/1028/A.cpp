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
#define N 1000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define Pi acos(-1.)
#define eps 1e-8
using namespace std;
int n,m;bool u;char s[N][N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,m)if(s[i][j]=='B'){u=1;
		rep(k,1,max(n,m)){
			if((s[i][j-k]!='B')&&(s[i][j+k]!='B')&&(s[i-k][j]!='B')&&(s[i+k][j]!='B'))break;
			if((s[i][j-k]!='B')||(s[i][j+k]!='B')||(s[i-k][j]!='B')||(s[i+k][j]!='B')){
				u=0;break;
			}
		}
		if(u){printf("%d %d",i,j);return 0;}
	}
}