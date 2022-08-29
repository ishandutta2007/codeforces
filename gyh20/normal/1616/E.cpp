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
int t,n,m,ans,c[100002],pos[27],sum;
char a[1000002],b[1000002];
vector<int>V[27];
inline void add(re int x,re int y){
	for(;x<=n;x+=x&(-x))c[x]+=y;
}
inline int ask(re int x,re int s=0){
	for(;x;x^=x&(-x))s+=c[x];
	return s;
}
signed main(){
	t=read();
	while(t--){
		n=read(),ans=1e18,sum=0;
		scanf("%s%s",a+1,b+1);
		for(re int i=0;i<=26;++i)V[i].clear(),pos[i]=0;
		for(re int i=1;i<=n;++i)c[i]=0;
		for(re int i=1;i<=n;++i)add(i,1),V[a[i]-'a'].push_back(i);
		for(re int i=1;i<=n;++i){
			re int mn=n+1;
			for(re int j=0;j<b[i]-'a';++j)
				if(pos[j]<V[j].size())
					mn=min(mn,V[j][pos[j]]);
			if(mn<=n)ans=min(ans,sum+ask(mn)-1);
			if(pos[b[i]-'a']==V[b[i]-'a'].size())break;
			add(V[b[i]-'a'][pos[b[i]-'a']],-1),sum+=ask(V[b[i]-'a'][pos[b[i]-'a']]);
			++pos[b[i]-'a'];
		}
		if(ans>=1e15)puts("-1");
		else printf("%lld\n",ans);
	}
}