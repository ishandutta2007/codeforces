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
set<mp> heap;
int n,k,t,c[30],d[30][30];
LL rest[1<<22];
deque<int> q[30];
int count(int x){
	int ret=0;
	while(x){
		x=x&(x-1);
		ret++;
	}
	return ret;
}
int have=0;
int main(){
	scanf("%d%d%d",&n,&k,&t);
	string s;
	cin>>s; 
	s='#'+s;
	rep(i,k) scanf("%d",&c[i]);
	rep(i,k) rep(j,k) scanf("%d",&d[i][j]);
	rb(i,1,n){
		have|=1<<(s[i]-'A');
		q[s[i]-'A'].PB(i);
	}
	rep(i,k){
		if(!q[i].empty()){
			heap.insert(II(q[i].front(),i));
			q[i].pop_front();
		} 
	} 
	rb(i,1,n){
		if(!q[s[i]-'A'].empty()){
			heap.insert(II(q[s[i]-'A'].front(),s[i]-'A'));
			q[s[i]-'A'].pop_front();
		} 
		heap.erase(II(i,s[i]-'A'));
		int mask=0;
		for(auto it=heap.begin();it!=heap.end();it++){
			rest[mask]+=d[s[i]-'A'][(*it).SEC];
			rest[mask|(1<<(s[i]-'A'))]-=d[s[i]-'A'][(*it).SEC];
			rest[mask|(1<<((*it).SEC))]-=d[s[i]-'A'][(*it).SEC];
			rest[mask|(1<<((*it).SEC))|(1<<(s[i]-'A'))]+=d[s[i]-'A'][(*it).SEC];
			mask|=(1<<((*it).SEC));
			if((*it).SEC==s[i]-'A') break;
		}
	}
	rep(i,k)
		rep(mask,1<<k){
			if((mask>>i)&1)
				rest[mask]+=rest[mask^(1<<i)];
		}
	int rest_=0;
	rep(i,1<<k){
		if((i|have)!=have) continue;
		if(i==have) continue;
		LL tmp=rest[i];
		rep(j,k) if((i>>j)&1) tmp+=c[j];
		rest_+=tmp<=(LL)t;
	}	
	cout<<rest_<<endl;
	return 0;
}