#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define foe(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,mo=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=300011,M=30;
int a[N];
int s[N*M][2],b[N*M][2],tot;
void ins(int x){
	int p=0;
	per(i,0,M-1){
		int y=x>>i&1;
		s[p][y]++;
		if(!b[p][y])b[p][y]=++tot;
		p=b[p][y];
	}
}
int F(int x){
	int p=0,r=0;
	per(i,0,M-1){
		int y=x>>i&1;
		//if(x==8)cerr<<y<<endl;
		if(s[p][y]){
			r^=y*(1<<i);
			s[p][y]--;
			p=b[p][y];
		}else{
			r^=(1-y)*(1<<i);
			s[p][y^1]--;
			p=b[p][y^1];
		}
	}
	return r^x;
}
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
	int n=rd();
	rep(i,1,n)a[i]=rd();
	rep(i,1,n){
		int x=rd();
		ins(x);
	}
	rep(i,1,n){
		printf("%d%c",F(a[i])," \n"[i==n]);
	}
}