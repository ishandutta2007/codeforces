#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,m,p[200002],a[200002],b[200002],stk[200002],tp,R[200002];
ll ans[200002],c[200002];
set<int>S;set<int>::iterator it1,it2;
struct node{int x,id;};
vector<node>Q[200002];
inline void Add(re int l,re int r,re int v){if(l==0)l=1;Q[l].push_back((node){r,v});}
inline void add(re int x,re ll y){for(;x<=n+1;x+=x&(-x))c[x]+=y;}
inline ll ask(re int x,re ll s=0){for(;x;x^=x&(-x))s+=c[x];return s;}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)p[i]=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i)b[i]=read();
	S.insert(0),S.insert(n+1);
	Add(0,n+1,0); 
	for(re int i=1;i<=m;++i){
		int x=read();
		if(S.find(x)!=S.end()){
			S.erase(x),it1=it2=S.lower_bound(x),--it1;
			Add(*it1,*it2,i),Add(*it1,x,-i),Add(x,*it2,-i); 
		}
		else{
			it1=it2=S.lower_bound(x),--it1;
			Add(*it1,*it2,-i),Add(*it1,x,i),Add(x,*it2,i); 
			S.insert(x);
		}
	}
	for(re int i=1;i<=n;++i){
		while(tp&&p[i]>p[stk[tp]])R[stk[tp]]=i,--tp;
		stk[++tp]=i; 
	}for(re int i=1;i<=tp;++i)R[stk[i]]=n+1;
	for(re int i=n;i;--i){
		add(i+1,a[i]);
		if(ask(R[i])>b[i])add(R[i],b[i]-ask(R[i]));assert(ask(R[i])<=b[i]);
		for(auto z:Q[i])if(z.id>=0)ans[z.id]+=ask(z.x);else ans[-z.id]-=ask(z.x);
	}
	for(re int i=1;i<=m;++i)ans[i]+=ans[i-1],printf("%lld\n",ans[i]);
}