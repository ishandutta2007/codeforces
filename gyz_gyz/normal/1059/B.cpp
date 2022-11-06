#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 2000
#define ll long long
#define pb push_back
#define mo 1000000007
#define add(x,y) x=(x+(y))%mo;
using namespace std;
int n,m;bool u,v[N][N];char s[N][N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,m){
		if((i<n-1)&&(j<m-1)){u=1;
			rep(i1,i,i+2)rep(j1,j,j+2)
				if(((i1!=i+1)||(j1!=j+1))&&(s[i1][j1]=='.'))u=0;
			if(u)rep(i1,i,i+2)rep(j1,j,j+2)
				if((i1!=i+1)||(j1!=j+1))v[i1][j1]=1;
		}
		if((s[i][j]=='#')&&(!v[i][j])){
			printf("NO\n");return 0;
		}
	}printf("YES\n");
}