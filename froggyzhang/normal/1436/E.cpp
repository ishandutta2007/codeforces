#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define N 100010
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
int n,a[N];
vector<int> p[N];
namespace Chair{
	int root[N],cnt;
	struct node{
		int ch[2],las;
	}tree[N<<5];
	#define ls tree[k].ch[0]
	#define rs tree[k].ch[1]
	inline void update(int k){
		tree[k].las=min(tree[ls].las,tree[rs].las);
	}
	void Modify(int &k,int pre,int L,int R,int pos,int t){
		k=++cnt;
		tree[k]=tree[pre];
		if(L==R)return (void)(tree[k].las=t);
		int mid=(L+R)>>1;
		if(pos<=mid){
			Modify(ls,tree[pre].ch[0],L,mid,pos,t);
		}
		else{
			Modify(rs,tree[pre].ch[1],mid+1,R,pos,t);
		}
		update(k);
	}
	int Query(int k,int L,int R,int lim){
		if(L==R)return L;
		int mid=(L+R)>>1;
		if(tree[ls].las<lim)return Query(ls,L,mid,lim);
		return Query(rs,mid+1,R,lim);
	}
	bool check(int l,int r,int x){
		return Query(root[r],1,n+1,l)==x;
	}
}
int main(){
	n=read();
	bool all1=true;
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]^1)all1=false;
	}
	if(all1)return !printf("1\n");
	for(int i=1;i<=n;++i){
		p[a[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		Chair::Modify(Chair::root[i],Chair::root[i-1],1,n+1,a[i],i);
	}
	for(int i=1;i<=n+1;++i){
		bool ok=false;
		int las=0;
		for(auto x:p[i]){
			if(Chair::check(las+1,x-1,i)){
				ok=true;
				break;
			}
			las=x;
		}
		if(!ok&&!Chair::check(las+1,n,i))return !printf("%d\n",i);
	}
	printf("%d\n",n+2); 
	return 0;
}