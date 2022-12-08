#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],n,k;
long long f(int x,int y) {
	return 1ll*(x/y+1)*(x/y+1)*(x%y)+1ll*(x/y)*(x/y)*(y-x%y);
}
struct node {
	int x,y;
	node(int xx=0,int yy=0) {
		x=xx,y=yy;
	}
	int operator<(const node &a)const {
		return f(x,y)-f(x,y+1)<f(a.x,a.y)-f(a.x,a.y+1);
	}
};
priority_queue<node>q;
int main() {
	long long ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),ans+=1ll*a[i]*a[i];
	for(int i=1;i<=n;i++)
		q.push(node(a[i],1));
	for(int i=1;i<=k-n;i++) {
		node t=q.top();
		q.pop();
		ans-=f(t.x,t.y)-f(t.x,t.y+1);
		q.push(node(t.x,t.y+1));
	}
	printf("%lld\n",ans);
	return 0;
}