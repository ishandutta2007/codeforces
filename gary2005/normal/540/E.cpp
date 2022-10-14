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
int n,cnt;
map<int,int> m,pos;
mp ope[100000+20];
vector<int> v;

const int MAXN=200000+20;
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
	void add(int i,int x){
		while(i<=n){
			bit[i]+=x;
			i+= i&(-i);	
		}
	}
}bb;
bool cmp(int A,int B){
	return pos[A]>pos[B];
}
int bs(int l,int r){
	if(l>r) return 0;
	return upper_bound(ALL(v),r)-lower_bound(ALL(v),l);
}
map<int,int> to_val; 
int main(){
	fastio;
	cin>>n;
	bb.n=n*2;
	rb(i,1,n)
		cin>>ope[i].FIR>>ope[i].SEC;
	rb(i,1,n)
		m[ope[i].FIR]=m[ope[i].SEC]=1;
	cnt=0;
	map<int,int> vvv;
	for(map<int,int> :: IT ite=m.begin();ite!=m.end();ite++){
		ite->SEC=++cnt;
		pos[ite->FIR]=ite->FIR;
		v.PB(ite->FIR);
//		vvv[it->FIR]
	}
	vvv=pos;
	rb(i,1,n){
		int x,y;
		x=vvv[ope[i].FIR];
		y=vvv[ope[i].SEC];
//		
		swap(pos[x],pos[y]);
		swap(vvv[ope[i].FIR],vvv[ope[i].SEC]);
		
	}
	LL res=0;
	sort(ALL(v),cmp);
	for(auto it:v){
		res+=bb.sum(m[it]-1);
		bb.add(m[it],1);
//		cout<<res<<endl;
	}
	rep(i,v.size()) to_val[pos[v[i]]]=v[i];
	sort(ALL(v));
	for(auto it:v)
	{	
		int po,va;
		va=to_val[it];
		po=it;
		if(po<va){
			//to left
			res+=max(0,va-po-1-bs(po+1,va-1));
		}
		else{
			//to right
			res+=max(0,po-va-1-bs(va+1,po-1));
		}
	}
	cout<<res<<endl;
	return 0;
}