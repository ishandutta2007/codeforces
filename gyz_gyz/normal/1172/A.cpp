#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=1e9+7;
int n,a[N];bool v[N];
void sol(){
	int nw=0;
	rep(i,1,n){
		if(nw){
			if(a[i]!=++nw)return;
		}
		if(a[i]==1)nw=1;
	}
	if(!nw)return;int ans=n-nw;
	queue<int>q;
	rep(i,1,n)q.push(a[i]);
	while(nw<n){
		if(!v[++nw])return;
		if(q.front())v[q.front()]=1;
		q.pop();q.push(nw);
	}
	printf("%d\n",ans);exit(0);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(x)v[x]=1;
	}
	rep(i,1,n)scanf("%d",&a[i]);
	sol();int ans=0;
	rep(i,1,n)if(a[i])ans=max(ans,i-a[i]+1);
	printf("%d\n",ans+n);
}