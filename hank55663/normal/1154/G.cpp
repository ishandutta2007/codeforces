#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pll pair<LL,LL>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int value[10000007][2];
int main() {
	int n;
	scanf("%d",&n);
	memset(value,0,sizeof(value));
	for(int i = 1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(value[x][0]){
			value[x][1]=i;
		}
		else{
			value[x][0]=i;
		}
	}
	LL ans=1e18,ansx,ansy;
	for(int i = 1;i<=1e7;i++){
		vector<pll> v;
		for(int k=1;k*i<=1e7;k++){
			
			if(value[k*i][0]){
				v.pb(mp(k,value[k*i][0]));
			}
			if(value[k*i][1]){
				v.pb(mp(k,value[k*i][1]));
			}
			if(v.size()>=2)
			break;
		}
		if(v.size()<2)
		continue;
		LL lcm=i*v[0].x*v[1].x;
		if(lcm<ans){
			ans=lcm;
			ansx=v[0].y;
			ansy=v[1].y;
		}
	//	printf("%lld %d\n",lcm,i);
	}
	if(ansx>ansy)
	swap(ansx,ansy);
	printf("%lld %lld\n",ansx,ansy);
}