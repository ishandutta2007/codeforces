#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
int n,a[200002],ans;
map<int,int>s;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline void gmx(re int &x,re int y){y>x&&(x=y);}
signed main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	s[a[1]-1]=0;
	for(re int i=1;i<n;++i)
		for(auto j=s.lower_bound(a[i+1]);j!=s.end();s.erase(j++)){
			re int x=j->first,y=j->second;
			gmx(s[x%a[i+1]],y+i*(x-x%a[i+1]));
			gmx(s[a[i+1]-1],y+i*((x+1)/a[i+1]*a[i+1]-a[i+1]));
		}
	for(auto i=s.begin();i!=s.end();++i)ans=max(ans,(i->first)*n+(i->second));
	printf("%lld",ans);
}