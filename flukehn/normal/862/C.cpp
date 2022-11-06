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
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
int lb(int x) {
	return x&-x;
}
const int N=1e6;
bool vis[N+11];
void print(int x){
	#define _rand() ((rand()<<15)^rand())
	while(1){
		int a,b;
		while(vis[a=_rand()%N]);
		while(vis[b=_rand()%N]);
		//cout << a << " " << b << " "<<(a^b) << endl;
		int c=x^a^b;
		if(c<=N&&a!=b&&a!=c&&b!=c&&!vis[c]){
			vis[a] = vis[b] = vis[c] = 1;
			printf("%d %d %d\n",a,b,c);
			return;
		}
	}
}
int main() {
	int n=rd(),x=rd();
	if(n==2&&x==0){
		puts("NO");
		return 0;
	}
	puts("YES");
	if(n==1)cout<<x<<endl;
	else if(n==2){
		cout<<0<<" "<<x<<endl;
	}
	else {
		int s=0;
		rep(i,1,n-3)printf("%d ",i),s^=i;
		print(x^s);
	}
}