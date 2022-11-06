#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=111;
int n,a[N],s[N];
bool t[N][N][2];
bool mark[N][N];
bool dfs(int x,int y,int f){
	if(mark[x][y])return t[x][y][f];
	mark[x][y]=1;
	if(x==y) {
		if(a[x]&1)return t[x][y][1]=1;
		else return 0;
	} else if((y-x+1)&1) t[x][y][1]=(a[x]%2&&a[y]%2);
	rep(i,x,y-1){
		int l=dfs(x,i,f),r=dfs(i+1,y,f);
		int L=dfs(x,i,f^1),R=dfs(i+1,y,f^1);
		if((l&&r)||(L&&R))t[x][y][0]=1;
		else if((l&&R)||(r&&L))t[x][y][1]=1;
	}
	return t[x][y][f];
}
int main() {
	n=rd();
	rep(i,1,n)a[i]=rd(),s[i]=s[i-1]+a[i];
	puts(dfs(1,n,1)?"YES":"NO");
}