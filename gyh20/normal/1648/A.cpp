#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m;
char s[1000002];
vector<int>A[100002]; 
map<int,vector<int> >X,Y;
int main(){
	t=1;
	while(t--){
		n=read(),m=read();long long ans=0;X.clear(),Y.clear();
		for(re int i=1;i<=n;++i){
			A[i].resize(m+1);
			for(re int j=1;j<=m;++j)A[i][j]=read(),X[A[i][j]].push_back(i),Y[A[i][j]].push_back(j);
		}
		for(auto o:X){
			vector<int>tmp=o.second;
			sort(tmp.begin(),tmp.end());
			re long long s=0;
			for(re int j=0;j<tmp.size();++j)ans+=1ll*j*tmp[j]-s,s+=tmp[j];
		}
		for(auto o:Y){
			vector<int>tmp=o.second;
			sort(tmp.begin(),tmp.end());
			re long long s=0;
			for(re int j=0;j<tmp.size();++j)ans+=1ll*j*tmp[j]-s,s+=tmp[j];
		}
		printf("%lld\n",ans);
	}
}