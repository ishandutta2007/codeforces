#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200020
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
int n,m,q;
struct QAQ{
	int x,y,type,id;
	bool operator <(const QAQ b)const{
		return x==b.x?type>b.type:x<b.x;
	}
}p[N],g[N];
struct BIT{
	int bit[N];
	inline int lowbit(int x){
		return x&(-x);
	}
	void Clear(){
		memset(bit,0,sizeof(bit));
	}
	void Add(int x,int d){
		while(x<=m){
			bit[x]+=d;
			x+=lowbit(x);
		}
	}
	int Ask(int x){
		int ans=0;
		while(x){
			ans+=bit[x];
			x-=lowbit(x);
		}
		return ans;
	}
}B;
bool check(int k){
	for(int i=1;i<=k;++i){
		g[i]=p[i];
	}
	B.Clear();
	sort(g+1,g+k+1);
	for(int i=1;i<=k;++i){
		if(g[i].type)B.Add(g[i].y,1);
		else if(B.Ask(g[i].y))return true;
	}
	return false;
}
int main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=q;++i){
		int x=read(),y=read();
		p[i].x=(x+1)>>1;
		p[i].y=(y+1)>>1;
		p[i].type=(x&1);
	}
	int l=0,r=q+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(!check(mid)){
			ans=mid,l=mid+1;
		}
		else{
			r=mid;
		}
	}
	for(int i=1;i<=ans;++i){
		printf("YES\n");
	}
	for(int i=ans+1;i<=q;++i){
		printf("NO\n");
	}
	return 0;
}