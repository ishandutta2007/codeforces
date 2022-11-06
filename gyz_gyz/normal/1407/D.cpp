#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=3e5+10;
const int mo=998244353;
int a[N],h[N];
int main(){int n;
	scanf("%d%d",&n,&h[1]);
	stack<int>l,r;
	l.push(1);r.push(1);
	rep(i,2,n){
		scanf("%d",&h[i]);a[i]=i-1;bool fl=1;
		for(;!l.empty()&&h[l.top()]>=h[i];l.pop()){
			a[i]=min(a[i],a[l.top()]+1);
			if(h[l.top()]==h[i])fl=0;
		}
		if(fl&&!l.empty())a[i]=min(a[i],a[l.top()]+1);
		l.push(i);
		for(;!r.empty()&&h[r.top()]<=h[i];r.pop()){
			a[i]=min(a[i],a[r.top()]+1);
			if(h[r.top()]==h[i])fl=0;
		}
		if(fl&&!r.empty())a[i]=min(a[i],a[r.top()]+1);
		r.push(i);
	}
	printf("%d\n",a[n]);
}