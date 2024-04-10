#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=150005,NC=N*31,mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
int ch[NC][2],nc=1,siz[NC],x,pw[N];
void ins(int x){
	int u=1;
	for(int i=29;i>=0;--i){
		int tmp=x>>i&1;
		if(!ch[u][tmp])ch[u][tmp]=++nc;
		u=ch[u][tmp],++siz[u];
	}
}
int dfs(int u,int v,int dep){
	if(!u||!v||dep==-1)return 0;
	if(!(x>>dep&1))return (dfs(ch[u][0],ch[v][0],dep-1)+dfs(ch[u][1],ch[v][1],dep-1))%mod;
	if(u==v){
		int ans=(pw[siz[ch[u][0]]]-1+pw[siz[ch[u][1]]]-1)%mod;
		add(ans,dfs(ch[u][0],ch[u][1],dep-1));return ans;
	}
	else{
		int ans=(1LL*(pw[siz[ch[u][0]]]-1)*(pw[siz[ch[v][0]]]-1)+1LL*(pw[siz[ch[u][1]]]-1)*(pw[siz[ch[v][1]]]-1))%mod;
		int A=dfs(ch[u][0],ch[v][1],dep-1),B=dfs(ch[u][1],ch[v][0],dep-1),a=ch[u][0],b=ch[u][1],c=ch[v][0],d=ch[v][1];
		add(ans,1LL*A*B%mod),add(ans,1LL*A*(pw[siz[c]]+pw[siz[b]]-1)%mod),add(ans,1LL*B*(pw[siz[a]]+pw[siz[d]]-1)%mod);
		return ans;
	}
}
int main(){
	pw[0]=1;for(int i=1;i<N;++i)pw[i]=pw[i-1],add(pw[i],pw[i]);
	int n;read(n,x),++x;
	if(x==(1<<30))return printf("%d\n",pw[n]-1),0;
	for(int i=1,x;i<=n;++i)read(x),ins(x);
	printf("%d\n",dfs(1,1,29));
	return 0;
}