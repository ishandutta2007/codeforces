#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define N 300030
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,ans;
struct Team{
	ll w,t;
	bool operator <(const Team b)const{
		return t>b.t;
	}
}a[N];
priority_queue<ll,vector<ll>,greater<ll> > q;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i].t=read(),a[i].w=read();
	}
	sort(a+2,a+n+1);
	int p=2,ft=0;
	while(p<=n&&a[1].t<a[p].t)q.push(a[p].w-a[p].t+1),++p;
	ans=p-1;
	while(!q.empty()){
		ll s=q.top();
		q.pop();
		if(a[1].t<s)break;
		a[1].t-=s;
		++ft;
		while(p<=n&&a[1].t<a[p].t)q.push(a[p].w-a[p].t+1),++p;
		ans=min(ans,p-ft-1);
	}
	printf("%d\n",ans);
	return 0;
}