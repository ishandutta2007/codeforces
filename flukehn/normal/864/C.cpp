#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
int main(){
	int a=rd(),b=rd(),f=rd(),k=rd();
	int now=0,rs=b,ans=0;
	rep(ttt,1,k){
		//debug(ttt);
		if(rs<abs(f-now)){
			puts("-1");
			return 0;
		}
		else if(now<f){
			rs-=f-now;
			if(!(ttt==k&&rs>=a-f)&&(rs<(a-f)*2)){
				rs=b;
				ans++;
			}
			rs-=a-f;
			now=a;
		}else{
			rs-=now-f;
			if(!(ttt==k&&rs>=f)&&rs<f*2){
				rs=b;
				ans++;
			}
			now=0;
			rs-=f;
		}
	}
	//cout<<rs<<endl;
	if(rs<0)puts("-1");
	else cout<<ans<<endl;
}