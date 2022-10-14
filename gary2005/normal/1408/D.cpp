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
int a[2000+1],b[2000+1],c[2000+1],d[2000+1];
int is[1000000+20];
int iss[2000+1];
vector<pair<int,mp> > v;
int main(){
	fastio;
	int n,m;
	R2(n,m);
	rb(i,1,n) cin>>a[i]>>b[i];
	rb(i,1,m) {
		int  x,y;
		cin>>x>>y;
		c[i]=x+1;
		d[i]=y+1;
		is[y]=max(is[y],x+1);
	}
	rl(i,1000000+1,0) is[i]=max(is[i+1],is[i]);
	set<mp> s;
	rb(i,1,n){
		iss[i]=max(0,is[b[i]]-a[i]);
		s.insert(II(iss[i],i));
	}
	rb(i,1,1000000+10){
		if(is[i]!=is[i-1]){
			rb(j,1,n){
				if(i>=b[j]){
					v.PB(II(i-b[j],II(j,is[i])));
				}
			}
		}
	} 
	sort(ALL(v));
	int l=0;
	set<mp> :: IT ite;	
	ite=s.end();
	ite--;
	int rest=(*ite).FIR;
	while(l<v.size()){
		int L=l;
		while(l+1<v.size()&&v[l+1].FIR==v[l].FIR){
			l++;
		}
		rb(i,L,l){
			s.erase(II(max(0,iss[v[i].SEC.FIR]),v[i].SEC.FIR));
			iss[v[i].SEC.FIR]=max(0,v[i].SEC.SEC-a[v[i].SEC.FIR]);
			s.insert(II(max(0,iss[v[i].SEC.FIR]),v[i].SEC.FIR));
		}
		ite=s.end();
		ite--;
		check_min(rest,v[l].FIR+(*ite).FIR);
		l++;
	}
	cout<<rest<<endl;
	return 0;
}