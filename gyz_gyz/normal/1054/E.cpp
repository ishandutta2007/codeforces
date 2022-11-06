#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define N 310
#define M 1000000
#define ll long long
#define mo 1000000007
#define inf 1000000000
using namespace std;
int n,m,tot,x,y;
int l1[N][N],l2[N][N],d[N],wr0[M],wr1[M],wr2[M],wr3[M];
string s[N][N],t[N][N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)cin>>s[i][j];
	rep(i,1,n)rep(j,1,m)cin>>t[i][j];
	rep(i,1,n)rep(j,1,m){
		l1[i][j]=s[i][j].length();
		l2[i][j]=t[i][j].length();
	}
	rep(i,2,m)dep(j,l1[1][i]-1,0){
		wr0[++tot]=1;wr1[tot]=i;
		if(s[1][i][j]=='0'){
			wr2[tot]=1;wr3[tot]=1;
		}else{
			wr2[tot]=n;wr3[tot]=i;d[i]++;
		}
	}
	rep(i,1,m-1){
		dep(j,l1[n][i]-1,0){
			wr0[++tot]=n;wr1[tot]=i;
			if(s[n][i][j]=='0'){
				wr2[tot]=1;wr3[tot]=i;
				if(i>1){
					wr0[++tot]=1;wr1[tot]=i;wr2[tot]=1;wr3[tot]=1;
				}
			}else{
				wr2[tot]=n;wr3[tot]=m;
			}
		}
		rep(j,1,d[i]){
			wr0[++tot]=n;wr1[tot]=i;wr2[tot]=n;wr3[tot]=m;
		}
	}
	rep(i,2,n-1)rep(j,1,m)dep(k,l1[i][j]-1,0){
		if(s[i][j][k]=='0'){
			if(i>1){
				wr0[++tot]=i;wr1[tot]=j;wr2[tot]=1;wr3[tot]=j;
			}
			if(j>1){
				wr0[++tot]=1;wr1[tot]=j;wr2[tot]=1;wr3[tot]=1;
			}
		}else{
			if(i<n){
				wr0[++tot]=i;wr1[tot]=j;wr2[tot]=n;wr3[tot]=j;
			}
			if(j<m){
				wr0[++tot]=n;wr1[tot]=j;wr2[tot]=n;wr3[tot]=m;
			}
		}
	}
	dep(i,l1[1][1]-1,0){
		wr0[++tot]=1;wr1[tot]=1;
		if(s[1][1][i]=='0'){
			wr2[tot]=1;wr3[tot]=m;x++;
		}else{
			wr2[tot]=n;wr3[tot]=1;y++;
		}
	}
	dep(i,l1[n][m]-1,0){
		wr0[++tot]=n;wr1[tot]=m;
		if(s[n][m][i]=='0'){
			wr2[tot]=1;wr3[tot]=m;x++;
		}else{
			wr2[tot]=n;wr3[tot]=1;y++;
		}
	}
	rep(i,0,l2[1][1]-1)if(t[1][1][i]=='0')x--;else y--;
	rep(i,0,l2[n][m]-1)if(t[n][m][i]=='0')x--;else y--;
	if(x>0){
		rep(i,1,x){
			wr0[++tot]=1;wr1[tot]=m;wr2[tot]=1;wr3[tot]=1;
		}
	}else{
		rep(i,1,-x){
			wr0[++tot]=1;wr1[tot]=1;wr2[tot]=1;wr3[tot]=m;
		}
	}
	if(y>0){
		rep(i,1,y){
			wr0[++tot]=n;wr1[tot]=1;wr2[tot]=n;wr3[tot]=m;
		}
	}else{
		rep(i,1,-y){
			wr0[++tot]=n;wr1[tot]=m;wr2[tot]=n;wr3[tot]=1;
		}
	}
	dep(i,l2[1][1]-1,0){
		wr2[++tot]=1;wr3[tot]=1;
		if(t[1][1][i]=='0'){
			wr0[tot]=1;wr1[tot]=m;
		}else{
			wr0[tot]=n;wr1[tot]=1;
		}
	}
	dep(i,l2[n][m]-1,0){
		wr2[++tot]=n;wr3[tot]=m;
		if(t[n][m][i]=='0'){
			wr0[tot]=1;wr1[tot]=m;
		}else{
			wr0[tot]=n;wr1[tot]=1;
		}
	}
	rep(i,1,n)dep(j,m,1)if((i+j>2)&&(i+j<n+m))
		dep(k,l2[i][j]-1,0)if(t[i][j][k]=='0'){
			if(i>1){
				wr0[++tot]=1;wr1[tot]=1;wr2[tot]=i;wr3[tot]=1;
			}
			if(j>1){
				wr0[++tot]=i;wr1[tot]=1;wr2[tot]=i;wr3[tot]=j;
			}
		}else{
			if(j<m){
				wr0[++tot]=n;wr1[tot]=m;wr2[tot]=n;wr3[tot]=j;
			}
			if(i<n){
				wr0[++tot]=n;wr1[tot]=j;wr2[tot]=i;wr3[tot]=j;
			}
		}
	printf("%d\n",tot);
	rep(i,1,tot)printf("%d %d %d %d\n",wr0[i],wr1[i],wr2[i],wr3[i]);
}