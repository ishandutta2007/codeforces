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
typedef long double lf;
int main(){
	lf l,v1,v2;int n,k;
	n=rd(),l=rd(),v1=rd(),v2=rd(),k=rd();
	k=n/k+(n%k?1:0);
	lf k1=k;
	double y=(v2-v1)*l/(v2*v2-v1*(v2-2*(k1-1)*(v2-v1)*v2/(v1+v2)));
	double x=(l-v2*y)/v1;
	printf("%.10lf\n",x+y);
}