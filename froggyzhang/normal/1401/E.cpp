#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 1000100
const int mx=1000000;
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
int n,m;
ll ans;
struct BIT{
	int bit[N];
	inline int lowbit(int x){
		return x&(-x);
	}
	void Add(int x,int d){
		while(x<=mx){
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
int an,bn;
struct Line{
	int pos,x;
	bool operator <(const Line b)const{
		return pos<b.pos;
	}
}a[N],b[N],p[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		int x=read(),l=read(),r=read();
		if(!l){
			++an;
			a[an].x=x,a[an].pos=r;
			if(r==mx)++ans;
		}
		else{
			++bn;
			b[bn].x=x,b[bn].pos=l;
		}
	}
	sort(a+1,a+an+1);
	sort(b+1,b+bn+1); 
	for(int i=1;i<=m;++i){
		p[i].pos=read();
		int l=read(),r=read();
		if(!l){
			p[i].x=r;
			if(r==mx)++ans;
		}
		else{
			p[i].x=-l;
		}
	}
	sort(p+1,p+m+1);
	int nowa=1,nowb=1;
	for(int i=1;i<=an;++i){
		B.Add(a[i].x,1);
	} 
	for(int i=1;i<=m;++i){
		while(nowa<=an&&a[nowa].pos<p[i].pos){
			B.Add(a[nowa].x,-1);
			++nowa;
		}
		while(nowb<=bn&&b[nowb].pos<=p[i].pos){
			B.Add(b[nowb].x,1);
			++nowb; 
		}
		if(p[i].x>0){
			ans+=B.Ask(p[i].x);
		}
		else{
			ans+=B.Ask(mx)-B.Ask(-p[i].x-1);
		}
	}
	printf("%I64d\n",ans+1);
	return 0;
}