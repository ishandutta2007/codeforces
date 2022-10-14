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
#define rb(a,b,c) for(register int a=b;a<=c;++a)
#define rl(a,b,c) for(register int a=b;a>=c;--a)
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=500000+1;
multiset<pair<int,int> > food;
set<mp> tortoise;
int x[MAXN];
int rest1[MAXN];
LL rest2[MAXN];
void process(mp& A,multiset<mp>::IT ite,set<mp>:: IT it){
//	auto ite=food.lower_bound(II(A.FIR.FIR,-INF));// 
//	auto it=tortoise.lower_bound(II(II(A.FIR.FIR,-INF),-INF));// 
	while(ite!=food.end()&&(*ite).FIR<=A.FIR){
		++rest1[A.SEC];
		rest2[A.SEC]+=(*ite).SEC;
		A.FIR+=(*ite).SEC;
		A.FIR=min(A.FIR,1000000000);
		food.erase(ite++);	
	} 
	while(it!=tortoise.end()&&(*it).FIR<=A.FIR){
		tortoise.erase(it++);
	}
}	
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
int main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	int n,m;
	n=read();
	m=read();
	vector<pair<mp,int> > tort;
	rb(i,1,n){
		int xi,ti;
		xi=x[i]=read();
		ti=read();
		rest2[i]+=ti;
		tort.PB(II(II(xi,min(1000000000,xi+ti)),i));
	}
	sort(ALL(tort));
	int L=-INF;
	rb(i,1,n){
		check_max(L,tort[i-1].FIR.FIR);
		if(L<=tort[i-1].FIR.SEC){
			tortoise.insert(II(tort[i-1].FIR.SEC,tort[i-1].SEC));
		}
		check_max(L,tort[i-1].FIR.SEC+1);
	}
	rb(i,1,m){
		int xi,ti;
		xi=read();
		ti=read(); 
		food.insert(II(xi,ti)); 
		auto ite=tortoise.lower_bound(II(xi,-INF));
		if(ite==tortoise.end()) continue;
		mp A=*ite;
		if(x[A.SEC]<=xi){
			tortoise.erase(ite++);
			process(A,food.find(II(xi,ti)),ite);
			tortoise.insert(A);
		}
	}
	rb(i,1,n) {
		write(rest1[i]);putchar(' ');
		write(rest2[i]);puts("");
	}
	return 0;
}