#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int p=2000003,M=9*70000+11;
struct myhash{
	int fir[p],h[M],nxt[M],v[M],tot;
	void ins(int x) {
		int z = x % p;
		for(int i=fir[z];i;i=nxt[i]){
			if(v[i]==x){
				h[i]++;
				return;
			} 
		}
		v[++tot]=x,h[tot]=1,nxt[tot]=fir[z];
		fir[z] = tot;
	}
	int query(int x) {
		int z = x % p;
		for(int i=fir[z];i;i=nxt[i]){
			if(v[i]==x) {
				return h[i];
			}
		}
	}
} h[12];
char s[70011][11];
int tt[70011][11];
int rr[11];
inline int calc(int *f,int l,int r){
	return f[r]-f[l-1]*rr[r-l+1];
}
void pr(int l,int x){
	static int dig[15];
	rep(i,1,l){
		dig[i]=x%10;
		x/=10;
	}
	per(i,l,1)putchar(dig[i]+'0');
}
int main() {
	int n=rd();
	rr[0]=1;
	rep(i,1,10)rr[i]=rr[i-1]*10;
	rep(i,1,n){
		set<pii> S;
		scanf("%s",s[i]+1);
		rep(j,1,9) {
			tt[i][j] = tt[i][j-1]*10+s[i][j]-'0';
			//cout<<tt[i][j] << " \n"[j==9];
		}
		rep(j,1,9)rep(k,j,9){
			int now=calc(tt[i],j,k);
			if(!S.count(mp(k-j+1,now)))h[k-j+1].ins(now),S.insert(mp(k-j+1,now));
			
		}
	}
	//cout<<"ok"<<endl;
	rep(i,1,n){
		rep(j,1,9){
			rep(k,1,9-j+1) {
				int now=calc(tt[i],k,k+j-1);
				if(h[j].query(now)<=1) {
					//cout<<"ok "<<j<<" "<<now<<endl;
					pr(j,now);
					putchar('\n');
					goto E;
				}
				//else cout<<"f "<<now<<" "<<h[j].query(now)<<" ";
				//else if(j==3)cout<<now<<endl;
			}
		}
		E:;
	}
}