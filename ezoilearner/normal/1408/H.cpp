#include<bits/stdc++.h>
using namespace std;
int n,m,T,len;
#define Maxn 500010
int a[Maxn],b[Maxn];
vector<int> vec;

int head[Maxn],v[Maxn],nxt[Maxn],tot=0;
void add_edge(int s,int e){tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;}

struct Seg{
	int l,r;
}seg[Maxn];

priority_queue<int,vector<int>,greater<int> > Q;

inline void rd(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}

int main(){
	rd(T);
	while(T--){
		rd(n);m=0;
		for(int i=1;i<=n;++i){
			rd(a[i]);
			if(a[i]==0)m++;
		}
		if(m==0){
			puts("0");
			continue;
		}
		for(int i=1;i<=n;++i)seg[i].l=seg[i].r=0;
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(a[i]==0)cnt++;
			else{
				if(cnt<=m/2)seg[a[i]].l=max(seg[a[i]].l,cnt);
				if(m-cnt<=m/2)seg[a[i]].r=max(seg[a[i]].r,m-cnt);
			}
		}
		for(int i=0;i<=m/2;++i)head[i]=0;tot=0;
		memset(b,0,sizeof(int)*(m/2+1));
		for(int i=1;i<=n;++i)b[seg[i].l]++,add_edge(seg[i].l,seg[i].r);
		int mx=0;
		for(int i=0;i<=m/2;++i){
			if(i)b[i]+=b[i-1];
			mx=max(mx,b[i]-i); 
		}
		int L=n-mx;
		for(int i=m/2;i>L;--i)
			for(int j=head[i];j;j=nxt[j])Q.push(v[j]);
		for(int i=L;i>=1;--i){
			for(int j=head[i];j;j=nxt[j])Q.push(v[j]);
			Q.pop();
		}
		for(int j=head[0];j;j=nxt[j])Q.push(v[j]);
		memset(b,0,sizeof(int)*(m/2+1));
		int ans=Q.size();mx=0;
		while(!Q.empty()){
			int x=Q.top();
			Q.pop();
			b[x]++;
		}
		for(int i=0;i<=m/2;++i){
			if(i)b[i]+=b[i-1];
			mx=max(mx,b[i]-i);
		}
		ans=min(ans-mx+L,m/2);
		printf("%d\n",ans);
	}
	return 0;
}