/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int rest=0;
const int MAXN=200000+20;
int bit[MAXN+10]={0};
int n;
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&(-i);
	}
	return s;
}
void add(int i,int x=1){
	while(i<=200000+10){
		bit[i]+=x;
		i+=i&(-i);	
	}
}
int main(){
	fastio;
	string s,t;
	cin>>n;
	cin>>s;
	t=s;
	reverse(ALL(s));
	set<int> ss[26];
	rb(i,0,n-1){
		ss[s[i]-'a'].insert(i);
	}
	LL rest=0;
	rep(i,n){
		int need=t[i]-'a';
		int index=*ss[need].begin();
		ss[need].erase(ss[need].begin());
		int real=index+sum(index+1);
		add(1);
		add(index+2,-1);
		assert(real>=i);
		rest+=real-i;
	}
	cout<<rest<<endl;
	return 0;
}
/** 
  *
  *
  *
  *
  **/