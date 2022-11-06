#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)/*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=10;
char C[N+11][N+11];
bool check(int x,int y){
	int t1=0,t2=0;
	per(i,x-1,1)if(C[i][y]=='X')t2++; else break;
	rep(i,x+1,N)if(C[i][y]=='X')t1++;else break;
	if(t1+t2>=4)return 1;else t1=t2=0;
	//cout<<"1no"<<endl;
	//if(x==1&&y==3)cout<<t1<<" "<<t2<<endl;
	per(i,y-1,1)if(C[x][i]=='X')t2++;else break;
	rep(i,y+1,N)if(C[x][i]=='X')t1++;else break;
	if(t1+t2>=4)return 1;else t1=t2=0;
	//if(x==1&&y==3)cout<<t1<<" "<<t2<<endl;
	for(int i=x-1,j=y-1;i>0&&j>0;i--,j--)
		if(C[i][j]=='X')t2++;else break;
	for(int i=x+1,j=y+1;i<=N&&j<=N;i++,j++)
		if(C[i][j]=='X')t1++;else break;
	//if(x==1&&y==3)cout<<t1<<" "<<t2<<endl;
	if(t1+t2>=4)return 1;else t1=t2=0;
	for(int i=x-1,j=y+1;i>0&&j<=N;i--,j++)
		if(C[i][j]=='X')t2++;else break;
	for(int i=x+1,j=y-1;i<=N&&j>0;i++,j--)
		if(C[i][j]=='X')t1++;else break;
	return t1+t2>=4;
}
bool judge(){
	rep(i,1,N)rep(j,1,N)if(C[i][j]=='.'){
		if(check(i,j)) {
			//cout << i << " " << j << endl;
			return 1;
		}
	}
	return 0;
}
int main(){
	rep(i,1,N)scanf("%s",C[i]+1);
	puts(judge()?"YES":"NO");
}