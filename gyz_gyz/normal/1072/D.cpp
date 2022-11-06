#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 3000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,k,t,f[N][N];bool v[N][N];char s[N][N];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,n)
		f[i][j]=max(f[i-1][j],f[i][j-1])+(s[i][j]=='a');
	rep(i,1,n)rep(j,1,n)if(i+j-1-k<=f[i][j])t=max(i+j,t);
	rep(i,1,n)if(t-i>0&&t-i<=n&&t-1-k<=f[i][t-i])v[i][t-i]=1;
	rep(i,2,t)printf("a");
	if(!t){
		printf("%c",s[1][1]);t=2;v[1][1]=1;
	}
	rep(i,t+1,n*2){char c='z';
		rep(j,1,n)if(i-j>0&&i-j<=n&&(v[j-1][i-j]||v[j][i-j-1]))
			c=min(c,s[j][i-j]);
		rep(j,1,n)if(i-j>0&&i-j<=n&&(v[j-1][i-j]||v[j][i-j-1])&&s[j][i-j]==c)v[j][i-j]=1;
		printf("%c",c);
	}
}