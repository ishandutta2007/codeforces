#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1200010
typedef long long ll;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int bn,a[N],s[N],n,m,k,l=1,r=0,len;
ll ans=0,Ans[N],cnt[N];
struct Mo{
	int l,r,pos,id;
}q[N];
void del(int x){
	cnt[s[x]]--;
	ans-=cnt[s[x]^k];
}
void add(int x){
	ans+=cnt[s[x]^k];
	cnt[s[x]]++;
}
bool cmp(Mo x,Mo y){
	return (x.pos^y.pos)?x.l<y.l:((x.pos&1)?x.r<y.r:x.r>y.r);
}
int main(){
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		s[i]=s[i-1]^a[i];
	}
	len=sqrt(n);
	for(int i=1;i<=m;i++){
		q[i].l=read()-1;
		q[i].r=read();
		q[i].id=i;
		q[i].pos=q[i].l/len;
	}
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++){
		int ql=q[i].l,qr=q[i].r;
		while(l<ql)del(l++);
		while(l>ql)add(--l);
		while(r<qr)add(++r);
		while(r>qr)del(r--);
		Ans[q[i].id]=ans;
	}
	for(int i=1;i<=m;i++){
		printf("%lld\n",Ans[i]);
	}
	return 0;
}