/*
Nearly  
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
typedef pair<LL,LL> mp;
typedef pair<mp,mp> superpair;
pair<LL,LL> ant[300000+1];
LL n,l,t; 
map<LL,LL> index;
int res[300000+1];
int main(){
	fastio;
	cin>>n>>l>>t;
	LL cur=0;
	vector<LL> v;
	rb(i,1,n)
	{
	
		char c;
		cin>>ant[i].FIR>>c;
		ant[i].FIR--;
		if(c=='R') ant[i].SEC=1;
		else ant[i].SEC =-1;
		index[ant[i].FIR]=i;
	}
	sort(ant+1,ant+1+n);
	rb(i,1,n){
		v.PB((((LL)ant[i].FIR+ant[i].SEC*t)%l+l)%l);
		cur+=(ant[i].FIR+ant[i].SEC*t)/l;
		if((ant[i].FIR+ant[i].SEC*t)%l<0) cur--;
	}
	sort(ALL(v));
	cur=(cur%n+n)%n;
	int now=0;
	rb(i,cur,v.size()-1) res[index[ant[++now].FIR]]=v[i];
	rep(j,cur) res[index[ant[++now].FIR]]=v[j];
	rb(i,1,n) cout<<res[i]+1<<" ";
	return 0;
}