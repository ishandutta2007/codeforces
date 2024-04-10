#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=1e5+11;
bitset<N> b[30],o,p;
char s[N],t[N];
int n;
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif 
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>s+1;
	n=strlen(s+1);
	rep(i,1,n)b[s[i]-'a'][i]=1;
	For(i,0,n)o[i]=1;
	int m;
	cin>>m;
	while(m--){
		int op;
		cin>>op;
		if(op==1){
			int x;char c;
			cin>>x>>c;
			b[s[x]-'a'][x]=0;
			b[c-'a'][x]=1;
			s[x]=c;
		}else{
			int l,r;
			cin>>l>>r>>t+1;
			int q=strlen(t+1);
			if(r-l+1<q){
				puts("0");
				continue;
			}
			p=o;
			rep(i,1,q)p&=(b[t[i]-'a']>>i);
			int w=(p>>(l-1)).count()-(p>>(r-q+1)).count();
			printf("%d\n",w);
		}
	}
}