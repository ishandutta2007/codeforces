/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,T,t[200000+20],b[200000+20];
map<int,int> m;
const int MAXN=200000;
struct BIT{
	int bit[MAXN+10]={0},n=MAXN;
	int sum(int i){
		if(!i) return 0;  
		int s=0;
		while(i>0){
			s+=bit[i];
			i-=i &(-i);
		}
		return s;
	}
	int query(int l,int r){
		if(r<l) return 0;
		return sum(r)-sum(l-1);
	}
	void add(int i,int x=1){
		while(i<=n){
			bit[i]+=x;
			i+= i&(-i);	
		}
	}
}bit;
set<int> s;
set<int> :: IT ite;
int get(int val){
	ite=s.upper_bound(val);
	if(ite==s.begin()) return 0;
	else{
		ite--;
		return m[*ite];
	}	
}
int main(){
	fastio;
	cin>>n>>T;
	rb(i,1,n) cin>>t[i],b[i]=t[i]-i;
	rb(i,1,n) m[b[i]]=1;
	int cnt=0;
	for(map<int,int> :: IT ite=m.begin();ite!=m.end();ite++)
	{
		s.insert(ite->FIR);
		ite->SEC=++cnt;
	}
	int res=0;
	rb(i,1,n){
		if(T-i<0) break; 
		int rest;
		rest=bit.sum(get(T-i));
		res=max(rest,res);
		bit.add(m[b[i]]);
	}
	if(T-(n+1)>=0)
	res=max(res,bit.sum(get(T-(n+1))));
	cout<<res<<endl;
	return 0;
}