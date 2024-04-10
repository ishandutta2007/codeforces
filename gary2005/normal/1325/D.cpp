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
int main(){
	fastio;
	LL u,v;
	cin>>u>>v;
	if(u+v==0){
		cout<<0;
		return 0;
	}
	if(u==v){
		cout<<1<<endl;
		cout<<u<<endl;
		return 0;
	}
	if(u>v||(v-u)%2){
		cout<<-1;
	}
	else{
		LL a=0,b=0;
		LL t=(v-u)/2;
		LL is=1;
		
		LL saveu=u;
		//find a b that a&b=t,a^b=u 
		while(t||u){
//			cout<<11<<endl;
			bool k1,k2;
			k1=t&1ll;
			k2=u&1ll;
			if(k1&&k1==k2){
				a=-1;
				break; 
			}
			if(k1){
				a+=is;
				b+=is;
			}
			else{
				if(k1==k2){
					
				}
				else{
					a+=is;
				}
			}
			u>>=1ll;
			t>>=1ll; 
			is<<=1ll;
		}
		if(a>=0)
		cout<<2<<'\n'<<a<<" "<<b<<endl;
		else 
		cout<<3<<'\n'<<saveu<<" "<<(v-saveu)/2<<" "<<(v-saveu)/2<<endl;
	}
	return 0;
}