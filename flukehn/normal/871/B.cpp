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
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;//*
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=5011;
int n;
int query(int i,int j){
	printf("? %d %d\n",i,j);
	fflush(stdout);
	return rd();
}
int f[N][N];
int a[N],b[N],vis[N],ans[N];
int main(){
	n=rd();
	rep(i,0,n-1)f[0][i]=query(0,i);
	rep(i,1,n-1)f[i][0]=query(i,0);
	rep(i,1,n-1)rep(j,1,n-1)f[i][j]=f[0][0]^f[i][0]^f[0][j];
	int fi=-1,sum=0;
	rep(i,0,n-1){
		memset(a,0,sizeof(int)*n);
		memset(b,0,sizeof(int)*n);
		a[0]=i;
		bool flag=1;
		rep(j,0,n-1)b[j]=f[0][j]^a[0];
		rep(j,1,n-1)a[j]=f[j][0]^b[0];
		memset(vis,0,sizeof(int)*n);
		rep(j,0,n-1)
			if(!vis[a[j]]&&a[j]<n)vis[a[j]]=1;
			else{flag=0;break;}
		if(flag){
			rep(j,0,n-1){
				if(b[j]<n&&a[b[j]]!=j){
					flag=0;
					break;
				}
			}
		}
		if(flag){
			sum++;
			if(!(~fi)){
				fi=i;
				rep(j,0,n-1)ans[j]=a[j];
			}
		}
	}
	printf("!\n");
	printf("%d\n",sum);
	rep(i,0,n-1)printf("%d%c",ans[i]," \n"[i==n-1]);
	fflush(stdout);
}