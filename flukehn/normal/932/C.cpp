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
int n,a,b;
inline void work(int l,int r){
	rep(i,l+1,r)printf("%d ",i);
	printf("%d ",l);
}
int main(){
	n=rd(),a=rd(),b=rd();
	int t=0;
	rep(i,0,n/a){
		t=n-a*i;
		if(t%b==0){
			rep(j,1,i){
				work((j-1)*a+1,j*a);
			}
			int q=a*i;
			rep(j,1,t/b){
				work((j-1)*b+1+q,j*b+q);
			}
			return 0;
		}
	}
	cout<<-1<<endl;
}