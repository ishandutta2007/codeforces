#include<bits/stdc++.h>
using namespace std ;
#define rep(i,s,t) for(register int i=(s);i<=(t);++i)
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1]
#define up(x) (t[x].sz=t[ls(x)].sz+t[rs(x)].sz+1)
#define pb push_back
#define gc getchar
int gi(){char cc=gc();int cn=0,f=1;while(cc<'0'||cc>'9'){if(cc=='-')f=-f;cc=gc();}
	while(cc>='0'&&cc<='9')cn=cn*10+cc-'0',cc=gc();return cn*f;
}const int N=2e5+5;const int M=50+5;struct LCT{ int mk,fa,ch[2],col,sz,c; }t[N];vector<int>G[N]; 
int n,Q,nm,mn,st[N],top,tr[N*2];char s[M]; 
void ad(int x,int k){for(int i=x;i<=mn;i+=(i&(-i)))tr[i]+=k;}
int qy(int x){int s=0;for(int i=x;i;i-=(i&(-i)))s+=tr[i];return s;}
bool is(int x){return (rs(t[x].fa)!= x)&&(ls(t[x].fa)!=x);}
void dfs(int x,int fa){if(fa^x)t[x].fa=fa;for(int v:G[x])if(fa^v)dfs(v,x);}
void sh(int x){if(t[x].mk)swap(ls(x),rs(x)),t[ls(x)].mk^=1,t[rs(x)].mk^=1,t[x].mk=0; 
	if(t[x].c)t[ls(x)].col=t[x].c,t[rs(x)].col=t[x].c,t[ls(x)].c=t[x].c,t[rs(x)].c=t[x].c,t[x].c=0;
}void ro(int x){int f=t[x].fa,ff=t[f].fa,d=(rs(f)==x),c=t[x].ch[d^1];t[x].fa=ff;
	if(!is(f))t[ff].ch[rs(ff)==f]=x;t[x].ch[d^1]=f,t[f].fa=x,t[f].ch[d]=c,t[c].fa=f,up(f),up(x); 
}void S(int x){int u=x;st[++top]=u;while(!is(u))st[++top]=(u=t[u].fa);while(top)sh(st[top--]);
	while(!is(x)){int f=t[x].fa,ff=t[f].fa;if(!is(f))(rs(ff)==f)^(rs(f)==x)?ro(x):ro(f);ro(x);} 
}void rt(int u){int x=u;++nm;for(int y=0;x;x=t[y=x].fa)S(x),rs(x)=0,up(x),ad(t[x].col,-t[x].sz),
	rs(x)=y,up(x);S(u),t[u].col=nm,t[u].c=nm,t[u].mk^=1,sh(u),ad(t[u].col,t[u].sz); 
}int Qy(int x) {S(x);return qy(t[x].col-1)+t[rs(x)].sz+1;} 
void Cp(int x,int y){int fx=Qy(x),fy=Qy(y);printf("%d\n",(fx<fy)?x:y);}
void it(){int cnt=n,u,s,v;for(int i=n;i>=1;--i){if(t[i].col)continue;u=i,s=v=0;
	while(!t[u].col&&u)t[u].col=cnt,rs(u)=v,up(u),v=u,u=t[u].fa,++ s;ad(cnt,s),--cnt;}
}signed main(){ 
	n=gi(),Q=gi();int x,y;rep(i,1,n)t[i].sz=1;rep(i,2,n) x=gi(),y=gi(),G[x].pb(y),G[y].pb(x);
	dfs(n,n),mn=n+Q,nm=n,it();while(Q--){cin>>s+1;if(s[1]=='u')x=gi(),rt(x);if(s[1]=='w')x=gi(),
	printf("%d\n",Qy(x));if(s[1]=='c')x=gi(),y=gi(),Cp(x,y);}return 0;
}