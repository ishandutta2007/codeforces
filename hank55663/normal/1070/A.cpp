#include<bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define x first 
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int dp[505][5005];
pair<pii,int> from[505][5005];
int main(){
	int d,s;
	scanf("%d %d",&d,&s);
	MEM(dp); 
	dp[0][0]=1;
	queue<pii> q;
	q.push(mp(0,0));
	while(!q.empty()){
		pii p=q.front();
	//	printf("%d %d\n",p.x,p.y);
		q.pop();
		int st=0;
		if(s==0)
		st=1;
		for(int i=st;i<10;i++){
			int a=(p.x*10+i)%d;
			int b=p.y+i;
			if(b>s)
			continue;
			if(dp[a][b]==0){
				dp[a][b]=1;
				from[a][b]=mp(p,i);
				q.push(mp(a,b));
			}
		}
	}
	if(dp[0][s]==0){
		printf("-1\n");
	}
	else{
		vector<int> v;
		int x=0,y=s;
		while(x!=0||y!=0){
			//printf("%d %d %d\n",x,y,from[x][y].y);
			v.pb(from[x][y].y);
			int tempx=from[x][y].x.x;
			int tempy=from[x][y].x.y;
			x=tempx;
			y=tempy;
		} 
		reverse(v.begin(),v.end());
		for(auto it:v)
		printf("%d",it);
		printf("\n");
	}
}