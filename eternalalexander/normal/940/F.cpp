#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; 
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=2e5+5,block=2100;
const int inf=1e9;
int n,m,qr,T;
int a[N],bel[N],c[N],d[N];
int cnt[N],ans[N];
struct Q{
	int l,r,t,id;
}q[N];
struct M{
	int x,y;
}up[N];
inline bool cmp(const Q & a,const Q & b){
	if(bel[a.l]==bel[b.l]) return bel[a.r]==bel[b.r]?a.t<b.t:bel[a.r]<bel[b.r];
	return a.l<b.l;
}
inline void add(int x){
	d[cnt[x]]--;cnt[x]++;d[cnt[x]]++;
}
inline void del(int x){
	d[cnt[x]]--;cnt[x]--;d[cnt[x]]++;
}
inline void modify(int p,int i){
	int &x=a[up[p].x],&y=up[p].y;
	if(up[p].x>=q[i].l&&up[p].x<=q[i].r){
		del(x);add(y);
	}
	swap(x,y);
}
int main(){
	n=read();qr=read();
	int num=0;
	for(int i=1;i<=n;i++) {
		a[i]=read();bel[i]=(i-1)/block+1;
		c[++num]=a[i]; 
	}
	for(int i=1;i<=qr;i++) {
		int op=read(),x=read(),y=read();
		if(op==1) {
			m++;
			q[m]={x,y,T,m};
		}else up[++T]={x,y},c[++num]=y;
	}
	sort(c+1,c+num+1);num=unique(c+1,c+num+1)-c-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(c+1,c+num+1,a[i])-c;
	for(int i=1;i<=T;i++) up[i].y=lower_bound(c+1,c+num+1,up[i].y)-c;
	sort(q+1,q+m+1,cmp);
	int l=1,r=0,now=0;
    for(int i=1;i<=m;i++){
        for(;r<q[i].r;r++) add(a[r+1]);
        for(;r>q[i].r;r--) del(a[r]);
        for(;l<q[i].l;l++) del(a[l]);
        for(;l>q[i].l;l--) add(a[l-1]);
        for(;now<q[i].t;now++) modify(now+1,i);
        for(;now>q[i].t;now--) modify(now,i);
        for(int j=1;;j++) if(!d[j]) {
			ans[q[i].id]=j;
			break;
		}
    }
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}