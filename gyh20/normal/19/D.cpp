#include<bits/stdc++.h>
#define re register
#define mp make_pair
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0'||v>'9')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int typ[800002],a[800002],b[800002],n,m,lsh[800002],cnt;
map<int,int>lll,lllb;
set<pair<int,int> >c[800002];
int main(){
	n=read();
	for(re int i=1;i<=n;++i){
		re char s;
		cin>>s;
		if(s=='a'){
			typ[i]=1;
			a[i]=read(),b[i]=read();
			lsh[++cnt]=b[i];
		}
		if(s=='r'){
			typ[i]=2;
			a[i]=read(),b[i]=read();
			lsh[++cnt]=b[i];
		}
		if(s=='f'){
			typ[i]=3;
			a[i]=read()+1,b[i]=read()+1;
			lsh[++cnt]=b[i];
		}
	}lsh[++cnt]=1e9,lsh[++cnt]=1e9;
	sort(lsh+1,lsh+cnt+1);
	for(re int i=1;i<=n;++i)lllb[cnt-(lower_bound(lsh+1,lsh+cnt+1,b[i])-lsh)+1]=b[i],b[i]=lower_bound(lsh+1,lsh+cnt+1,b[i])-lsh;
	for(re int i=1;i<=n;++i)b[i]=cnt-b[i]+1;
	for(re int i=1;i<=cnt;++i)c[i].insert(mp(2e9,1));
	for(re int i=1;i<=n;++i){
	//	printf("%d %d\n",a[i],b[i]);
		if(typ[i]==1){
			for(re int j=b[i];j<=cnt;j+=j&(-j))c[j].insert(mp(a[i],-b[i]));
		}
		else if(typ[i]==2){
			for(re int j=b[i];j<=cnt;j+=j&(-j))c[j].erase(mp(a[i],-b[i]));
		}
		else{
			re pair<int,int> ans=mp(2e9,cnt);
			for(re int j=b[i];j;j-=j&(-j))ans=min(ans,*c[j].lower_bound(mp(a[i],-b[i])));
			if(ans.first!=2e9)printf("%d %d\n",ans.first,lllb[-ans.second]);
			else puts("-1");
		}
	}
}