#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
using namespace std;
int main(){
	LL n,a,b;
	scanf("%lld %lld %lld",&n,&a,&b);
	//pair<int,pii> p[200005];
	map<LL,map<LL,LL> > m;
	map<LL,LL> sum;
	for(int i = 0;i<n;i++){
		LL x,vx,vy;
		scanf("%lld %lld %lld",&x,&vx,&vy);
		if(a<0)
		vx=-vx;
		LL value = vy-a*vx;
		//printf("%lld\n",value);
		m[value][vx]++;//.pb(x);
		sum[value]++;
		//p[i]=mp(x,mp(vx,vy));
	}
	LL ans=0;
	for(auto it:m){
		for(auto it2:it.y){
			ans+=it2.y*(sum[it.x]-it2.y);
		}
	}
	printf("%lld\n",ans);
}