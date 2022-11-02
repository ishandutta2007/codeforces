#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > pii;
typedef long long LL;
#define mpr make_pair
#define FS first
#define SC second
#define PB push_back
template < typename T > T MAX(T a,T b){return (a>b)?a:b;}
template < typename T > T MIN(T a,T b){return (a<b)?a:b;}
template < typename T > void UMAX(T &a,T b){a=(a>b?a:b);}
template < typename T > void UMIN(T &a,T b){a=(a<b?a:b);}
int readint(){
	char c=getchar();
	int ret=0;
	while(!(c>='0' && c<='9')) c=getchar();
	while(c>='0' && c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}
void putint(int v){
	if(!v){
		putchar('0');
		return;
	}
	if(v>=10) putint(v/10);
	putchar('0'+(v%10));
}
struct ms{
	LL a,b,t;
	void read(){
		scanf("%I64d%I64d%I64d",&a,&b,&t);
	}
	inline LL at(){return a+t;}
	inline LL bt(){return b-t;}
}es[200005];
int n,pat[200005],pbt[200005],pt[200005];
int rpat[200005],rpbt[200005],rpt[200005];
bool cmpa(ms A,ms B){
	return A.a<B.a;
}
bool cmpat(int A,int B){
	return es[A].at()<es[B].at();
}
bool cmpbt(int A,int B){
	return es[A].bt()<es[B].bt();
}
bool cmpt(int A,int B){
	return es[A].t<es[B].t;
}
set < int > avai_t,avai_bt,fu_o,fu_at;
LL res,x;
void movetoavai(int d){
	fu_o.erase(fu_o.find(d));
	fu_at.erase(fu_at.find(rpat[d]));
	avai_t.insert(rpt[d]);
	avai_bt.insert(rpbt[d]);
}
void delfromavai(int d){
	avai_t.erase(avai_t.find(rpt[d]));
	avai_bt.erase(avai_bt.find(rpbt[d]));
}
void updatex(){
	while(!fu_o.empty()){
		int d=*(fu_o.begin());
		if(es[d].a<=x)
			movetoavai(d);
		else break;
	}
	while(!avai_bt.empty()){
		int d=pbt[*(avai_bt.begin())];
		if(es[d].bt()<x)
			delfromavai(d);
		else break;
	}
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		es[i].read();
		pat[i]=pbt[i]=pt[i]=i;
	}
	sort(es,es+n,cmpa);
	sort(pat,pat+n,cmpat);
	sort(pbt,pbt+n,cmpbt);
	sort(pt,pt+n,cmpt);
	for(i=0;i<n;++i){
		rpat[pat[i]]=i;
		rpbt[pbt[i]]=i;
		rpt[pt[i]]=i;
		fu_o.insert(i);
		fu_at.insert(i);
	}
	while(!avai_bt.empty() || !fu_at.empty()){
//		printf("x=%lld\n",x);
		int cddfat=-1,cddvt=-1;
		if(!avai_t.empty()) cddvt=pt[*(avai_t.begin())];
		if(!fu_at.empty()) cddfat=pat[*(fu_at.begin())];
//		printf("f %d  v %d\n",cddfat,cddvt);
		if(cddfat==-1){
			LL A=es[cddvt].a,B=es[cddvt].b,T=es[cddvt].t;
			LL til=(B-x)/T;
			res+=til;
			x+=til*T;
//			printf("f1 til=%lld\n",til);
		}
		else if(cddvt==-1){
			++res;
			x=es[cddfat].at();
//			printf("f2\n");
		}
		else if(x+es[cddvt].t<es[cddfat].at()){
			LL A=es[cddvt].a,B=es[cddvt].b,T=es[cddvt].t;
			LL til=MIN((B-x)/T,(es[cddfat].at()-x)/T);
			res+=til;
			x+=til*T;
//			printf("f3 til=%lld\n",til);
		}
		else{
			++res;
			x=es[cddfat].at();
//			printf("f4\n");
		}
		updatex();
	}
	printf("%I64d\n",res);
	return 0;
}
/*
 * 
 * 1. mastera+tb-ttp1,p2,p3rp1,rp2,rp3
 * 		ida
 * 2. setmaster
 * 		p2p3
 * 		p1
 * 3. p1 x+p3x
 * 		x
 * 4. master
 * 5. x
*/