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
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)/*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=1e6;
set<pii> S;
int a[N+44];
int main(){
	int now=0;
	int n=rd(),A=rd();
	rep(i,1,N)if(i!=A)S.insert(mp(0,i));
	set<pii>::iterator si;
	rep(i,1,n){
		int x=rd();
		if(x==A){
			now++;
			while((si=S.begin())!=S.end()){
				if(si->x>=now)break;
				else a[si->y]=-1,S.erase(si);
			}
			if(si==S.end()){
				puts("-1");
				return 0;
			}
			//cout<<S.size()<<" f"<<endl;
		}
		else if(~a[x]){
			S.erase(mp(a[x],x));
			++a[x];
			S.insert(mp(a[x],x));
		}
	}
	//cout<<S.size()<<endl;
	printf("%d\n",S.begin()->y);
}