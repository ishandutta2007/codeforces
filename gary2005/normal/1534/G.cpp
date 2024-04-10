/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=8e5+233;
mp a[MAXN];
int n;
priority_queue<LL> dpl;
priority_queue<LL,vector<LL>,greater<LL> > dpr;
LL tagl=0,tagr=0;
LL lval=0;
LL lx=0;
mp calc(int px,int nx){// (+,-)
	if(px&1&&nx&1){
		return II((nx-px)/2,(nx-px)/2);
	}
	if(!(px&1)&&nx&1){
		return II((nx-px)/2,(nx-px+1)/2);
	}
	if(px&1&&!(nx&1)){
		return II((nx-px+1)/2,(nx-px)/2);
	}
	if(!(px&1)&&!(nx&1)){
		return II((nx-px)/2,(nx-px)/2);
	}
	return II(114,514);
}
void trans(int prex,mp now){
	mp mov=calc(prex,now.FIR);
	tagr+=mov.FIR;
	tagl-=mov.SEC;
	lx=tagl;
	now.SEC-=now.SEC&1;
	now.SEC/=2;
	lval+=abs(lx-now.SEC);
	dpl.push(now.SEC-tagl);
	dpr.push(now.SEC-tagr);
	while(true){
		LL x,y;
		x=dpl.top()+tagl;dpl.pop();
		y=dpr.top()+tagr;dpr.pop();
		if(x>y){
			dpl.push(y-tagl);
			dpr.push(x-tagr);
		}
		else{
			dpl.push(x-tagl);
			dpr.push(y-tagr);
			break;
		}
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d%d",&a[i].FIR,&a[i].SEC);
		a[i]=II(a[i].FIR+a[i].SEC,a[i].FIR-a[i].SEC);
	}
	sort(a+1,a+1+n);
	rb(i,1,1000000) dpl.push(0);
	rb(i,1,1000000) dpr.push(0);
	a[0]=II(0,0);
	rb(i,1,n) trans(a[i-1].FIR,a[i]);
	vector<int> L;
	while(!dpl.empty()){
		L.PB(dpl.top()+tagl);
		dpl.pop();
	}
	rl(i,L.size(),1){
		lval+=1ll*(lx-L[i-1])*(i);
		lx=L[i-1];
	}
	printf("%lld\n",lval);
	return 0;
}