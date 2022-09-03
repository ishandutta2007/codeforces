#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int dp[32][10000];
int vis[32][10000];
vector<pii> vv[33];
void solve(){
	int l,r;
	scanf("%d %d",&l,&r);
	if(l==r){
		printf("YES\n2 1\n1 2 %d\n",l);
	}
	else{
		printf("YES\n");
		vector<pair<pii,int> > v;
		//v.pb(mp(1))
		int n=2;
		for(int i = 1;i+l<=r;i=i*2){
			v.pb(mp(mp(1,n),l));
			if(i*2-1<=r-l){
				for(int j = 2;j<n;j++){
					v.pb(mp(mp(j,n),1<<(j-2)));
				}
			}
			else{
				int sum=i;
				int now=1;
				for(int j = n-1;j>=2;j--){
					if(sum+(1<<(j-2))<=r-l){
						v.pb(mp(mp(j,n),now));
						now+=(1<<(j-2));
						sum+=(1<<(j-2));
					}
				}
			}
			n++;
		}
		for(int i = 2;i<n;i++){
			v.pb(mp(mp(i,n),(1<<(i-2))));
		}
		v.pb(mp(mp(1,n),l));
		printf("%d %d\n",n,v.size());
		for(auto it:v){
			vv[it.x.x].pb(mp(it.x.y,it.y));
			printf("%d %d %d\n",it.x.x,it.x.y,it.y);
		}
	/*	dp[1][0]=1;
		priority_queue<pii,vector<pii>,greater<pii> > pq;
		vis[1][0]=1;
		pq.push(mp(0,1));
		while(!pq.empty()){
			pii p=pq.top();
			
			swap(p.x,p.y);
			if(p.x==n)assert(p.y>=l&&p.y<=r);
			pq.pop();
			for(auto it:vv[p.x]){
				dp[it.x][it.y+p.y]+=dp[p.x][p.y];
				if(!vis[it.x][it.y+p.y]){
					pq.push(mp(it.y+p.y,it.x));
					vis[it.x][it.y+p.y]=1;
				}
			}
		}
		
		for(int i = l;i<=r;i++){
			printf("%d %d\n",i,dp[n][i]);
			assert(dp[n][i]==1);
		}*/
	}
}
int main(){
    int t=1;00000;//00000;
    //scanf("%d",&t);
    while(t--)solve();
}
/*

*/