#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int a[N],c[N];std::vector<int> v[N];
int t[N*4],T[N],POS,pos,b[N],s[N],d[N+N];
int main(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]),++c[a[i]],v[a[i]].pb(i);
	int x=std::max_element(c,c+n+1)-c;for(int i=1;i<=n;++i)b[i]=b[i-1]+(a[i]==x);
	std::set<int> S;for(int i=1;i<=n;++i)if(a[i]==x)S.insert(i);
	int ans=0;memset(d,-1,sizeof(d));
	for(int y=1;y<=n;++y)if(y!=x&&!v[y].empty()){
		POS=0,pos=0,t[++pos]=0,t[++pos]=n;
		for(auto i:v[y]){
			t[++pos]=i,t[++pos]=i-1;
			auto it=S.lower_bound(i);
			if(it!=S.end()){
				t[++pos]=*it-1,t[++pos]=*it;
				if(++it!=S.end())t[++pos]=*it-1;
				T[++POS]=*--it,S.erase(it);
			}
			it=S.lower_bound(i);
			if(it!=S.begin()){
				--it,t[++pos]=*it,t[++pos]=*it-1;
				if(it!=S.begin())t[++pos]=*--it,++it;
				T[++POS]=*it,S.erase(it);
			}
		}
		std::sort(t+1,t+pos+1),pos=std::unique(t+1,t+pos+1)-t-1;
		for(int i=1,j;i<=pos;++i){
			j=t[i],s[i]=s[i-1]+(a[j]==y?-1:0);
			if(~d[b[j]+s[i]+N])ans=std::max(ans,j-d[b[j]+s[i]+N]);
			else d[b[j]+s[i]+N]=j;
		}
		for(int i=1;i<=pos;++i)d[b[t[i]]+s[i]+N]=-1;
		for(int i=1;i<=POS;++i)S.insert(T[i]);
	}
	printf("%d\n",ans);
	return 0;
}