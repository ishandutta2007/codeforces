#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,p[200002],d[200002],n,mx1,mx2,m;
struct node{
	int x,y;
	bool operator <(const node A)const{return x==A.x?y<A.y:x<A.x;}
};
vector<node>A;
inline void Ins(re int x,re int y,re int z){
	if(x>y)return;
	A.push_back((node){x,z}),A.push_back((node){y+1,-z});
}
signed main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)p[i]=read();
	for(re int i=1;i<=m;++i)d[i]=read()*2;
	sort(d+1,d+m+1);
	d[m+1]=1e12;
	re int pos=0;d[0]=-1e12;
	for(re int i=1;i<=n;++i){
		while(pos<m&&d[pos+1]<=(i-1)*200)++pos;
		re int l=d[pos],r=d[pos+1],x=(i-1)*200;
		re int mid1=x-(r-x),mid2=x+(x-l);
		Ins(max(l+1,mid1+1),min(r-1,mid2-1),p[i]);
	}
	sort(A.begin(),A.end());
	re int mx=0,sz=0;
	for(re int i=0;i<A.size();++i)sz+=A[i].y,mx=max(mx,sz);
	printf("%lld",mx);
}