#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
#define N
int main(){
	vector<pii> l,r;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		l.pb(mp(x,i));
		r.pb(mp(y,i));
	}
	sort(l.begin(),l.end());
	sort(r.begin(),r.end());
	int ans=0;
	if(l.back().y==r.front().y){
		ans=max(ans,r[1].x-l[l.size()-2].x);
	}
	else{
		ans=max(max(r[0].x-l[l.size()-2].x,r[1].x-l.back().x),ans);
	}
	printf("%d\n",ans);
}
/*
   s       20006
 qqqqqq  0~10000
bbbbbbbb  10001 20000
  5 5 5    20001 20005
     t    20007





*/