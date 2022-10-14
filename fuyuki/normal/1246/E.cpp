#include<queue>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define fs first
#define sc second
#define rnt re int
#define re register
#define I inline int
#define mk make_pair
#define V inline void
#define P pair<int,int>
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
const int N=17;
int n,m,sum,S,a[N];
bitset<2001>dp[65536];
V input(){
	scanf("%d%d",&n,&m),S=1<<n,S--;
	FOR(i,0,n-1)scanf("%d",a+i),sum+=a[i];
}
V init(){
	dp[0][0]=1;
	FOR(i,0,S){
		ROF(j,sum/m,1)
			dp[i][j]=dp[i][j]||dp[i][j*m];
		FOR(j,0,n-1)if(!(i>>j&1))
			dp[1<<j|i]|=dp[i]<<a[j];
	}
}
priority_queue<P>q;
V work(){
	if(!dp[S][1])return void(cout<<"NO");
	puts("YES");
	rnt res=1,now=0,flag=0;
	while(S){
		if(!flag&&res*m<=sum&&dp[S][res*m])
			res*=m,now++;
		flag=0;
		FOR(i,0,n-1)if((S>>i&1)&&res>=a[i]&&dp[S^(1<<i)][res-a[i]]){
			S^=1<<i,res-=a[i],q.push(mk(now,a[i])),flag=1;
			break;
		}
	}
	while(--n){
		P x=q.top();q.pop();
		P y=q.top();q.pop();
		rnt w=x.sc+y.sc,d=x.fs;
		cout<<x.sc<<' '<<y.sc<<'\n';
		while(w%m==0)w/=m,d--;
		q.push(mk(d,w));
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}