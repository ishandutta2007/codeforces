#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0;
	char ch=getchar();
	for(; ch<'0'||ch>'9'; ch=getchar());
	for(; ch>='0'&&ch<='9'; ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
const int maxn=1e5+10;
int a[maxn],t[maxn],d[maxn],ans[maxn],v[1000],siz;
int dui[maxn],c[maxn],m,top,n,K;
inline void push(int x) {
	dui[++top]=x;
	int t=top;
	while(t!=1&&dui[t>>1]>dui[t])
		swap(dui[t>>1],dui[t]),t>>=1;
}
inline void pop() {
	dui[1]=dui[top--];
	int t=1;
	while((t<<1<=top&&dui[t]>dui[t<<1])||(t<<1<top&&dui[t]>dui[t<<1|1])) {
		if(t<<1>=top||dui[t<<1]<dui[t<<1|1])
			swap(dui[t],dui[t<<1]),t<<=1;
		else
			swap(dui[t],dui[t<<1|1]),t=t<<1|1;
	}
}
struct node {
	int l,r,id;
	inline int operator <(const node &a)const {
		int b1=(l-1)/K+1,b2=(a.l-1)/K+1;
		if(b1!=b2)return b1<b2;
		return b1&1?r<a.r:r>a.r;
	}
} q[maxn];
inline void change(int x,int f) {
	if(c[a[x]]<=K)d[c[a[x]]]--;
	c[a[x]]+=f;
	if(c[a[x]]<=K)d[c[a[x]]]++;
}
int main() {
	n=read();
	for(int i=1; i<=n; i++)
		a[i]=c[i]=read();
	sort(c+1,c+1+n);
	m=unique(c+1,c+1+n)-c-1;
	K=sqrt(n);
	for(int i=1; i<=n; i++) {
		a[i]=lower_bound(c+1,c+m+1,a[i])-c;
		t[a[i]]++;
	}
	for(int i=1; i<=m; i++)
		if(t[i]>K)
			v[++siz]=i;
	int Q=read();
	for(int i=1; i<=Q; i++)
		q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+1+Q);
	int l=1,r=0;
	memset(c,0,sizeof(c));
	for(int i=1; i<=Q; i++) {
		while(l<q[i].l)change(l++,-1);
		while(l>q[i].l)change(--l,1);
		while(r<q[i].r)change(++r,1);
		while(r>q[i].r)change(r--,-1);
		for(int j=1; j<=K; j++)
			t[j]=d[j];
		top=0;
		for(int j=1; j<=siz; j++)
			if(c[v[j]]>K)
				push(c[v[j]]);
		int sum=0,las=0;
		for(int j=1; j<=K; j++)
			if(t[j]) {
				if(las) {
					t[j]--;
					sum+=las+j;
					if(las+j>K)push(las+j);
					else t[las+j]++;
				}
				sum+=t[j]/2*(j+j);
				if(j<<1>K)
					for(int k=1;k<=t[j]/2;k++)
						push(j+j);
				else t[j+j]+=t[j]/2;
				t[j]&=1;
				if(t[j])las=j;
				else las=0;
			}
		if(las)push(las);
		while(top>1)
		{
			int d1=dui[1];
			pop();
			int d2=dui[1];
			pop();
			sum+=d1+d2;
			push(d1+d2);
		}
		ans[q[i].id]=sum;
	}
	for(int i=1;i<=Q;i++)
		printf("%d\n",ans[i]);
	return 0;
}