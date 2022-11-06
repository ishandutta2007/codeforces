#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define foe(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,mo=1e9+7;
inline int Rd(){
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=1e5+11;
char s[N];
int n;
int Tes(){
	if(s[1]!='R')return 1;
	if(s[2]>'9')return 1;
	rep(i,3,n)if(s[i]=='C')return i;
	return 1;
}
void Putint(int x){
	if(x<=26){
		putchar(x+'A'-1);
	}else{
		if(x%26){
			Putint(x/26);
			putchar(x%26+'A'-1);
		}else{
			Putint(x/26-1);
			putchar('Z');
		}
	}
}
void Work(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int op=Tes();
	if(op==1){
		int x=0,y=0,i;
		for(i=1;i<=n;++i){
			if(s[i]<='9')break;
			x=x*26+s[i]-'A'+1;
		}
		for(;i<=n;++i){
			y=y*10+s[i]-'0';
		}
		printf("R%dC%d\n",y,x);
	}else{
		int x=0,y=0;
		For(i,2,op){
			x=x*10+s[i]-'0';
		}
		rep(i,op+1,n){
			y=y*10+s[i]-'0';
		}
		Putint(y);
		printf("%d\n",x);
	}
}
int main(){
	//cout<<'@'-'A'<<endl;
	int T=Rd();
	while(T--)Work();
}