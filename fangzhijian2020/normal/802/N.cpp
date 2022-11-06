#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int read(){
	int a=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return a;
}
char c[2000005];int n,a[2000005],K,opt[2000005];long long ans;
struct node{
	long long val;int opt;
	bool operator<(const node&a)const{
		return val>a.val||val==a.val&&opt>a.opt;
	}
};
priority_queue<node>q;
bool check0(long long C){
	int cnt=0;
	while(!q.empty())q.pop();
	for(int i=1;i<=(n<<1);++i){
		if(i&1){
			if(a[i]<C)q.push((node){a[i],1});
		}
		else{
			if(!q.empty()){
				node now=q.top();
				if(now.val+a[i]<C){
					q.pop();cnt+=now.opt;
					q.push((node){C-a[i],0});
				}	
			}
		}
	}
	return cnt<=K;
}
void check1(long long C){
	long long ans=0;int cnt=0;
	while(!q.empty())q.pop();
	for(int i=1;i<=(n<<1);++i){
		if(i&1){
			if(a[i]<C)q.push((node){a[i],1});
		}
		else{
			if(!q.empty()){
				node now=q.top();
				if(now.val+a[i]<C){
					ans+=now.val+a[i]-C;
					q.pop();cnt+=now.opt;
					q.push((node){C-a[i],0});
				}	
			}
		}
	}
	cout<<ans+1ll*K*C;
}
int main(){
//	system("fc b.out b15.out");
//	freopen("b14.in","r",stdin);
//	freopen("b.out","w",stdout);
	n=read();K=read();
	for(int i=1;i<=n;++i)a[2*i-1]=read();
	for(int i=1;i<=n;++i)a[2*i]=read();
	long long l=0,r=2e9;
	while(l<=r){
		int mid=l+r>>1;
		if(check0(mid))l=mid+1;
		else r=mid-1;
	}
	check1(l-1);
	return 0;
}