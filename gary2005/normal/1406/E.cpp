/*
{By GWj
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
bool prime[100000+20];
int block=97;
bool del[100000+20];
int n;
bool q(LL x){
	if(x>(LL)n) return 0;
	cout<<"A "<<x<<endl;
	ff;
	int rr;
	R(rr);
	return rr!=0;
}
int main(){
	fastio;
	R(n);
	if(n==1){
		cout<<"C 1"<<endl;
		return 0;
	}
	vector<int> primes,have_fact;
	rb(i,2,n){
		if(!prime[i]){
			primes.PB(i);
			for(int j=i+i;j<=n;j+=i){
				prime[j]=1;
			}
		}
	}
	int cnt=0;
	bool get=0;
	int las=0; 
	for(auto it:primes){
		cnt++;
		int rest=0;
		cout<<"B "<<it<<endl;ff;
		R(rest);
		for(int j=it;j<=n;j+=it){
			if(!del[j/it]){
				rest--;
			}
		}
		if(rest!=0){
			have_fact.PB(it);
		}
		for(int j=it;j<=n;j+=it){
			del[j]=1;
		}
		if(cnt%block==0){
			if(!get){
				cout<<"A "<<1<<endl;ff;
				int rest;
				R(rest);
				rb(i,1,n){
					if(!del[i]) rest--;
				}
				if(rest!=0){
					get=1;
					rb(i,las,cnt-1){
						cout<<"B "<<primes[i]<<endl;ff;
						int rest;
						R(rest;) 
						if(rest!=0){
							get=1;
							have_fact.PB(primes[i]);
							break;
						}		
					}	
				}
							
			}	
			las=cnt;
		}
	}
	if(!get){
		rb(i,las,cnt-1){
			cout<<"B "<<primes[i]<<endl;ff;
			int rest;
			R(rest;) 
			if(rest!=0){
				get=1;
				have_fact.PB(primes[i]);
				break;
			}		
		}	
	}
	if(have_fact.empty()){
		cout<<"C 1"<<endl;
		ff;
		return 0;	
	}
	int rest=1;
	for(auto it:have_fact){
		LL now=it;
		while(q(now)){
			now*=it;
		}
		now/=it;
		rest*=now;
	}	
	cout<<"C "<<rest<<endl;ff;
	return 0;
}