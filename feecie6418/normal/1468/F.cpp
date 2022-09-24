#include<bits/stdc++.h>
#define re register
using namespace std;
#define mp make_pair
int n,m,t;
int gcd(int x,int y){
	if(!x||!y)return x+y;
	return __gcd(x,y);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		map<pair<int,int>,int> s,s2;
		long long ans=0;
		for(re int i=1;i<=n;++i){
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			int x=a-c,y=b-d,t=gcd(abs(a-c),abs(b-d));
			x/=t,y/=t;
			int tx=x,ty=y;
			if(tx<0||(tx==0&&ty<0))tx=-tx,ty=-ty;
			ans+=s[mp(tx,ty)],s[mp(tx,ty)]++;
			ans-=s2[mp(x,y)],s2[mp(x,y)]++;
		}
		printf("%lld\n",ans);
	}
}