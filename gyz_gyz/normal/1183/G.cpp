#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=998244353;
typedef pair<int,int> pii;
pii a[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n)a[i]={0,0};
	rep(i,1,n){int x,y;
		scanf("%d%d",&x,&y);
		++a[x].fr;
		if(y)++a[x].sc;
	}
	int x=n,ans=0,rs=0;multiset<int>s;
	sort(a+1,a+n+1,[](pii&a,pii&b){return a>b;});
	rep(i,1,n){
		while(!s.empty()&&x>a[i].fr){
			ans+=x;rs+=min(*s.rbegin(),x);
			--x;s.erase(--s.end());
		}
		x=min(x,a[i].fr);
		s.insert(a[i].sc);
	}
	while(x&&!s.empty()){
		ans+=x;rs+=min(*s.rbegin(),x);
		--x;s.erase(--s.end());
	}
	printf("%d %d\n",ans,rs);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}