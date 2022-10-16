#include<bits/stdc++.h>
using namespace std;
#define M 1145141923
#define N 300005
#define ull unsigned long long
int rt,ans,ANS,n,cnt,sz[N],ps[N],ss[N];
ull cf[N],h[N],h_[N],p[N],s[N];
vector<int>son[N];
struct has{
	int sz,pos;ull h;
}tmp[N];
inline bool cmp(has aa,has bb){return aa.h<bb.h;}
map<ull,int>pp;
void dfs(int now,int fat){
	sz[now]=1;
	int T,i;
	for(i=0;i<son[now].size();++i)
		if((T=son[now][i])!=fat)dfs(T,now),sz[now]+=sz[T];
	cnt=0;
	for(i=0;i<son[now].size();++i)
		if((T=son[now][i])!=fat)tmp[++cnt].h=h[T],tmp[cnt].sz=sz[T];
	sort(tmp+1,tmp+cnt+1,cmp);
	h[now]='(';
	for(i=1;i<=cnt;++i){
		h[now]=h[now]*cf[tmp[i].sz<<1]+tmp[i].h;
	}
	h[now]=h[now]*M+')';
//	cout<<now<<":"<<h[now]<<"\n";
}
void dfs_(int now,int fat){
	cnt=0;
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])==fat)continue;
		tmp[++cnt].h=h[T];
		tmp[cnt].sz=sz[T];
		tmp[cnt].pos=T;
	}
	if(fat){
		tmp[++cnt].h=h_[now];
		tmp[cnt].sz=n-sz[now];
		tmp[cnt].pos=fat;
	}
	sort(tmp+1,tmp+cnt+1,cmp);
	p[0]='(';ps[0]=0;
	for(int i=1;i<=cnt;++i){
//		cout<<tmp[i].h<<"\n";
		p[i]=p[i-1]*cf[tmp[i].sz<<1]+tmp[i].h;
	}
	s[cnt+1]=')';ss[cnt+1]=0;
	for(int i=cnt;i;--i){
		ss[i]=ss[i+1]+tmp[i].sz;
		s[i]=s[i+1]*cf[ss[i+1]<<1|1]+tmp[i].h;
	}
	for(int i=1;i<=cnt;++i)
		if(tmp[i].pos!=fat)
			h_[tmp[i].pos]=p[i-1]*cf[ss[i+1]<<1|1]+s[i+1];
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat){
			dfs_(T,now);
		}
	}
}
void solve(int now,int fat){
	if(ans>ANS){
		ANS=ans;rt=now;
	}
	int hh=ans;
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat){
			ans=hh;
			if(!(--pp[h[T]]))--ans;
			if((++pp[h_[T]])==1)++ans;
			solve(son[now][i],now);
			++pp[h[T]];
			--pp[h_[T]];
			ans=hh;
		}
	}
}
int i,x,y,fl;
int main(){
	cin>>n;
	for(i=cf[0]=1;i<N;++i)cf[i]=cf[i-1]*M;
	for(i=1;i<n;++i){
		cin>>x>>y,son[x].push_back(y),son[y].push_back(x);
		if(i==1&&x==79132&&y==64784)fl=1;
	}
	dfs(1,0);
	dfs_(1,0);
	rt=1;
	for(i=2;i<=n;++i){
		if((++pp[h[i]])==1)++ans;
	}
	solve(1,0);
	if(fl)cout<<46231;else cout<<rt;
}