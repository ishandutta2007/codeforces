#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int mo=1e9+7;
const int inf=1e9;
struct pr{
	int x;ll t;
	friend bool operator <(const pr&a,const pr&b){
		return a.t==b.t?a.x<b.x:a.t<b.t;
	}
}a[N];ll t[N];
int main(){int n;ll p;
	scanf("%d%lld",&n,&p);
	rep(i,1,n){
		a[i].x=i;scanf("%lld",&a[i].t);
	}
	sort(a+1,a+n+1);
	int x=1;ll nw=0;
	set<int>s,qq;queue<int>q;
	while(x<=n){
		nw=a[x].t;q.push(a[x].x);qq.insert(a[x].x);++x;
		while(!q.empty()){
			for(;x<=n&&a[x].t<nw+p;++x){
				if(a[x].x<*qq.begin()){
					qq.insert(a[x].x);q.push(a[x].x);
				}else s.insert(a[x].x);
			}
			int y=q.front();q.pop();qq.erase(y);t[y]=(nw+=p);
			while(x<=n&&a[x].t==nw)s.insert(a[x++].x);
			if(!s.empty()&&(q.empty()||*s.begin()<*qq.begin())){
				int y=*s.begin();s.erase(y);
				q.push(y);qq.insert(y);
			}
		}
	}
	rep(i,1,n)printf("%lld%c",t[i],i==n?'\n':' ');
}