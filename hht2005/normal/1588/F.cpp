#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define enter pc('\n')
#define space pc(' ')
using ll=long long;
const int MAXL=1<<22;
char i_str[MAXL],o_str[MAXL],*i_s,*i_t;
int o_t;
inline char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
inline int read() {
	int x=0,f=0;
	char ch=gc();
	for(; ch<'0'||ch>'9'; ch=gc())
		if(ch=='-')f=1;
	for(; ch>='0'&&ch<='9'; ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
#define fl fwrite(o_str,1,o_t,stdout),o_t=0
inline void pc(char x) {
	o_str[o_t++]=x;
	if(o_t==MAXL)fl;
}
inline void write(ll x) {
	if(x<0)x=-x,pc('-');
	if(x>9)write(x/10);
	pc(x%10^48);
}
const int N=2e5+10;
#define ub(a,b) upper_bound(pos[a].begin(),pos[a].end(),b)
int in[N],p[N];
int op[N],x[N],y[N],id[N];
ll a[N],sum[N],val[N];
vector<int>pos[N];
int main() {
	int n=read(),q;
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		p[i]=read();
	q=read();
	for(int i=1;i<=q;i++)
		op[i]=read(),x[i]=read(),y[i]=read();
	int B=305;
	for(int T=1;T<=q;T+=B) {
		int l=T,r=min(q,T+B-1);
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+a[i];
		memset(in,0,sizeof(in));
		memset(val,0,sizeof(val));
		for(int i=l;i<=r;i++) {
			if(op[i]!=1)in[x[i]]=x[i];
			if(op[i]==3)in[y[i]]=y[i];
		}
		for(int i=1;i<=n;i++)
			pos[i].clear(),pos[i].shrink_to_fit();
		int top=0;
		for(int i=1;i<=n;i++) {
			if(in[i]==i)id[++top]=i;
			if(in[i])continue;
			int now=p[i],c;
			while(now!=i&&!in[now])now=p[now];
			c=in[now];
			if(now==i)c=-1;
			now=p[i];
			in[i]=c;
			while(now!=i&&!in[now])in[now]=c,now=p[now];
		}
		for(int i=1;i<=n;i++)
			if(in[i]>0)pos[in[i]].push_back(i);
		for(int i=l;i<=r;i++) {
			if(op[i]==1) {
				ll Sum=sum[y[i]]-sum[x[i]-1];
				for(int j=1;j<=top;j++)
					Sum+=val[id[j]]*(ub(id[j],y[i])-ub(id[j],x[i]-1));
				write(Sum),enter;
			} else if(op[i]==2) {
				int now=in[x[i]];
				do {
					val[now]+=y[i];
					now=in[p[now]];
				}while(now!=in[x[i]]);
			} else swap(p[x[i]],p[y[i]]);
		}
		for(int i=1;i<=n;i++)
			if(in[i]>0)a[i]+=val[in[i]];
	}
	fl;
	return 0;
}