#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int inf=0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;
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
int n,Q,S,d,a[N],ans[N],L[N],R[N],vis[N][3];
inline int Findl(int x){
	return upper_bound(a+1,a+n+1,x)-a-1;	
}
inline int Findr(int x){
	return lower_bound(a+1,a+n+1,x)-a;
}
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int> >,greater<tuple<int,int,int> > > q; 
int main(){
	n=read(),Q=read(),S=read(),d=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	memset(ans,0x3f,sizeof(ans));
	ans[S]=0;
	q.push(make_tuple(ans[S],S,0));
	memset(L,0x3f,sizeof(L));
	memset(R,0x3f,sizeof(R)); 
	while(!q.empty()){
		int u=get<1>(q.top()),type=get<2>(q.top());
		q.pop();
//		if(vis[u][type])continue;
//		vis[u][type]=1;
		int w;
		if(!type){
			int l1=Findl(a[u]-d),r1=Findr(a[u]-d);
			int l2=Findl(a[u]+d),r2=Findr(a[u]+d);
			if(l1>=1){
				w=a[u]-d-a[l1];
				if(w<L[l1]){
					L[l1]=w,q.push(make_tuple(w,l1,1));
				}
				w=max(ans[u],w);
				if(w<ans[l1]){
					ans[l1]=w,q.push(make_tuple(w,l1,0));
				}
			}
			if(l2>=1){
				w=a[u]+d-a[l2];
				if(w<L[l2]){
					L[l2]=w,q.push(make_tuple(w,l2,1));
				}
				w=max(ans[u],w);
				if(w<ans[l2]){
					ans[l2]=w,q.push(make_tuple(w,l2,0));
				}
			}
			if(r1<=n){
				w=a[r1]-(a[u]-d);
				if(w<R[r1]){
					R[r1]=w,q.push(make_tuple(w,r1,2));
				}
				w=max(ans[u],w);
				if(w<ans[r1]){
					ans[r1]=w,q.push(make_tuple(w,r1,0));
				}	
			}
			if(r2<=n){
				w=a[r2]-(a[u]+d);
				if(w<R[r2]){
					R[r2]=w,q.push(make_tuple(w,r2,2));
				}
				w=max(ans[u],w);
				if(w<ans[r2]){
					ans[r2]=w,q.push(make_tuple(w,r2,0));
				}
			}
		}
		else if(type==1){
			if(u>1){
				w=L[u]+a[u]-a[u-1];
				if(w<L[u-1]){
					L[u-1]=w,q.push(make_tuple(w,u-1,1));
				}
				w=max(ans[u],w);
				if(w<ans[u-1]){
					ans[u-1]=w,q.push(make_tuple(w,u-1,0));
				}	
			}		
		}
		else{
			if(u<n){
				w=R[u]+a[u+1]-a[u];
				if(w<R[u+1]){
					R[u+1]=w,q.push(make_tuple(w,u+1,2));
				}
				w=max(ans[u],w);
				if(w<ans[u+1]){
					ans[u+1]=w,q.push(make_tuple(w,u+1,0));
				}
			}
		}
	}
	while(Q--){
		int u=read(),k=read();
		printf(ans[u]<=k?"Yes\n":"No\n");
	}
	return 0;
}