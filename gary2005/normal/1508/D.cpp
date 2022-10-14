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
typedef pair<double,double> mp;
/*}
*/
const int MAXN=2e3+233;
mp operator + (mp A,mp B){
	return II(A.FIR+B.FIR,A.SEC+B.SEC); 
} 
mp operator - (mp A,mp B){
	return II(A.FIR-B.FIR,A.SEC-B.SEC);
}
mp a[MAXN];
int n,p[MAXN],fa[MAXN],jd;
double ang(mp A){
	A=A-a[jd];
	double tmp=atan2(A.SEC,A.FIR);
	return tmp;
}
bool cmp(int A,int B){
	return ang(a[A])<ang(a[B]);
}
int root(int x){
	return fa[x]=(fa[x]==x? x:root(fa[x]));
}
void merge(int u,int v){
	fa[root(u)]=root(v);
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%lf%lf%d",&a[i].FIR,&a[i].SEC,&p[i]);
	rb(i,1,n) fa[i]=i;
	vector<int> id;
	rb(i,1,n) if(p[i]!=i) id.PB(i);
	if(id.empty()){
		puts("0");
		return 0;
	}
	vector<int> nw;
	jd=id[0];
	for(auto it:id){
		if(a[it].FIR<a[jd].FIR) jd=it;
	}
	for(auto it:id) if(it!=jd) nw.PB(it);
	sort(ALL(nw),cmp);
	rb(i,1,n) merge(i,p[i]);
	vector<pair<int,int> > rest;
	rb(i,1,nw.size()-1){
		int A,B;
		A=nw[i-1];
		B=nw[i];
		if(root(A)!=root(B)){
			merge(A,B);
			swap(p[A],p[B]);
			rest.PB(II(A,B));
		}
	}
	while(p[jd]!=jd){
		rest.PB(II(jd,p[jd]));
		swap(p[jd],p[p[jd]]);
	}
	printf("%d\n",int(rest.size()));
	for(auto it:rest){
		printf("%d %d\n",it.FIR,it.SEC);
	}
	return 0;
}