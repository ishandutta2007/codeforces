/* --- author: dxm --- */
#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

void qread(int &x){
	int neg=1;x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}

const int maxn=1000005;
const int maxm=26;
int n;
char c[maxn];
string s[maxn],t[maxn],pre[maxn];
pii val[maxn];
vector<vector<int> >ans;

namespace Trie{
	int rt,tot;
	int nxt[maxn][maxm];
	vector<int>v[maxn];
	int newnode(){
		tot++;
		rep(i,26)nxt[tot][i]=0;
		v[tot].clear();
		return tot;
	}
	void init(){
		tot=0;
		rt=newnode();
	}
	void insert(string s,int id){
		int cur=rt;
		rep(i,s.size()){
			if(!nxt[cur][s[i]-'a'])nxt[cur][s[i]-'a']=newnode();
			cur=nxt[cur][s[i]-'a'];
		}
		v[cur].pb(id);
	}
	void getans(int cur){
		if(!v[cur].empty())ans.pb(v[cur]);
		rep(i,26)if(nxt[cur][i])getans(nxt[cur][i]);
	}
}

int main(){
#ifdef FILE
	freopen("FILE.in","r",stdin);
	freopen("FILE.out","w",stdout);
#endif
	scanf("%d",&n);
	REP(i,n){
		scanf("%s",c);s[i]=c;
		scanf("%s",c);t[i]=c;
		rep(j,t[i].size())val[i].fst|=(1<<t[i][j]-'a');
		for(int j=s[i].size()-1;j>=0;j--){
			if(!(val[i].fst&(1<<s[i][j]-'a'))){
				pre[i]=s[i].substr(0,j+1);
				break;
			}
		}
//		cout<<pre[i]<<endl;
		val[i].snd=i;
	}
	sort(val+1,val+1+n);
	REP(i,n){
		int j=i;
		Trie::init(); 
		while(j<=n&&val[j].fst==val[i].fst){
			Trie::insert(pre[val[j].snd],val[j].snd);
			j++;
		}
		Trie::getans(1);
		i=j-1;
	}
	printf("%d\n",ans.size());
	rep(i,ans.size()){
		printf("%d ",ans[i].size());
		rep(j,ans[i].size())printf("%d ",ans[i][j]);
		puts("");
	}
#ifdef TIME
	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
#endif
	return 0;
}

/*
Input:
-----------------
Output:
*/