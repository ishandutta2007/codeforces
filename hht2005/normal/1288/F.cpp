#include<bits/stdc++.h>
using namespace std;
const int maxn=1010,maxm=500010,inf=0x3f3f3f3f;
int hea[maxn],nxt[maxm],to[maxm],dis[maxn],pre[maxn],f[maxn],q[maxn*200],h,e,S,T,tot;
long long sumw,sumc,sum,w[maxm],c[maxm],flow[maxn];
inline int read() {
	int x=0,f=0;
	char ch=getchar();
	for(; ch<'0'||ch>'9'; ch=getchar())
		if(ch=='-')f=1;
	for(; ch>='0'&&ch<='9'; ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
inline void ins(int a,int b,int ww,int cc) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=ww;
	c[tot]=cc;
}
inline void add(int a,int b,int ww,int cc) {
//	cerr<<a<<' '<<b<<' '<<cc<<endl;;
	ins(a,b,ww,cc);
	ins(b,a,0,-cc);
}
void EK() {
	while(1) {
		memset(dis,inf,sizeof(dis));
		dis[S]=0;
		q[h=e=1]=S;
		while(h<=e) {
			int x=q[h++];
			f[x]=0;
			for(int i=hea[x]; i; i=nxt[i]) {
				if(w[i]&&dis[to[i]]>dis[x]+c[i]) {
					dis[to[i]]=dis[x]+c[i];
					pre[to[i]]=i;
					if(!f[to[i]]) {
						f[to[i]]=1;
						q[++e]=to[i];
					}
				}
			}
		}
		if(dis[T]>=inf)break;
		long long mi=inf;
		for(int i=T;i!=S;i=to[pre[i]^1])mi=min(w[pre[i]],mi);
		for(int i=T;i!=S;i=to[pre[i]^1])w[pre[i]]-=mi,w[pre[i]^1]+=mi,sumc+=mi*c[pre[i]];
		sumw+=mi;
	}
}
inline void add(int a,int b,int L,int R,int cc) {
//	cerr<<a<<' '<<b<<' '<<L<<','<<R<<','<<cc<<endl;
	sumc+=cc*L;
	add(a,b,R-L,cc);
	flow[a]-=L;
	flow[b]+=L;
}
void work() {
	add(T,S,0,inf,0);
	for(int i=1;i<=T;i++) {
		if(flow[i]<0)add(i,T+2,-flow[i],0);
		if(flow[i]>0)add(T+1,i,flow[i],0),sum+=flow[i];
	}
//	for(int i=1;i<=T;i++)
//		cerr<<flow[i]<<endl;
	S+=2,T+=2;
	EK();
//	cerr<<sumc<<endl;
}
char s1[maxn],s2[maxn];
int main() {
	tot=1;
	int n1=read(),n2=read(),m=read(),R=read(),B=read(),a,b;
	S=n1+n2+1,T=S+1;
	scanf("%s%s",s1+1,s2+1);
	for(int i=1;i<=n1;i++) {
		if(s1[i]=='R')add(S,i,1,inf,0);
		if(s1[i]=='B')add(i,T,1,inf,0);
		if(s1[i]=='U') {
			add(S,i,0,inf,0);
			add(i,T,0,inf,0);
		}
	}
	for(int i=1;i<=n2;i++) {
		if(s2[i]=='B')add(S,i+n1,1,inf,0);
		if(s2[i]=='R')add(i+n1,T,1,inf,0);
		if(s2[i]=='U') {
			add(S,i+n1,0,inf,0);
			add(i+n1,T,0,inf,0);
		}
	}
	int H=tot+1;
	for(int i=1;i<=m;i++) {
		int a=read(),b=read();
		add(a,b+n1,0,1,R);
		add(b+n1,a,0,1,B);
	}
	int E=tot;
	work();
	if(sumw!=sum)return puts("-1"),0;
	printf("%lld\n",sumc);
	for(int i=H;i<=E;i+=4) {
		if(!w[i])putchar('R');
		else if(!w[i+2])putchar('B');
		else putchar('U');
	}
	puts("");
	return 0;
}