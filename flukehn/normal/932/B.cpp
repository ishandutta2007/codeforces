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
const int inf=~0u>>1,mod=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=1e6+1;
int p[N];
inline void F(int n){
	int r=1,t=n;
	while(t)r*=(t%10?t%10:1),t/=10;
	p[n]=p[r];
	//cout<<p[n]<<endl; 
}
int f[10][N];
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
	For(i,1,10)p[i]=i;
	For(i,10,N)F(i);
	rep(k,1,9){
		For(i,1,N){
			f[k][i]=f[k][i-1]+(p[i]==k);
		}
	}
	int q=rd();
	while(q--){
		int l=rd(),r=rd(),k=rd();
		printf("%d\n",f[k][r]-f[k][l-1]);
	}
}