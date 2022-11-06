#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
vector<int>p[N],r[N];
int a[N],w[N],s[N];
int cal(int x){int y=0;
	for(auto&i:p[x])y+=s[i];return y;
}
int main(){
	rep(i,1,100000){
		rep(j,1,i){
			if(j*j>i)break;
			if(!(i%j)){
				p[i].push_back(j);
				if(j*j!=i)p[i].push_back(i/j);
			}
		}
		w[i]=i>1;
		for(auto&j:p[i])if(j!=i)w[i]-=w[j];
	}
	int n;ll ans=0;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-(a+1);
	dep(i,n,1){
		ans=max(ans,(ll)a[i]);
		for(auto&j:p[a[i]])r[j].push_back(a[i]);
	}
	rep(i,1,100000){
		stack<int>sk;
		for(auto&j:r[i]){
			int x=j/i,y=0;
			while(cal(x)<(int)sk.size()){
				y=sk.top();sk.pop();
				for(auto&k:p[y])s[k]-=w[k];
			}
			ans=max(ans,1ll*x*y*i);sk.push(x);
			for(auto&k:p[x])s[k]+=w[k];
		}
		while(!sk.empty()){
			int x=sk.top();sk.pop();
			for(auto&k:p[x])s[k]-=w[k];
		}
	}
	printf("%lld\n",ans);
}