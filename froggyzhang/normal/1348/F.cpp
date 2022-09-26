#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 200100
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
int n,ans[N],pos[N],L[N],R[N],s1,s2;
struct OP{
	int l,r,id;
	bool operator <(const OP b)const{
		return r<b.r;
	}
}a[N];
struct Ele{
	int pos,id;
	bool operator <(const Ele b)const{
		return pos<b.pos;
	}
};
priority_queue<Ele> q;
int bit[N];
inline int lowbit(int x){
	return x&(-x);
}
void Add(int x,int d){
	while(x<=n){
		bit[x]=min(bit[x],d);
		x+=lowbit(x);
	}
}
int Ask(int x){
	int ans=inf;
	while(x){
		ans=min(ans,bit[x]);
		x-=lowbit(x); 
	}
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i].l=read(),a[i].r=read();
		a[i].id=i;
		L[i]=a[i].l,R[i]=a[i].r;
	}
	sort(a+1,a+n+1);
	int now=n;
	for(int i=n;i>=1;--i){
		while(now&&a[now].r==i){
			q.push({a[now].l,a[now].id});
			--now;
		}
		int u=q.top().id;
		q.pop();
		ans[u]=i;
		pos[i]=u;
	}
	memset(bit,0x3f,sizeof(bit));
	for(int i=n;i>=1;--i){
		int tmp=Ask(i);
		if(R[pos[i]]>=tmp){
			s1=i,s2=tmp;
			break;
		}
		Add(L[pos[i]],i);
	}
	printf(s1?"NO\n":"YES\n");
	for(int i=1;i<=n;++i){
		printf("%d ",ans[i]);
	}
	printf("\n");
	if(s1){
		for(int i=1;i<=n;++i){
			if(ans[i]==s1)printf("%d ",s2);
			else if(ans[i]==s2)printf("%d ",s1);
			else printf("%d ",ans[i]);
		} 
		printf("\n");
	}
	return 0;
}