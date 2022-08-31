#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,a[100002],m,c[100002],f[100002],g[100002],lp;
char usd[100002];
vector<int>ans[100002],tmp1;
inline void gmx(re int&x,re int y){y>x&&(x=y);}
inline void add(re int x,re int y){for(;x<=n;x+=x&(-x))gmx(c[x],y);}
inline int ask(re int x,re int s=0){for(;x;x^=x&(-x))gmx(s,c[x]);return s;}
int main(){
	t=read(),srand(time(0));
	while(t--){
		n=read(),m=0;
		vector<int>tmp;
		for(re int i=1;i<=n;++i)tmp.push_back(read());tmp1=tmp;
		re int num=0;
		while(1){
			++num;
			while(tmp.size()){
				re int k=0;
				while((k*(k+1)>>1)<=tmp.size())++k;--k;
				fill(c,c+n+1,0),fill(usd,usd+n+1,0);vector<int>nw;
				re int mx1=0,mx2=0;
				for(re int i=0;i<tmp.size();++i)add(tmp[i],f[i]=ask(tmp[i])+1),mx1=max(mx1,f[i]);
				if(mx1>k){
					re int lst=n;
					for(re int i=tmp.size()-1;~i;--i)if(f[i]==mx1&&tmp[i]<=lst)lst=tmp[i],--mx1,usd[i]=1;
					++m,ans[m].clear();for(re int i=0;i<tmp.size();++i)if(usd[i])ans[m].push_back(tmp[i]);else nw.push_back(tmp[i]);
					tmp=nw;
				}
				else{
					for(re int i=1;i<=mx1;++i){
						++m,ans[m].clear();
						for(re int j=0;j<tmp.size();++j)if(f[j]==i)ans[m].push_back(tmp[j]);
					}
					break;
				}
			}
			printf("%d\n",m);
			for(re int i=1;i<=m;++i){
				printf("%d ",ans[i].size());
				for(auto z:ans[i])printf("%d ",z);
				puts("");
			}
			break;
		}
	}
}