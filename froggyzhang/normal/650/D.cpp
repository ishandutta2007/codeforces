#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 800080
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
int n,m,bn,b[N],a[N],f[N],g[N],mx,tmp,cnt[N];
int bit[N],ans[N];
struct Query{
	int pos,val,id;
	int x,y;
}q[N];
bool cmp(Query a,Query b){
	if(a.pos==b.pos)return a.val<b.val;
	return a.pos<b.pos;
}
inline int lowbit(int x){
	return x&(-x);
}
void Add(int x,int d){
	while(x<=bn){
		bit[x]=max(bit[x],d);
		x+=lowbit(x);	
	} 
}
int Ask(int x){
	int ans=0;
	while(x){
		ans=max(ans,bit[x]);
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		b[++bn]=a[i];
	}
	for(int i=1;i<=m;i++){
		q[i].pos=read(),q[i].val=read();
		q[i].id=i;
		b[++bn]=q[i].val;
	}
	sort(b+1,b+bn+1);
	bn=unique(b+1,b+bn+1)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+bn+1,a[i])-b;
	}
	for(int i=1;i<=m;i++){
		q[i].val=lower_bound(b+1,b+bn+1,q[i].val)-b;
	}
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=n;++i){
		f[i]=Ask(a[i]-1)+1;
		Add(a[i],f[i]);
	}
	memset(bit,0,sizeof(bit));
	for(int i=n;i>=1;--i){
		g[i]=Ask(bn-a[i])+1;
		Add(bn-a[i]+1,g[i]);
	}
	for(int i=1;i<=n;i++){
		mx=max(mx,f[i]+g[i]-1);
	}
	for(int i=1;i<=n;i++){
		if(mx==f[i]+g[i]-1)++cnt[f[i]];
	}
	memset(bit,0,sizeof(bit));
	tmp=1;
	for(int i=1;i<=m;i++){
		while(tmp<q[i].pos){
			Add(a[tmp],f[tmp]);
			++tmp;
		}
		q[i].x=Ask(q[i].val-1);
	}
	memset(bit,0,sizeof(bit));
	tmp=n;
	for(int i=m;i>=1;--i){
		while(tmp>q[i].pos){
			Add(bn-a[tmp]+1,g[tmp]);
			--tmp;
		}
		q[i].y=Ask(bn-q[i].val);
	}
	for(int i=1;i<=m;++i){
		if(q[i].x+q[i].y+1>mx){
			ans[q[i].id]=q[i].x+q[i].y+1;
		}
		else if(q[i].x+q[i].y+1<mx&&f[q[i].pos]+g[q[i].pos]-1==mx&&cnt[f[q[i].pos]]==1){
			ans[q[i].id]=mx-1;
		}
		else{
			ans[q[i].id]=mx;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}