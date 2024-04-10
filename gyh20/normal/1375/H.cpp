#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,q,a[1000002],bl[1000002],B,tot,U[5200002],V[5200002],ans[1000002],pos[1000002];
inline int Merge(re int x,re int y){
	if(!x||!y)return x+y;
	++tot,U[tot]=x,V[tot]=y;
	if(tot>2200000)printf("%d\n",tot);
	return tot;
}
struct node{
	vector<vector<int> >V;basic_string<int>X;
	inline int ask(re int l,re int r){
		re int p1=lower_bound(X.begin(),X.end(),l)-X.begin(),p2=upper_bound(X.begin(),X.end(),r)-X.begin()-1;
		if(p2<0||p1>=X.size()||p1>p2)return 0;
		return V[p1][p2-p1];
	}
	inline void Merge(node&A,node&B){
		X=A.X+B.X,sort(X.begin(),X.end()),V.resize(X.size());
		for(re int j=0;j<V.size();++j)V[j].resize(V.size()-j);
		for(re int i=0;i<V.size();++i)
			for(re int j=i;j<V.size();++j)
				V[i][j-i]=::Merge(A.ask(X[i],X[j]),B.ask(X[i],X[j]));
	}
}T[100002];
inline node build(re int l,re int r){
	node s,sl,sr;
	if(l==r){
		s.V.resize(1),s.V[0].resize(1),s.X.resize(1),s.V[0][0]=s.X[0]=pos[l];
		return s;
	}
	re int mid=l+r>>1;
	sl=build(l,mid),sr=build(mid+1,r),s.Merge(sl,sr);return s;
}
int main(){
	n=read(),q=read(),B=256,tot=n;
	for(re int i=1;i<=n;++i)a[i]=read(),bl[i]=(i-1)/B+1,pos[a[i]]=i;
	for(re int i=1;i<=n;++i)if((i-1)*B+1<=n)T[i]=build((i-1)*B+1,min(i*B,n));
	for(re int j=1;j<=q;++j){
		re int l=read(),r=read();
		for(re int i=1;i<=n/B+1;++i)ans[j]=Merge(ans[j],T[i].ask(l,r));
	}
	printf("%d\n",tot);
	for(re int i=n+1;i<=tot;++i)printf("%d %d\n",U[i],V[i]);
	for(re int i=1;i<=q;++i)printf("%d ",ans[i]);
}