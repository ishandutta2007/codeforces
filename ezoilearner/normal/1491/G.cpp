#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

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

int n,q;
#define Maxn 200010
bool vis[Maxn];
int c[Maxn],cnt,len[Maxn];
vector<int> p[Maxn];

pii seq[Maxn];
void Add(int a,int b){
	seq[++q]=pii(a,b);
}

int main(){
	rd(n);
	rep(i,1,n)rd(c[i]);
	rep(i,1,n)
		if(!vis[i]){
			cnt++;
			int t=i;
			while(!vis[t]){
				p[cnt].push_back(t);
				vis[t]=true;
				t=c[t];
			}
		}
	for(int i=2;i<=cnt;i+=2){
		Add(p[i-1][0],p[i][0]);
		for(int j=1;j<p[i-1].size();++j)Add(p[i][0],p[i-1][j]);
		for(int j=1;j<p[i].size();++j)Add(p[i-1][0],p[i][j]);
		Add(p[i-1][0],p[i][0]);
	}
	if(cnt&1){
		if(cnt>1){
			int t=p[1][0];
			Add(p[cnt][0],t);
			for(int i=0;i<p[cnt].size();++i)Add(p[cnt][(i+1)%p[cnt].size()],t);
		}else if(p[cnt].size()>1){
			Add(p[cnt][0],p[cnt][2]);
			Add(p[cnt][0],p[cnt][1]);
			Add(p[cnt][2],p[cnt][1]);
			for(int i=3;i<p[cnt].size();++i)Add(p[cnt][2],p[cnt][i]);
			Add(p[cnt][2],p[cnt][0]);
		}
	}
	printf("%d\n",q);
	rep(i,1,q)printf("%d %d\n",seq[i].FR,seq[i].SE);
	return 0;
}