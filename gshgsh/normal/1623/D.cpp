#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 100001
int T,N,M,x,y,x1,y1,p;const int dx[4]={1,1,-1,-1},dy[4]={1,-1,1,-1};
struct node{int x,y,p;friend bool operator==(node a,node b){return a.x==b.x&&a.y==b.y&&a.p==b.p;}friend bool operator!=(node a,node b){return !(a==b);}};
node to(node a){int x=a.x+dx[a.p],y=a.y+dy[a.p];int p=a.p;if(x==1||x==N)p^=2;if(y==1||y==M)p^=1;return{x,y,p};}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M>>x>>y>>x1>>y1>>p;p=1ll*p*pow(100,P-2)%P;
		vector<node>a;a.push_back({x,y,(x==N)<<1|(y==M)});
		node u=to(a[0]);while(u.x!=a[0].x||u.y!=a[0].y||u.p!=a[0].p)a.push_back(u),u=to(u);
		int M=a.size();vector<int>vis(M);For(i,0,M-1)vis[i]=a[i].x==x1||a[i].y==y1;
		int mul=1,sum=0;For(i,0,M-1)if(vis[i])sum=(sum+1ll*i*mul%P*p)%P,mul=1ll*mul*(1+P-p)%P;
		int ans1=pow(1-mul+P,P-2);int ans2=1ll*mul*M%P*(1+P-mul)%P*ans1%P*pow(1-mul+P,P-2)%P;
		cout<<(ans2+1ll*ans1*sum)%P<<'\n';
	}
}