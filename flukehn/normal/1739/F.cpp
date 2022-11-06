#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2022,M=N*2;
const int H=12;
char s[N],t[H*2];
struct ACAM{
	int ch[M][H];
	int fail[M];
	int val[M];
	const int root=1;
	int cnt;
	void init(){
		cnt=1;
		memset(ch,0,sizeof(ch));
		memset(fail,0,sizeof(fail));
		memset(val,0,sizeof(val));
	}
	void add(char *t,int w){	
		int p=root;
		for(;*t;++t){
			int c=*t-'a';
			if(!ch[p][c]){
				ch[p][c]=++cnt;
			}
			p=ch[p][c];
		}
		val[p]+=w;
	}
	void work(){
		queue<int> q;
		q.push(root);
		fail[1]=1;
		while(!q.empty()){
			int x=q.front();
			q.pop();
			val[x] += val[fail[x]];
			if(x==root){
				for(int i=0;i<H;++i) {
					int &y=ch[x][i];
					if(!y) {
						y=root;
					}else{
						fail[y]=root;
						q.push(y);
					}
				}
			}else{
				for(int i=0;i<H;++i){
					int &y=ch[x][i];
					if(!y) {
						y=ch[fail[x]][i];
					}else{
						fail[y]=ch[fail[x]][i];
						q.push(y);
					}
				}
			}
		}
	}
} ac;
void add(){
	int w;
	cin>>w>>s;
	int e[H][H]={0};
	int m=strlen(s);
	For(i,1,m) {
		int x=s[i]-'a';
		int y=s[i-1]-'a';
		e[x][y]=e[y][x]=1;
	}
	int d[H]={0};
	For(i,0,H)For(j,0,H) d[i]+=e[i][j];
	For(i,0,H)if(d[i]>2) return;
	int p;
	for(p=0;p<H;++p)if(d[p]==1)break;
	if(p>=H) return;
	int q=-1,len=0;
	for(;;){
		t[len++]=p+'a';
		int i;
		for(i=0;i<H;++i)
			if(i!=q&&e[p][i])break;
		if(i>=H) break;
		q=p,p=i;
	}
	
	t[len]=0;
	dbg(t);
	ac.add(t,w);
	reverse(t,t+len);
	ac.add(t,w);
}
int n;
int f[1<<H][M];
int g[1<<H][M];
template<class T>
inline bool upmx(T &x,T y){return x<y?x=y,1:0;}
void solve(){
	ac.init();
	for(int i=0;i<n;++i) {
		add();
	}
	ac.work();
	memset(f,-0x3f,sizeof(f));
	f[0][1]=0;
	for(int i=0;i<(1<<H);++i){
		for(int j=1;j<=ac.cnt;++j) {
			For(k,0,H) if(~i>>k&1) {
				int ni=i|(1<<k);
				int nj=ac.ch[j][k];
				if(upmx(f[ni][nj], f[i][j]+ac.val[nj])) {
					g[ni][nj] = (j << H) + i;
				}
			}
		}
	}
	int ans=-1;
	int q=-1,p=(1<<H)-1;
	for(int i=1;i<=ac.cnt;++i)
		if(upmx(ans, f[p][i])) q =i;
	dbg(ans, p, q);
	string ret;
	for(int i=0;i<H;++i) {
		int w=g[p][q];
		int u=w&((1<<H)-1);
		int v=w>>H;
		int j=__lg(u ^ p);
		ret+=j+'a';
		p=u,q=v;
	}
	reverse(ret.begin(),ret.end());
	cout<<ret<<"\n";
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	while(cin>>n){
		solve();
	}
}