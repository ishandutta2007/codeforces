#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=2005;
int ch[N][2],Fa[N],nc,siz[N],S,mn,rt,I,nd[N];bool vis[N];
inline void link(int x,int c,int y){ch[x][c]=y,Fa[y]=x;}
void getrt(int x,int fa){
	std::vector<int> e;
	if(ch[x][0])e.pb(ch[x][0]);
	if(ch[x][1])e.pb(ch[x][1]);
	if(~Fa[x])e.pb(Fa[x]);
	int tmp=0;siz[x]=1;for(auto v:e)if(!vis[v]&&v!=fa)getrt(v,x),siz[x]+=siz[v],chmax(tmp,siz[v]);
	chmax(tmp,S-siz[x]);if(tmp<=mn)mn=tmp,rt=x;
}
void solve(int x){
	getrt(x,0),S=siz[x],mn=1e9,getrt(x,0),vis[x=rt]=1;
	int a=ch[x][0],b=ch[x][1];char ans;
	if(a){
		printf("%d %d %d\n",nd[a],nd[b],I),fflush(stdout);
		do{ans=getchar();}while(!isalpha(ans));
	}
	if(!a||ans=='X'){
		if(Fa[x]==-1||vis[Fa[x]]){
			int u=++nc;nd[u]=nd[I]=I;
			if(~Fa[x])link(Fa[x],x==ch[Fa[x]][1],u);
			link(u,0,x),link(u,1,I);
		}
		else solve(Fa[x]);
	} 
	else{
		int c=ch[x][ans=='Y'];
		if(vis[c]){
			int u=++nc;nd[u]=nd[I]=I;
			link(x,ans=='Y',u),link(u,0,c),link(u,1,I);
		}
		else solve(c);
	}
}
int main(){
	int n;read(n);
	memset(Fa,-1,sizeof(Fa)),nc=n+1,link(n+1,0,1),link(n+1,1,2),nd[1]=1,nd[2]=2,nd[n+1]=1;
	for(int i=3;i<=n;++i)memset(vis,0,n+n+3),I=i,solve(n+1);
	printf("-1\n");for(int i=1;i<=nc;++i)printf("%d%c",Fa[i]," \n"[i==nc]);
	fflush(stdout);
	return 0;
}