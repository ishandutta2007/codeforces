//* AuThOr GaRyMr *// 
#include<bits/stdc++.h>
#define rb(a,b,c) for(LL a=b;a<=c;++a)
#define rl(a,b,c) for(LL a=b;a>=c;--a)
#define niv vector<LL>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const LL INF=0x3f3f3f3f;
typedef pair<LL,LL> mp;
typedef pair<mp,mp> superpair;
LL hp[200000+10],dmg[200000+10];
mp bigger[200000+10];
bool cmp(mp A,mp B){
	return A>B;
}
LL cost=0;
LL tmp_cost;
LL all_cost;
LL stop=0;
map<LL,int> app;
LL tmp_bigger=0;
map<LL,LL> M;
int main(){
	LL n,a,b;
	scanf("%I64d %I64d %I64d",&n,&a,&b);
	b=min(b,n);
	rb(i,1,n){
		scanf("%I64d %I64d",&hp[i],&dmg[i]);
		bigger[i]=II(hp[i]-dmg[i],i);
		tmp_cost+=dmg[i];
	}
	all_cost=tmp_cost;
	sort(bigger+1,bigger+1+n,cmp);
	rb(i,1,b){
		if(bigger[i].FIR<0) break;
		tmp_cost+=bigger[i].FIR;
		if(i!=b) tmp_bigger+=bigger[i].FIR;
		if(i!=b)stop=i;
		if(i!=b)app[bigger[i].SEC]=1;
		M[bigger[i].SEC]=i;
	}
	cost=tmp_cost;
//	cout<<all_cost<<" "<<tmp_bigger<<endl;
	if(a&&b) 
	rb(i,1,n){
		tmp_cost=all_cost;
		if(hp[i]*(1<<(a))<=dmg[i]) continue;
		LL tmp_big=hp[i]*(1<<(a))-dmg[i];
		tmp_cost+=tmp_big;
		if(!app[i]){
			tmp_cost+=tmp_bigger;
		}
		else{
//			cout<<tmp_cost<<" "<<i<<endl;
			tmp_cost+=tmp_bigger-bigger[M[i]].FIR;
//			cout<<
			if(stop<n){
				if(bigger[stop+1].FIR>0){
					tmp_cost+=bigger[stop+1].FIR;
				}
			}
		}
//		cout<<i<<" "<<tmp_cost<<endl;
		cost=max(cost,tmp_cost);
	}
	cout<<cost<<endl;
	return 0;
}