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
struct plane{
	int d,f,c;
	plane(int a,int b,int e):d(a),f(b),c(e){
	}
	plane(){
	}
};
bool operator<(const plane &a,const plane &b){
	return a.d<b.d;
}
map<LL,int> in[100005];
map<LL,int> out[100005];
plane inp[100005],outp[100005];
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int inind=0,outind=0;
	for(int i=0;i<m;i++){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(c==0){
			inp[inind++]=plane(a,b,d);
		}
		else if(b==0){
			outp[outind++]=plane(a,c,d);
		}
	}
	sort(inp,inp+inind);
	sort(outp,outp+outind);
	LL ans=1e12;
	LL now=0;
	for(int i=1;i<=n;i++){
		in[i][1e12]++;
		out[i][1e12]++;
		now+=1e12;
	} 
	for(int i=0;i<outind;i++){
		out[outp[i].f][outp[i].c]++;
	}
	for(int i=1;i<=n;i++){
		now+=out[i].begin()->x;
	}
	int nowind=0;
	for(int i=0;i<inind;i++){
		while(nowind<outind){
			if(outp[nowind].d>inp[i].d+k)
			break;
			now-=out[outp[nowind].f].begin()->x;
			if(--out[outp[nowind].f][outp[nowind].c]==0){
				out[outp[nowind].f].erase(outp[nowind].c);
			}
			now+=out[outp[nowind].f].begin()->x;
			nowind++;
		}
		now-=in[inp[i].f].begin()->x;
		in[inp[i].f][inp[i].c]++;
		now+=in[inp[i].f].begin()->x;
		ans=min(ans,now);
	}
	if(ans==1e12)
	ans=-1;
	printf("%lld\n",ans);
}