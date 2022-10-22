#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define per(i,a,b) for(ll i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

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

int n,m;
#define Maxn 55
char ch[Maxn][Maxn];

int cnt[2];

int id(char c){
	if(c=='R')return 1;
	return 0;
}

void PUT(int x){
	if(x==0)putchar('W');
	else putchar('R');
}

void output(){
	puts("YES");
	rep(i,1,n){
		rep(j,1,m){
			if((i+j)&1)PUT(cnt[1]);
			else PUT(cnt[0]);		
		}
		puts("");
	}
}

int main(){
	int T;rd(T);
	while(T--){
		rd(n);rd(m);
		cnt[0]=cnt[1]=-1;
		bool fl=false;
		rep(i,1,n){
			scanf("%s",ch[i]+1);
			rep(j,1,m)
				if(ch[i][j]!='.'){
					int t=id(ch[i][j]),at=(i+j)&1;
					if(cnt[at]==-1)cnt[at]=t;
					else if(t!=cnt[at])fl=true;
				}
		}
		if(fl){
			puts("NO");
		}else{
			int c0,c1;
			if(cnt[0]==-1&&cnt[1]==-1){
				cnt[0]=0;cnt[1]=1;
				output();
			}else if(cnt[0]==cnt[1]){
				puts("NO");
			}else{
				if(cnt[0]==-1)cnt[0]=cnt[1]^1;
				else if(cnt[1]==-1)cnt[1]=cnt[0]^1;
				output();
			}
		}
	}
	return 0;
}