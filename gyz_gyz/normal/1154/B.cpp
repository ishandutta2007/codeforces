#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int mo=1e9+7;
const int inf=1e9;
const ll Inf=1e18;
int main(){set<int>s;
	int n;scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		s.insert(x);
	}
	if(s.size()==1)return printf("0\n"),0;
	if(s.size()==2){
		int t=*--s.end()-*s.begin();
		return printf("%d\n",t&1?t:t>>1),0;
	}
	if(s.size()>3||*s.begin()+*--s.end()!=*++s.begin()*2)
		return printf("-1\n"),0;
	printf("%d\n",*++s.begin()-*s.begin());
}