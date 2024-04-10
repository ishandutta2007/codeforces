#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5;
struct Blocks{

int n,all,B;
vector<bool> pos;
vector<int> blocks,bel,S,E;
void init(int _n){
	n=_n,B=sqrt(n);
	pos.resize(n+2),bel.resize(n+2);
	blocks.resize(n/B+2);
	S.resize(n/B+2);
	E.resize(n/B+2);
	for(int i=1;i<=n;i++){
		bel[i]=(i-1)/B+1;
		E[bel[i]]=i;
	}
	for(int i=n;i;i--)S[bel[i]]=i;
}
void set(int x){
	if(!pos[x])pos[x]=1,blocks[bel[x]]++;
}
void unset(int x){
	if(pos[x])pos[x]=0,blocks[bel[x]]--;
}
int get(){
	int cur=1;
	while(blocks[cur]==E[cur]-S[cur]+1)cur++;
	for(int i=S[cur];;i++)if(!pos[i])return i;
	return assert(0),-1;
}

}b[N+5];
int n,t1,t2;
ll Ks[N+5],X[N+5],valk[N+5];
char O[N+5];
vector<int> nd[N+5];
map<ll,int> idk,idans,has;
int main(){
	scanf("%d",&n),has[0]=1;
	for(int i=1;i<=n;i++){
		char op[10];
		scanf("%s",op);
		O[i]=op[0];
		if(op[0]=='+'||op[0]=='-'){
			ll x;
			scanf("%lld",&x);
			has[x]=1;
			X[i]=x;
		}
		if(op[0]=='?'){
			ll k;
			scanf("%lld",&k);
			if(!idk[k])idk[k]=++t1,valk[t1]=k;
			X[i]=k;
		}
	}
	for(auto [k,id]:idk){
		ll u=0;
		while(has[u]){
			if(!idans.count(u))idans[u]=++t2;
			nd[idans[u]].push_back(id);
			u+=k;
		}
		b[id].init(u/k+1);
		b[id].set(1);
	}
	for(int i=1;i<=n;i++){
		if(O[i]=='+'){
			ll x=X[i];
			if(!idans.count(x))continue;
			for(int kid:nd[idans[x]]){
				b[kid].set(x/valk[kid]+1);
			}
		}
		if(O[i]=='-'){
			ll x=X[i];
			if(!idans.count(x))continue;
			for(int kid:nd[idans[x]]){
				b[kid].unset(x/valk[kid]+1);
			}
		}
		if(O[i]=='?'){
			ll k=X[i];
			cout<<b[idk[k]].get()*k-k<<'\n';
		}
	}
}