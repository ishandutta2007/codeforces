#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define fr first
#define sc second
#define N 3010
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
int n,m,a[N],l[N][N*2],r[N][N*2];char s[N][N*2];ll ans;
void f(int x,int y){for(;x<=n;x+=x&(-x))a[x]+=y;}
int q(int x){int y=0;for(;x;x^=x&(-x))y+=a[x];return y;}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",s[i]+i);
	rep(i,1,n){
		rep(j,i-1,i+m-1)l[i][j]=s[i][j]=='z'?l[i][j-1]+1:-1;
		dep(j,i+m,i)r[i][j]=s[i][j]=='z'?r[i][j+1]+1:-1;
	}
	rep(i,1,n+m-1){
		int L=max(i-m+1,1),R=min(i,n);set<pii>e;
		rep(j,1,n)a[j]=0;int tot=0;
		rep(j,L,R)if(s[j][i]=='z'){
			f(j,1);++tot;e.insert({l[j][i]+j,j});
			while(e.begin()->fr<j){
				f(e.begin()->sc,-1);--tot;
				e.erase(e.begin());
			}
			ans+=tot-q(max(j-r[j][i]-1,0));
		}else while(!e.empty()){
			f(e.begin()->sc,-1);--tot;
			e.erase(e.begin());
		}
	}
	printf("%lld\n",ans);
}