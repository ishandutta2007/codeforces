#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
using namespace std;
struct ask{
	int a,b,c,d;
	int i;
	LL ans;
}query[200005];
int p[200005];
bool cmp1(const ask &a,const ask &b){
	return a.a<b.a;
}
bool cmp2(const ask &a,const ask &b){
	return a.c>b.c;
}
bool cmp3(const ask &a,const ask &b){
	return a.i<b.i;
}
int s[200005];
int n;
void add(int x){
	for(int i=x;i<=n;i+=i&-i)
	s[i]++;
}
int ask(int x){
	int res=0;
	for(int i=x;i>0;i-=i&-i)
	res+=s[i];
	return res;
}
int main(){
	int q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(int i=0;i<q;i++){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		LL ans=(LL)n*(n-1)/2;
		ans-=(LL)(a-1)*(a-2)/2;
		ans-=(LL)(b-1)*(b-2)/2;
		ans-=(LL)(n-c)*(n-c-1)/2;
		ans-=(LL)(n-d)*(n-d-1)/2;
		query[i].a=a;
		query[i].b=b;
		query[i].c=c;
		query[i].d=d;
		query[i].i=i;
		query[i].ans=ans;
	//	printf("%d\n",ans);
	}
	sort(query,query+q,cmp1);
	int now=1;
	MEM(s);
	for(int i=0;i<q;i++){
		while(now<query[i].a){
			add(p[now]);
		//	printf("%d",p[now]);
			now++;
		}
		LL res=ask(query[i].b-1);
		query[i].ans+=res*(res-1)/2;
	//	printf("%lld\n",res);
		res=now-1-ask(query[i].d);
	// 3	printf("%lld\n",res);
		query[i].ans+=res*(res-1)/2;
	}
//	printf("%d",now);
	sort(query,query+q,cmp2);
	now=n;
	MEM(s);
	for(int i=0;i<q;i++){
		while(now>query[i].c){
			add(p[now]);
			now--;
		} 
		LL res=ask(query[i].b-1);
		query[i].ans+=res*(res-1)/2;
		res=n-now-ask(query[i].d);
		query[i].ans+=res*(res-1)/2;
	}
	sort(query,query+q,cmp3);
	for(int i=0;i<q;i++){
		printf("%I64d\n",query[i].ans);
	}
}
/*
2 3
0 1
*/