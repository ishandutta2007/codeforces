#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
struct node{
	int x,y,z,id,id1;
	bool operator <(const node A)const{return x==A.x?y<A.y:x<A.x;}
}p[2002],B;
int n,fa[2002],pos[2002];
char usd[2002];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline bool cmp(re node x,re node y){
	return atan2(y.y-B.y,y.x-B.x)<atan2(x.y-B.y,x.x-B.x);
}
inline void Merge(re int x,re int y){
	fa[root(x)]=root(y);
}
vector<int>A,bb;
inline void Swap(re int x,re int y){
	A.push_back(p[x].id1),bb.push_back(p[y].id1);
	swap(p[x].z,p[y].z);
}
int main(){
	n=read();
	int nn=0;
	for(re int i=1;i<=n;++i){++nn;
		fa[nn]=nn,p[i].x=read(),p[i].y=read(),p[i].z=read(),p[i].id=nn,p[i].id1=nn;
		if(p[i].id==p[i].z){
			--i;--n;continue;
		}
	}
	sort(p+1,p+n+1);B=p[1];
	if(n==0)return puts("0"),0;
	sort(p+2,p+n+1,cmp);
	for(re int i=1;i<=n;++i)Merge(p[i].id,p[i].z);
	for(re int i=1;i<=2000;++i)pos[p[i].id]=i;
	for(re int i=2;i<n;++i)
		if(root(p[i].z)^root(p[i+1].z))
			Swap(i,i+1),Merge(p[i].z,p[i+1].z);
	for(re int i=1;i<n;++i)Swap(1,pos[p[1].z]);
	printf("%u\n",A.size());
	for(re int i=0;i<A.size();++i)printf("%d %d\n",A[i],bb[i]);
}