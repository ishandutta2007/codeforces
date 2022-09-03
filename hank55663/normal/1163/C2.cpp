#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	pii p[1005];
	for(int i = 0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p[i]=mp(x,y);
	}
	map<pii,int > m;
	LL tot=0;
	for(int i = 0;i<n;i++){
		map<pii,int> s;
		for(int j = i+1;j<n;j++){
			pii pp=mp(p[j].x-p[i].x,p[j].y-p[i].y);
			if(pp.x<0)pp.x*=-1,pp.y*=-1;
			int gcd=__gcd(pp.x,pp.y);
			pp.x/=gcd;
			pp.y/=gcd;
			s[pp]++;
		}
		for(auto it:s)
		if(it.y==1)
		m[it.x]++,tot++;
	}
	LL ans=tot*(tot-1)/2;
	for(auto it:m){
		ans-=(it.y-1)*it.y/2;
	}
	printf("%lld\n",ans);
	return 0;
}
/*




*/