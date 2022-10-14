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
int n;
int a[100007],Mobius[100007];
vector<int> mul[100000+7];
bool prime[100000+87];
vector<int> fact[100000+3],facts[100000+3];
int cnt[100000+3];
void add(int x){
	for(auto it:facts[x]){
		cnt[it]++;
	}
}
void erase(int x){
	for(auto it:facts[x]){
		cnt[it]--;
	}
}
int main(){
	fastio;
	R(n);
	rb(i,1,n)
		R(a[i]);
	rb(i,2,100000){
		if(!prime[i]){
			fact[i].PB(i);
			for(int j=i+i;j<=100000;j+=i){
				fact[j].PB(i);
				prime[j]=1;
			}
		}
	}
	rb(i,1,100000){
		for(int j=i;j<=100000;j+=i){
			facts[j].PB(i);
		}
	}
	Mobius[1]=1;
	rb(i,2,100000){
		Mobius[i]=1;
		for(auto it:fact[i]){
			if((i/it)%it==0){
				Mobius[i]=0;
			}
			Mobius[i]*=-1;
		}
	}
	stack<int> sta;
	rb(i,1,n){
		for(int j=1;j*j<=a[i];j++){
			if(a[i]%j==0){
				mul[j].PB(a[i]/j);
				if(j*j!=a[i]) mul[a[i]/j].PB(j);
			}
		}
	}
	LL rest=1; 
	rb(i,1,100000){
		sort(ALL(mul[i]));
		reverse(ALL(mul[i]));
//		if(i==3) for(auto it:mul[i]){
//			cout<<it<<" ";
//		}
//		if(i==3)
//		cout<<endl;
		stack<int> st;
		LL tmp=0;
		for(auto it:mul[i]){
			int tmpp=0;
			for(auto it2:facts[it]){
				tmpp+=Mobius[it2]*cnt[it2];
//				cout<<it2<<" "<<Mobius[it2]<<" "<<cnt[it2]<<" "<<tmpp<<endl; 
			}
//			cout<<it<<"_"<<tmpp<<" "<<cnt[11]<<" "<<Mobius[77]<<endl; 
			if(tmpp){
				while(!st.empty()){
					if(__gcd(st.top(),it)==1){
						if(tmpp==1) break;
						tmpp--;
					}
					erase(st.top());
					st.pop();
				}
				tmp=max(tmp,1ll*st.top()*it);
			}
			add(it);
			st.push(it);
		}
		while(!st.empty()){
			erase(st.top());
			st.pop();
		}
//		if(tmp){
//			cout<<i<<" "<<tmp<<endl; 
//		}
		rest=max(rest,tmp*i);
	}
	cout<<rest<<endl;
	return 0;	
}

/*
41
2 30 1 1 3 1 1 21 27 12 1 1 18 2 1 15 1 9 3 15 15 3 1 1 6 2 2 1 2 12 18 18 2 1 30 1 15 1 2 30 15
*/