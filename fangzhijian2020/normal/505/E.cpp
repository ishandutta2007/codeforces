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
int n,m,k,p,h[100005],a[100005];long long tmp[100005],l,r,mid;
struct node{
	int x,id;
	bool operator<(const node&a)const{
		return x>a.x;
	}
};
priority_queue<node>q;
long long solve(int id){return tmp[id]/a[id];}
bool check(long long S){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;++i){
		tmp[i]=S;
		if(tmp[i]-1ll*m*a[i]<h[i]){
			q.push((node){solve(i),i});
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=k;++j){
			if(!q.empty()){
				int id=q.top().id;q.pop();
				if(solve(id)<i)return 0;
				if((tmp[id]+=p)-1ll*m*a[id]<h[id]){
					q.push((node){solve(id),id});
				}
			}
		}
	}
	return q.empty();
}
int main(){
	n=read();m=read();k=read();p=read();
	for(int i=1;i<=n;++i){
		h[i]=read();a[i]=read();
		r=max(r,h[i]+1ll*m*a[i]);
	}
	while(l<=r){
		mid=l+r>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<r+1;
	return 0;
}