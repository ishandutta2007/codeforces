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
const int inf=~0u>>1,mod=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=1e6+11;
char s[N],t[N];
int n;
int q;
inline bool ck(char a,char b){return (s[q]==a&&t[q]==b)||(s[q]==b&&t[q]==a);}
inline bool jud(){
	rep(i,1,n)if(s[i]!=t[i]){
		q=i;
		if(ck('0','o')||ck('1','i')||ck('1','l')||ck('i','l'))continue;
		else return 0;
	}
	return 1;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,n)if(s[i]>='A'&&s[i] <= 'Z')s[i]+=32;
	if(n>50){
		puts("No");
		return 0;
	}
	int m=rd();
	while(m--){
		scanf("%s",t+1);
		int p=strlen(t+1);
		rep(i,1,n)if(t[i]>='A'&&t[i] <= 'Z')t[i]+=32;
		if(p==n&&jud()){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}