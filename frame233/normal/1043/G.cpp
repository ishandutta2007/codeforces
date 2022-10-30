#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=200005;
char s[N],t[N];int n,m,Log2[N];
struct rmq{
	int f[N][20];
	inline int ask(int l,int r){int k=Log2[r-l+1];return std::min(f[l][k],f[r-(1<<k)+1][k]);}
	void init(int *a){for(int i=n;i>=1;--i){f[i][0]=a[i];for(int j=1;j<20&&i+(1<<(j-1))<=n;++j)f[i][j]=std::min(f[i][j-1],f[i+(1<<(j-1))][j-1]);}}
};
struct DS{
	int sa[N],rk[N],tax[N],tp[N],H[N];rmq _;
	void Rsort(){
		memset(tax,0,(m+3)<<2);
		for(int i=1;i<=n;++i)++tax[rk[i]];
		for(int i=1;i<=m;++i)tax[i]+=tax[i-1];
		for(int i=n;i>=1;--i)sa[tax[rk[tp[i]]]--]=tp[i];
	}
	void SA(char *s){
		for(int i=1;i<=n;++i)rk[i]=s[i],tp[i]=i;
		m=127,Rsort();
		for(int w=1,p=0;p<n;w<<=1,m=p){
			p=0;for(int i=0;i<w;++i)tp[++p]=n-i;
			for(int i=1;i<=n;++i)if(sa[i]>w)tp[++p]=sa[i]-w;
			Rsort(),memcpy(tp,rk,(n+3)<<2),rk[sa[1]]=p=1;
			for(int i=2;i<=n;++i)rk[sa[i]]=tp[sa[i-1]]==tp[sa[i]]&&tp[sa[i-1]+w]==tp[sa[i]+w]?p:++p;
		}
		for(int i=1,k=0;i<=n;++i){
			if(rk[i]==1)continue;
			if(k)--k;
			for(int j=sa[rk[i]-1];s[i+k]==s[j+k];++k);
			H[rk[i]]=k;
		}
		_.init(H);
	}
	inline int ask(int l,int r){
		l=rk[l],r=rk[r];if(l>r)std::swap(l,r);
		return _.ask(l+1,r);
	}
}a,b;
inline int lcp(int x,int y){return a.ask(x,y);}
inline int lcs(int x,int y){return b.ask(n-x+1,n-y+1);}
struct seg{
	int mn[524288+5],M;
	void build(int n){for(M=1;M<=n+2;M<<=1);memset(mn,63,sizeof(mn));}
	void upd(int s,int t,int C){
		if(s>t)return;
		for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1){
			if(~s&1)mn[s^1]=C;
			if(t&1)mn[t^1]=C;
		}
	}
	void out(int *a,int op){
		for(int i=2;i<=n+M;++i)chmin(mn[i],mn[i>>1]);
		for(int i=1;i<=n;++i)a[i]=i+op*(2*mn[i+M]-1);
	}
}c,d;
int sl[N],sr[N],cnt[26],B,tr[N],tl[N],last[26];rmq _;
bool issol(int l,int r){
	if(r-l+1>26)return true;
	memset(cnt,0,sizeof(cnt));
	for(int i=l;i<=r;++i)++cnt[s[i]-97];
	return *std::max_element(cnt,cnt+26)>1;
}
bool check1(int l,int r){
	int len=r-l+1,x=len;
	for(int i=2;i*i<=x;++i)if(x%i==0){
		while(x%i==0)x/=i;
		if(lcp(l,l+len/i)>=len-len/i)return true;
	}
	if(x>1)return lcp(l,l+len/x)>=len-len/x;
	return false;
}
bool check2(int l,int r){
	if(sl[l]<=r||sr[r]>=l)return true;
	int len=r-l+1;
	for(int i=1;i<=B&&i+i<=len;++i)if(lcp(l,r-i+1)>=i)return true;
	for(int _=std::max(1,a.rk[l]-B),ed=std::min(n,a.rk[l]+B);_<=ed;++_){
		int i=a.sa[_];
		if(l<i&&i<=r&&r-i+1>B&&lcp(l,i)>=r-i+1)return true;
	}
	return false;
}
inline bool check3(int l,int r){return tr[l]<=r||tl[r]>=l||_.ask(l,r)<=r;}
int main(){
	for(int i=2;i<N;++i)Log2[i]=Log2[i>>1]+1;
	read(n),scanf("%s",s+1);for(int i=1;i<=n;++i)t[n-i+1]=s[i];
	a.SA(s),b.SA(t),c.build(n),d.build(n);
	for(int len=n/2;len>=1;--len){
		for(int x=1,y=len+1;y<=n;x+=len,y+=len)if(s[x]==s[y]){
			int l1=std::min(len,lcp(x,y)),l2=std::min(len,lcs(x,y));
			c.upd(x-l2+1,x+l1-len,len),d.upd(y-l2+len,y+l1-1,len);
		}
	}
	c.out(sl,1),d.out(sr,-1),_.init(sl);
	memset(last,0,sizeof(last));for(int i=1;i<=n;++i)tl[i]=last[s[i]-97],last[s[i]-97]=i;
	memset(last,63,sizeof(last));for(int i=n;i>=1;--i)tr[i]=last[s[i]-97],last[s[i]-97]=i;
	int q,l,r;read(q);for(B=1;B*B<=n;++B);
	while(q--){
		read(l,r);
		if(!issol(l,r))puts("-1");
		else if(check1(l,r))puts("1");
		else if(check2(l,r))puts("2");
		else if(check3(l,r))puts("3");
		else puts("4");
	}
	return 0;
}