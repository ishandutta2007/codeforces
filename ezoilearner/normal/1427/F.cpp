#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n;
#define cout cerr
#define Maxn 405
#define FR first
#define SE second
bool type[Maxn*3];

int head[Maxn],v[Maxn],nxt[Maxn],tot=0,cnt=0,c[Maxn];
int num[Maxn][3],L[Maxn],ans[Maxn];
inline void add_edge(int s,int e){tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;}

pii stk[Maxn*3];int tp;
deque<int> que[4];
void push(int x){
	int to=c[x]*2;
	if(head[x])to++;
	que[to].push_back(x);
}
void del(int x){
	for(int i=head[x];i;i=nxt[i])push(v[i]);
}
void F(int c,int &t){
	if(que[c*2+1].size()){
		t=que[c*2+1].front();
		del(t);
		que[c*2+1].pop_front();
	}else{
		t=que[c*2].front();
		del(t);
		que[c*2].pop_front();
	}
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	rd(n);
	int p;
	for(int i=1;i<=3*n;++i){
		rd(p);
		type[p]=1;
	}
	for(int i=1;i<=6*n;++i){
		if(tp&&stk[tp].SE==type[i]){
			int t=stk[tp].FR;
			stk[++tp]=pii(t,type[i]);
			num[t][L[t]++]=i;
			if(L[t]==3){
				tp-=3;
				if(tp)add_edge(stk[tp].FR,t);
				else push(t);
			}
		}else{
			stk[++tp]=pii(++cnt,type[i]);
			num[cnt][L[cnt]++]=i;
			c[cnt]=type[i];
		}
	}
	for(int i=1;i<=n;++i){
		F(0,ans[i*2-1]);
		F(1,ans[i*2]);
	}
	for(int i=2*n;i>=1;--i){
		int t=ans[i];
		for(int j=0;j<3;++j)printf("%d ",num[t][j]);
		puts("");
	}
	return 0;
}