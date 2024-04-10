#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=1e5+1;
ll ans;
int n,m,tot,top;
vector<int>d[N];
int a[N],pri[N],tag[N],mu[N],cnt[N],sta[N];
V input(){for(int x=scanf("%d",&m);m--;a[x]=1)scanf("%d",&x),n=max(x,n);}
V init(){
	int p(mu[ans=n,1]=1);
	FOR(i,2,n){
		if(!tag[i])pri[++tot]=i,mu[i]=-1;
		FOR(j,1,tot){
			if((p=i*pri[j])>n)break;
			tag[p]=1,mu[p]=-mu[i];
			if(i%pri[j]==0){mu[p]=0;break;}
		}
	}
	FOR(i,1,n)FOR(j,1,n/i)d[i*j].push_back(i),a[i]|=a[i*j];
}
I gcd(int x,int y){return!y?x:gcd(y,x%y);}
ll lcm(int x,int y){return 1ll*x*y/gcd(x,y);}
I ask(int x,int out=0){for(int v:d[x])out+=cnt[v];return out;}
V add(int x,int w){for(int v:d[x])cnt[v]+=mu[v]*w;}
V work(){
	ROF(i,n,1)if(a[i]){
		for(int sum=ask(i);sum;sum-=gcd(sta[top--],i)==1)add(sta[top],-1);
		ans=max(ans,lcm(i,sta[top+1])),add(sta[++top]=i,1);
	}
	cout<<ans;
}
int main(){
	input();
	init();
	work();
	return 0;
}