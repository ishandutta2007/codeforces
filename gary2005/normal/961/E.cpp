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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN=2e5+10;
int n;
int a[MAXN];//<=1e9
struct BIT{
	int bit[MAXN+10]={0},n;
	int sum(int i){
		int s=0;
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
}bb;
int main(){
	fastio;
//	bb.n=n
	cin>>n;
	bb.n=n;
	rb(i,1,n) cin>>a[i];
	priority_queue<mp> q;
	LL res=0;
	rl(i,n,1){
		while(!q.empty()&&q.top().FIR>=i){
			bb.add(q.top().SEC,1);
			q.pop();
		}
//		cout<<bb.query(1,n)<<endl;
		res+=bb.query(1,min(a[i],n));
		q.push(II(a[i],i));
	}
	cout<<res<<endl;
	return 0;
}