/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize(2)
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
#define R(a) a=read()
#define R2(a,b) a=read(),b=read()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
#define vector deque
/*}
*/
inline int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
inline void write(LL x)
{
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int MAXN=1000+2;
vector<unsigned int> g[MAXN];
int a[MAXN];
int n,k;
void merge(vector<LL>& A,vector<LL>& B){//merge A,B to A
	if(B.size()>A.size()) swap(A,B);
	vector<LL> ret=A;
	rep(i,B.size()){
		int ano=k-2-i;
		check_max(ano,i);
		check_max(ret[i],B[i]);
		if(ano<A.size()) 
		check_max(ret[i],A[ano]+B[i]);
		if(ano<B.size())
		check_max(ret[i],A[i]+B[ano]);
	}
	rl(i,B.size(),2)
		check_max(ret[i-2],ret[i-1]);
	B.clear();
	A=ret;
}
void calc(vector<LL>&rest,int now,int pre=0){
	vector<LL> tmp;
	for(auto it:g[now]){
		if(it!=pre){
			calc(tmp,it,now);
			merge(rest,tmp);
		}
	}
	while(rest.size()>=k+1){
		rest.POB();
	}
	if(rest.size()==k){
		rest.push_front(rest.back()+a[now]);
		if(rest.size()!=1)
		check_max(rest[0],rest[1]);
	}
	else{
		rest.push_front(a[now]);
		if(rest.size()!=1)
		check_max(rest[0],rest[1]);
	}
//	cout<<a[now]<<now<<endl;
//	rb(i,0,rest.size()-1){
//		cout<<i<<' '<<rest[i]<<endl;
//	} 
//	cout<<"--------------------\n";
}
int main(){
	fastio;
	n=read();
	k=read();
	k++;
	rb(i,1,n)
		a[i]=read();
	rb(i,2,n){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	vector<LL> rest;
	calc(rest,1);
	cout<<rest[0]<<endl;
	return 0;
}
/** 
  *
  *
  *
  *
  **/