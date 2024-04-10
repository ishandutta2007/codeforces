#include<iostream> 
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,k,h[200005],ans[200005],a[200005];
struct node{
	int id,v;
	bool operator<(const node&a)const{
		return v<a.v;
	}
};
priority_queue<node>q;node t[200005];vector<int>v[200005];
bool check(int L){
	if(L==0)return 1;while(!q.empty())q.pop();
	for(int i=1;i<=n;++i){
		if(h[i])q.push((node){i,h[i]});ans[i]=0;
	}
	for(int T=1;T<=k;++T){
		int tp=0,tot=0;
		while(!q.empty()){
			node x=q.top();q.pop();
			if(x.v>1)t[++tot]=(node){x.id,x.v-1};
			++tp;ans[v[x.id][x.v-1]]=T;
			if(tp==L)break;
		}
		for(int i=1;i<=tot;++i)q.push(t[i]);
		if(tp!=L)return 0;
	}
	return 1;
}
int main(){
	T=read()+1;
	while(--T){
		n=read();k=read();
		for(int i=1;i<=n;++i){
			a[i]=read();++h[a[i]];v[a[i]].push_back(i);
		}
		int l=0,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid))l=mid+1;
			else r=mid-1;	
		}
		check(l-1);
		for(int i=1;i<=n;++i)cout<<ans[i]<<" ";puts("");
		for(int i=1;i<=n;++i){
			h[a[i]]=0;v[a[i]].clear();ans[i]=0;
		}
	}
	return 0;
}