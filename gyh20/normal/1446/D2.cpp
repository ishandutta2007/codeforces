#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
vector<int>V[200002];
int n,m,a[200002],ans,A[200002],B[200002],lst[400002],X,Y,pos;
char usd[200002];
inline void solve(re int o1=0,re int o2=n+1){
	for(re int i=0;i<=m+m;++i)lst[i]=-1;
	re int s=m;lst[s]=o1;B[m+1]=o2;
	for(re int i=1;i<=m&&B[i]<o2;++i){
		if(B[i]<=o1)continue;
		s+=A[i];
		if(~lst[s])ans=max(ans,min(B[i+1],o2)-lst[s]-1);
		else lst[s]=B[i];
	}
}
int main(){
	n=read();
	for(re int i=1;i<=n;++i)V[a[i]=read()].push_back(i);
	pos=1;
	for(re int i=2;i<=n;++i)if(V[i].size()>V[pos].size())pos=i;
	for(re int i=1;i<=n;++i)
		if(i^pos&&V[i].size()){m=0;
			if(V[i].size()<=100){
				X=i,Y=pos;
				for(re int j=0;j<V[i].size();++j){
					re int x=V[i][j],y=lower_bound(V[pos].begin(),V[pos].end(),x)-V[pos].begin();
					re int p1=j,p2=max(0,y-(int)V[i].size()+j-2),lmt=min(y+V[i].size()-j+2,V[pos].size());m=0;
					while(j&&V[pos][p2]<V[i][j-1])++p2;
					re int pp=0,pp1=n+1;
					if(j)pp=max(pp,V[i][j-1]);
					if(p2)pp=max(pp,V[pos][p2-1]);
					while(p1<V[i].size()&&p2<lmt){
						if(V[i][p1]<=V[pos][p2])A[++m]=1,B[m]=V[i][p1++];
						else A[++m]=-1,B[m]=V[pos][p2++];
					}
					while(p1<V[i].size())A[++m]=1,B[m]=V[i][p1++];
					while(p2<lmt)A[++m]=-1,B[m]=V[pos][p2++];
					if(p2<V[pos].size())pp1=min(pp1,V[pos][p2]);
					solve(pp,pp1);
				}
			}
			else{X=-1;
				re int p1=0,p2=0;
				while(p1<V[i].size()&&p2<V[pos].size()){
					if(V[i][p1]<=V[pos][p2])A[++m]=1,B[m]=V[i][p1++];
					else A[++m]=-1,B[m]=V[pos][p2++];
				}
				while(p1<V[i].size())A[++m]=1,B[m]=V[i][p1++];
				while(p2<V[pos].size())A[++m]=-1,B[m]=V[pos][p2++];
				solve();
			}
		}
	printf("%d",ans);
}