#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define N 100010
inline int read(){
	int x=0,f=1;
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
int T,n,cnt[N];
priority_queue<int> q;
queue<pair<int,int> > res;
inline bool check(int x){
	while(!q.empty())q.pop();
	while(!res.empty())res.pop();
	for(int i=1;i<=n;++i){
		if(cnt[i])q.push(cnt[i]);
	}
	int step=0; 
	for(int i=1;i<=n;++i){
		while(!res.empty()&&step-res.front().first>=x)q.push(res.front().second),res.pop();
		++step;
		if(q.empty())return false;
		int u=q.top()-1;
		q.pop();
		if(u){
			res.push(make_pair(step,u));
		}
	}
	return true;
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		cnt[i]=0;
	}
	for(int i=1;i<=n;++i){
		int x=read();
		++cnt[x];
	}
	int l=0,r=n,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid,l=mid+1;
		}
		else{
			r=mid;
		}
	} 
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}