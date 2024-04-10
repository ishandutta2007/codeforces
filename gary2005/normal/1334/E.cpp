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
const int MOD=998244353;
LL D;
LL fac[71],rfact[71];
LL c(int x,int y){
	return fac[y]*rfact[x]%MOD*rfact[y-x]%MOD;
}
vector<vector<LL> >  divd;
bool vis[5000000]; 
map<LL,int> m;
LL quick(LL A,LL B){
	if(!B) return 1ll;
	LL tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1) tmp*=A,tmp%=MOD;
	return tmp;
}
LL Res[5000000];
int main(){
	fastio;
	fac[0]=1;
	rb(i,1,70)
		fac[i]=fac[i-1]*i,fac[i]%=MOD;
	rfact[70]=quick(fac[70],MOD-2);
	rl(i,70-1,1)
		rfact[i]=rfact[i+1]*(i+1),rfact[i]%=MOD;
	rfact[0]=1;
	cin>>D;
	vector<LL> facts;
	for(LL i=1;i*i<=D;i++){
		if(D%i==0) {
			facts.PB(i);
			if(i*i!=D)
				facts.PB(D/i);
		}
	}
	sort(ALL(facts));
	rep(i,facts.size())
		m[facts[i]]=i;
	divd=vector<vector<LL> > (facts.size());
	rep(i,facts.size()){
		if(!i) continue;
		if(!vis[i]){
			vis[i]=1;
			vector<LL> F;
			for(LL j=1;j*j<=facts[i];j++){
				if(facts[i]%j==0){
					if(j!=1){
						F.PB(j);
						break;	
					}
					F.PB(facts[i]/j);
				}
			}
			sort(ALL(F));
			LL tmp=facts[i];
			for(auto it:F){
			divd[i].PB(it);break;
			}		
//			for(LL j=facts[i]*2;j<=D&&D%j==0;j+=facts[i]){
//				if(vis[m[j]]){
//					break;
//				}
//				vis[m[j]]=1;
//				divd[m[j]].PB(facts[i]);
//			}
		}
	}
	rep(i,facts.size()){
//		cout<<"#:"<<facts[i]<<":";for(auto it:divd[i]) cout<<it<<" ";cout<<endl;
		if(!i||divd[i][0]==facts[i]){
			
		}
		else{
			LL tmp=divd[i][0];
			divd[i]=divd[m[facts[i]/divd[i][0]]];
			divd[i].PB(tmp);
		}
		sort(ALL(divd[i]));
	}
	vector<LL> tmp;
	rep(i,facts.size()){
		tmp.clear();
		rep(j,divd[i].size()){
			if(!j||divd[i][j]!=divd[i][j-1]){
				tmp.PB(1);
			}
			else{
				tmp[tmp.size()-1]++;
			}
		}
		LL sum=0;
		Res[i]=1;
		for(auto it:tmp)
			{
				sum+=it;
			}
		for(auto it:tmp){
			Res[i]*=c(it,sum);
			Res[i]%=MOD;
			sum-=it;
		}
	}
	int Q;
	cin>>Q;
	while(Q--){
		LL u,v;
		cin>>u>>v;
		LL g=__gcd(u,v);
		u/=g,v/=g;
		cout<<Res[m[u]]*Res[m[v]]%MOD<<endl;	
	}
	return 0;
}