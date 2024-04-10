#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int n,l,m;
struct arr {int s[555];}a,b,c;
ll tmp[1055];
const ll MOD=1e9+7;
arr operator * (arr a,arr b)
{
	for(int i=0;i<m+m;++i) tmp[i]=0;
	for(int i=0;i<m;++i)
		for(int j=0;j<m;++j)
			tmp[i+j]+=a.s[i]*ll(b.s[j])%MOD;
	arr p;
	for(int i=0;i<m;++i)
		p.s[i]=(tmp[i]+tmp[i+m])%MOD;
	return p;
}
arr ans;
int bt[1000999];
int main()
{
	scanf("%d%d%d",&n,&l,&m);
	for(int i=1;i<=n;++i)
	{
		int x; scanf("%d",&x);
		x%=m; ++a.s[x];
	}
	for(int i=1;i<=n;++i)
	{
		int x; scanf("%d",&x);
		x%=m; bt[i]=x; ++b.s[x];
	}
	for(int i=1;i<=n;++i)
	{
		int x; scanf("%d",&x);
		x%=m; bt[i]+=x; ++c.s[bt[i]%m];
	}
	ans.s[0]=1; l-=2;
	while(l)
	{
		if(l&1) ans=ans*b;
		b=b*b; l>>=1;
	}
	ans=ans*a*c;
	ll op=ans.s[0];
	op=(op%MOD+MOD)%MOD;
	printf("%d\n",int(op));
}