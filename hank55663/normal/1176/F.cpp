#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
LL dp[200005][10];
int main(){
	MEMS(dp);
	dp[0][0]=0;
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		LL k;
		scanf("%lld",&k);
		vector<LL> v;
		LL tot2=-1;
		LL tot3=-1;
		while(k--){
			LL c,d;
			scanf("%lld %lld",&c,&d);
			if(c==1)
			v.pb(d);
			if(c==2)
			tot2=max(tot2,d);
			if(c==3)
			tot3=max(tot3,d);
		}
		sort(v.begin(),v.end());
		vector<pair<pll,LL>> vv;
		vv.pb(mp(mp(0,0),0));
		if(tot3!=-1)
		vv.pb(mp(mp(1,tot3),tot3));
		if(tot2!=-1)
		vv.pb(mp(mp(1,tot2),tot2));
		if(tot2!=-1&&v.size())
		vv.pb(mp(mp(2,tot2+v.back()),max(tot2,v.back())));
		reverse(v.begin(),v.end());
		if(v.size()>=1)
		vv.pb(mp(mp(1,v[0]),v[0]));
		if(v.size()>=2)
		vv.pb(mp(mp(2,v[0]+v[1]),v[0]));
		if(v.size()>=3)
		vv.pb(mp(mp(3,v[0]+v[1]+v[2]),v[0]));
		for(auto it:vv){
			for(int j = 0;j<10;j++){
				if(dp[i-1][j]!=-1){
					int next=(j+it.x.x)%10;
					LL value=it.x.y+dp[i-1][j];
					if(next<j){
						value+=it.y;
						//dp[i][next]=max()
					}
					dp[i][next]=max(dp[i][next],value);
				}
			}
		}
	}
	LL ans=0;
	for(int i = 0;i<10;i++)
		ans=max(ans,dp[n][i]);
	printf("%lld\n",ans);
}
/*
aaaa
aaba
abaa
baaa
baba
*/