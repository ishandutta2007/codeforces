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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
map<int,vector<mp> > row;
map<int,vector<mp> > column;
multiset<pair<int,pair<int,bool > > > queries;
vector<mp> upd(vector<mp> old){
	vector<mp> ret;
	sort(ALL(old));
	int l,r;
	l=r=-INF;
	for(auto it:old){
		if(it.FIR>r){
			if(r!=-INF){
				ret.PB(II(l,r));
			}
			l=it.FIR;
			r=it.SEC;
		}
		else{
			check_max(r,it.SEC);
		}
	}
	ret.PB(II(l,r));
	return ret;
}
const int MAXN=100000+20;
int bit[MAXN+10]={0};
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&(-i);
	}
	return s;
}
void add(int i,int x=1){
	while(i<=MAXN){
		bit[i]+=x;
		i+=i&(-i);	
	}
}
vector<int> v;
int Find(int x){
	return lower_bound(ALL(v),x)-v.begin()+1;
}
int process(pair<int,bool> A){
	return (A.SEC? 1:-1)*sum(Find(A.FIR));
}
int main(){
	scanf("%d",&n);
	rb(i,1,n){
		int X1,X2,Y1,Y2;
		scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
		if(X1==X2){// 
			if(Y1>Y2)
				swap(Y1,Y2);
			row[X1].PB(II(Y1,Y2));
		}
		else{// 
			if(X1>X2)
				swap(X1,X2);
			column[Y1].PB(II(X1,X2));
		}
	}
	LL rest=0;
	for(auto it=row.begin();it!=row.end();it++){
		it->SEC=upd(it->SEC); 
		for(auto itt:it->SEC)
			rest+=itt.SEC-itt.FIR+1;
	}
	for(auto it=column.begin();it!=column.end();it++){
		v.PB(it->FIR);
		it->SEC=upd(it->SEC);
		for(auto itt:it->SEC){
			queries.insert(II(itt.SEC,II(it->FIR,0)));
			queries.insert(II(itt.FIR-1,II(it->FIR,1)));	
			rest+=itt.SEC-itt.FIR+1;
		}
	}
	sort(ALL(v));
	for(auto it=row.begin();it!=row.end();it++){
		while(queries.begin()!=queries.end()&&queries.begin()->FIR<it->FIR){
			rest+=process(queries.begin()->SEC);
			queries.erase(queries.begin());
		}
		for(auto itt:it->SEC){
			int l,r;
			l=Find(itt.FIR);
			r=Find(itt.SEC+1);
			add(l);
			add(r,-1);
		}
	}	
	while(queries.begin()!=queries.end()){
		rest+=process(queries.begin()->SEC);
		queries.erase(queries.begin()); 
	}
	cout<<rest<<endl;
	return 0;
}
/*



setset 
*/