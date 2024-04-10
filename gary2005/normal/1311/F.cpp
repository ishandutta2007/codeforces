/*
AuThOr Gwj
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
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;

const int MAXN=200000;
struct BIT{
	LL bit[MAXN+10]={0},n=MAXN;
	LL sum(int i){
		LL s=0;
		while(i>0){
			s+=bit[i];
			i-=i &(-i);
		}
		return s;
	}
	int query(int l,int r){
		return sum(r)-sum(l-1);
	}
	void add(int i,int x=1){
		while(i<=n){
			bit[i]+=x;
			i+= i&(-i);	
		}
	}
}bit1,bit2;
int n;
mp a[MAXN+2];
map<int,int> m;
map<int,int> rm;
int main(){
	fastio;
	cin>>n;
	rb(i,1,n)
		cin>>a[i].SEC,m[a[i].SEC]=1;
		int cnt=0;
	for(map<int,int> :: IT ite=m.begin();ite!=m.end();ite++) ite->SEC=++cnt,rm[cnt]=ite->FIR;
	rb(i,1,n)
		a[i].SEC=m[a[i].SEC];
	rb(i,1,n)
		cin>>a[i].FIR;
	sort(a+1,a+1+n); 
	LL res=0;
	rb(i,1,n){
		res+=bit1.sum(a[i].SEC-1)*(rm[a[i].SEC])-bit2.sum(a[i].SEC-1);
		bit1.add(a[i].SEC);
		bit2.add(a[i].SEC,rm[a[i].SEC]);
	}
	cout<<res<<endl;
	return 0;
}