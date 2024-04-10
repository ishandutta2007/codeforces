#include<bits/stdc++.h>
typedef long long ll;
const int N=200005,mod1=1000000007,mod2=1000000009;
struct hash{
	ll b,c;
	inline hash(){b=0,c=0;}
	inline hash(int o){b=o,c=o;}
	inline hash(int x,int y){b=x,c=y;}
	inline hash operator += (const hash &o){(b+=o.b)>=mod1&&(b-=mod1),(c+=o.c)>=mod2&&(c-=mod2);return *this;}
	inline hash operator + (const hash &o)const{hash a(*this);return a+=o;}
	inline hash operator -= (const hash &o){(b-=o.b)<0&&(b+=mod1),(c-=o.c)<0&&(c+=mod2);return *this;}
	inline hash operator - (const hash &o)const{hash a(*this);return a-=o;}
	inline hash operator * (const hash &o)const{return hash(b*o.b%mod1,c*o.c%mod2);}
	inline bool operator == (const hash &o)const{return b==o.b&&c==o.c;}
	inline bool operator < (const hash &o)const{return b==o.b?c<o.c:b<o.b;}
}pw[N],f[N],g[N];
const hash base=hash(2333);
struct PAM{
	char s[N];int n,ch[N][26],fa[N],len[N],nc,p,edp[N],anc[N][20],nd[N];hash w[N];
	PAM(){fa[0]=fa[1]=1,len[1]=-1,p=1,nc=1;}
	void ins(int x){
		int c=s[x]-97;
		while(s[x-len[p]-1]!=s[x])p=fa[p];	
		if(!ch[p][c]){
			int u=++nc,q=fa[p];len[u]=len[p]+2;
			while(s[x-len[q]-1]!=s[x])q=fa[q];
			fa[u]=ch[q][c],ch[p][c]=u,edp[u]=x;
		}
		p=ch[p][c];
	}
	void build(){
		for(int i=1;i<=n;++i)ins(i),nd[i]=p;
		for(int i=0;i<=nc;++i)anc[i][0]=fa[i];
		for(int j=1;j<20;++j)for(int i=0;i<=nc;++i)anc[i][j]=anc[anc[i][j-1]][j-1];
	}
	int jump(int x,int k){
		if(len[x]<=k)return len[x];
		for(int i=19;i>=0;--i)if(len[anc[x][i]]>k)x=anc[x][i];
		x=fa[x];return len[x];
	}
}A,B,AR,BR;
char s[N],t[N];
std::set<hash> SA,SB;
std::map<hash,int> MA,MB,mp;
inline hash H1(int l,int r){return f[r]-f[l-1]*pw[r-l+1];}
inline hash H2(int l,int r){return g[r]-g[l-1]*pw[r-l+1];}
int main(){
	pw[0]=hash(1);for(int i=1;i<N;++i)pw[i]=pw[i-1]*base;
	scanf("%s%s",s+1,t+1);int n=strlen(s+1),m=strlen(t+1);
	A.n=n;for(int i=1;i<=n;++i)A.s[i]=s[i];
	B.n=m;for(int i=1;i<=m;++i)B.s[i]=t[i];
	AR.n=n;for(int i=1;i<=n;++i)AR.s[n-i+1]=s[i];
	BR.n=m;for(int i=1;i<=m;++i)BR.s[m-i+1]=t[i];
	A.build(),B.build(),AR.build(),BR.build();
	for(int i=1;i<=n;++i)f[i]=f[i-1]*base+hash(s[i]);
	for(int i=1;i<=m;++i)g[i]=g[i-1]*base+hash(t[i]);
	for(int i=2;i<=A.nc;++i)SA.insert(H1(A.edp[i]-A.len[i]+1,A.edp[i]));
	for(int i=2;i<=B.nc;++i)SB.insert(H2(B.edp[i]-B.len[i]+1,B.edp[i]));
	for(int i=2;i<=A.nc;++i)if(A.fa[i]>1){
		int j=A.fa[i],r=A.edp[i],l=r-(A.len[i]-A.len[j])+1;
		A.w[i]=H1(l,r);
	}
	for(int i=2;i<=B.nc;++i)if(B.fa[i]>1){
		int j=B.fa[i],l=B.edp[i]-B.len[i]+1,r=l+(B.len[i]-B.len[j])-1;
		B.w[i]=H2(l,r);
	}
	ll ans=1LL*(A.nc-1)*(B.nc-1),res=0;
	for(int i=2;i<=A.nc;++i)if(A.fa[i]>1){
		int j=A.fa[i],r=A.edp[i],l=r-(A.len[i]-A.len[j])+1;
		hash S,T;
		int len=AR.jump(AR.nd[n-l+1],r-l+1);
		if(len==r-l+1)continue;
		if(A.jump(A.nd[r],r-l+1-len)==r-l+1-len)T=H1(l,r)*pw[len]+H1(l,l+len-1);
		else{
			len=A.jump(A.nd[r],r-l+1);
			if(A.jump(A.nd[r-len],r-l+1-len)==r-l+1-len)T=H1(l,r)*pw[r-len-l+1]+H1(l,r-len);
			else continue;
		}
		if(SB.find(T)!=SB.end())++res;
	}
	for(int i=2;i<=B.nc;++i)if(B.fa[i]>1){
		int j=B.fa[i],l=B.edp[i]-B.len[i]+1,r=l+(B.len[i]-B.len[j])-1;
		hash S,T;
		int len=BR.jump(BR.nd[m-l+1],r-l+1);
		if(len==r-l+1)continue;
		if(B.jump(B.nd[r],r-l+1-len)==r-l+1-len)T=H2(l+len,r)*pw[r-l+1]+H2(l,r);
		else{
			len=B.jump(B.nd[r],r-l+1);
			if(B.jump(B.nd[r-len],r-l+1-len)==r-l+1-len)T=H2(r-len+1,r)*pw[r-l+1]+H2(l,r);
			else continue;
		}
		if(SA.find(T)!=SA.end())++res;
	}
	for(int i=2;i<=A.nc;++i)if(A.fa[i]>1&&A.len[i]<=A.len[A.fa[i]]*2)++MA[A.w[i]];
	for(int i=2;i<=B.nc;++i)if(B.fa[i]>1&&B.len[i]<=B.len[B.fa[i]]*2)++MB[B.w[i]];
	for(int i=2;i<=A.nc;++i)if(A.fa[i]>1)res+=MB[A.w[i]];
	for(int i=2;i<=B.nc;++i)if(B.fa[i]>1)res+=MA[B.w[i]];
	for(int i=2;i<=A.nc;++i)if(A.fa[i]>1)++mp[A.w[i]];
	for(int i=2;i<=B.nc;++i)if(B.fa[i]>1)res-=mp[B.w[i]];
	printf("%lld\n",ans-res);
	return 0;
}