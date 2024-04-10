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
int tmp[1000000+2],a[1000000+2];
set<int> s;
int main(){
	fastio;
	int n;
	int mm=-1;
	cin>>n;rb(i,1,n) cin>>tmp[i],mm=max(mm,tmp[i]);
	rb(i,1,n) if(mm==tmp[i]) {
		mm=i;break;
	}
	tmp[0]=tmp[n];
	rb(i,1,n) a[i]=tmp[(i+mm-1)%n];
	s.insert(0);
	s.insert(n+1);
	map<int,vector<int > >  m;
	rb(i,1,n) m[-a[i]].PB(i);
	LL res=0;
	for(map<int,vector<int> > :: IT ite=m.begin();ite!=m.end();ite++){
		vector<int> add=ite->SEC;
		vector<mp> range;
		for(auto it:add){
			set<int> :: IT ite=s.lower_bound(it);
			
			range.PB(II(0,0));
			ite--;
			range[range.size()-1].FIR=*ite;
			ite++;
			range[range.size()-1].SEC=*ite;
//			res+=range
		}
		for(auto it:range){
			if(it.FIR)
				res++;
			if(it.SEC<=n)
				res++;
			if(it.SEC==n+1&&it.FIR!=1&&-ite->FIR!=a[1]){
//				cout<<-ite->FIR<<endl;
				res++;
			}
		}
		int now=0;
//		cout<<ite->FIR<<" "<<range[0].FIR<<" "<<range[0].SEC<<" "<<res<<endl;
		for(auto it:range){
			res+=lower_bound(ALL(add),it.SEC)-upper_bound(ALL(add),add[now++]);
		}
//		cout<<res<<endl;
		for(auto it:add)
			s.insert(it);
	}
	cout<<res<<endl;
	return 0;
}