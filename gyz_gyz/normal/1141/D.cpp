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
#define N 1000010
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
typedef long long ll;
int n;char s1[N],s2[N];
queue<int>p1[200],p2[200];vector<pair<int,int>>r;
int main(){
	scanf("%d%s%s",&n,s1+1,s2+1);
	rep(i,1,n){
		p1[s1[i]].push(i);
		p2[s2[i]].push(i);
	}
	rep(i,'a','z'){
		while(!p1[i].empty()&&!p2[i].empty()){
			r.pb({p1[i].front(),p2[i].front()});
			p1[i].pop();p2[i].pop();
		}
		while(!p1[i].empty()&&!p2['?'].empty()){
			r.pb({p1[i].front(),p2['?'].front()});
			p1[i].pop();p2['?'].pop();
		}
		while(!p1['?'].empty()&&!p2[i].empty()){
			r.pb({p1['?'].front(),p2[i].front()});
			p1['?'].pop();p2[i].pop();
		}
	}
	while(!p1['?'].empty()&&!p2['?'].empty()){
		r.pb({p1['?'].front(),p2['?'].front()});
		p1['?'].pop();p2['?'].pop();
	}
	cout<<r.size()<<'\n';
	for(auto i:r)printf("%d %d\n",i.fr,i.sc);
}