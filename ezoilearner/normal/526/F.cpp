#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
#define Maxn 300010
int p[Maxn];

namespace Seg{
	int L[Maxn],stk1[Maxn],stk2[Maxn],top1,top2;
	int mnpos[Maxn<<2],tag[Maxn<<2],mn[Maxn<<2];
	void maketag(int k,int ad){
		tag[k]+=ad;mn[k]+=ad;
		return;
	}
	void Build_Tree(int k,int l,int r){
		mn[k]=0;tag[k]=0;mnpos[k]=l;
		if(l==r)return;
		int mid=(l+r)>>1;
		Build_Tree(k<<1,l,mid);
		Build_Tree(k<<1|1,mid+1,r);
	}
	void push_up(int k){
		mn[k]=min(mn[k<<1],mn[k<<1|1])+tag[k];
		if(mn[k<<1]+tag[k]==mn[k])mnpos[k]=mnpos[k<<1];
		else mnpos[k]=mnpos[k<<1|1];
	}
	void Add(int k,int l,int r,int L,int R,int ad){
		if(l==L&&r==R){
			maketag(k,ad);
			return;
		}
		int mid=(l+r)>>1;
		if(R<=mid)Add(k<<1,l,mid,L,R,ad);
		else if(mid<L)Add(k<<1|1,mid+1,r,L,R,ad);
		else{
			Add(k<<1,l,mid,L,mid,ad);
			Add(k<<1|1,mid+1,r,mid+1,R,ad);
		}
		push_up(k);
	}
	void Build_L(){
		Build_Tree(1,1,n);
		for(int i=1;i<=n;++i){
			if(i>1)Add(1,1,n,1,i-1,-1);
			while(top1&&p[stk1[top1]]<p[i]){
				Add(1,1,n,stk1[top1-1]+1,stk1[top1],p[i]-p[stk1[top1]]);
				top1--;
			}
			stk1[++top1]=i;
			while(top2&&p[stk2[top2]]>p[i]){
				Add(1,1,n,stk2[top2-1]+1,stk2[top2],p[stk2[top2]]-p[i]);
				top2--;
			}
			stk2[++top2]=i;
			L[i]=mnpos[1];
		}		
	}
}

struct Data{
	int l,r,mn,mx;
	bool type;//:false :true
	Data(){l=r=mn=mx=0;type=false;}
	Data(int _l,int _r,int _mn,int _mx,bool _type){l=_l;r=_r;mn=_mn;mx=_mx;type=_type;}
	bool Judge(){
		if(mx-mn==r-l)return true;
		return false;
	} 
}A[Maxn<<1];ll Ans=0;
int stk[Maxn],top=0;
int cnt=0;
int head[Maxn<<1],v[Maxn<<1],nxt[Maxn<<1],tot=0;
int sgn(int x){return x<0?-1:1;}
bool Judge(Data t1,Data t2){
	Data t;
	t.l=t1.l;t.r=t2.r;t.mn=min(t1.mn,t2.mn);t.mx=max(t1.mx,t2.mx);
	return t.Judge();
}
Data merge(Data t1,Data t2){
	if(t1.l>t2.l)swap(t1,t2);
	Data t;
	t.l=t1.l;t.r=t2.r;t.mn=min(t1.mn,t2.mn);t.mx=max(t1.mx,t2.mx);
	return t;
}
inline void add_edge(int s,int e){tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;}
void dfs(int u){
	int siz=0;
	for(int i=head[u];i;i=nxt[i]){
		dfs(v[i]);
		siz++;
	}
	if(A[u].type)Ans++;
	else{
		if(siz==0)Ans++;
		Ans+=1ll*siz*(siz-1)/2;
	}
}

inline void rd(int &x){
	x=0;char ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}

int main(){
	rd(n);
	int r,c;
	for(int i=1;i<=n;++i){
		rd(r);rd(c);
		p[r]=c;
	}
	Seg::Build_L();
	for(int i=1;i<=n;++i){//tmp tmpid add_edge()
		A[++cnt]=Data(i,i,p[i],p[i],false);
		Data tmp=A[cnt];int tmpid=cnt;
		while(tmp.l!=Seg::L[i]){
			int t=stk[top];
			if(A[t].r>A[t].l&&A[t].type==false&&Judge(A[t],tmp)&&sgn(p[A[t].l]-p[A[t].r])==sgn(p[A[t].r]-p[i])){
				A[t]=merge(A[t],tmp);A[t].type=false;
				add_edge(t,tmpid);tmpid=t;top--;tmp=A[t]; 
				continue;
			}
			cnt++;A[cnt]=merge(A[stk[top]],tmp);add_edge(cnt,stk[top]);add_edge(cnt,tmpid);
			top--;A[cnt].type=false;
			while(!A[cnt].Judge()){
				A[cnt]=merge(A[stk[top]],A[cnt]);add_edge(cnt,stk[top]);top--;
				A[cnt].type=true;
			}
			tmpid=cnt;tmp=A[cnt];
		}
		stk[++top]=tmpid;
	}
	dfs(stk[top]);
	printf("%lld\n",Ans);
	return 0;
}