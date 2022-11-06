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
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=200011;
char s[N];
set<int> a,b;
vector<int> v[N];
int tot;
void no(){puts("-1");exit(0);}
int main(){
#ifdef flukehn
	freopen(".in","r",stdin);
#endif
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,1,n)if(s[i]=='0')a.insert(i);else b.insert(i);
	while(a.size()){
		if(!b.size()){
			foe(i,a){
				++tot;
				v[tot].pb(*i);
			}
			break;
		}
		++tot;
		int x=*a.begin();
		a.erase(a.begin());
		//cerr<<x<<endl;
		v[tot].pb(x);
		while(b.size()){
			set<int>::iterator it=b.lower_bound(x);
			if(it==b.end())break;
			int y=*it;
			v[tot].pb(y);
			b.erase(it);
			it=a.lower_bound(y);
			if(it==a.end())no();
			x=*it;
			a.erase(*it);
			v[tot].pb(x);
		}
	}
	if(b.size())no();
	printf("%d\n",tot);
	rep(i,1,tot){
		int x=v[i].size();
		printf("%d ",x);
		For(j,0,x)printf("%d%c",v[i][j]," \n"[j==x-1]);
	}
}