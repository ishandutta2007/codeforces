/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
vector<mp> get(LL u){
	int i_=0;
	int last=0;
	vector<mp> v;
	rl(i,33,0){
		i_++;
		if((u>>i)&1){
			if(last==0) last=i_;		
		}
		else{
			if(last){
				v.PB(II(last,i_-1)); 
				last=0;
			}
		}
	}
	if(last){
		v.PB(II(last,i_));
	}
	return v;
}
void solve(){
	LL u,v;
	scanf("%lld%lld",&u,&v);
	vector<mp> A,B;
	A=get(u);
	B=get(v);
//	for(auto it:A) cout<<it.FIR<<" "<<it.SEC<<endl;
//	for(auto it:B) cout<<it.FIR<<" "<<it.SEC<<'_'; 
	int now=0;
	bool ok=0;
	rep(i,B.size()){
		auto& it=B[i];
		if(now==A.size()) {
			printf("NO\n");
			return ;
		}
		if(A[now].FIR==it.FIR){
			if(A[now].SEC>it.SEC){
				if(!ok){
					printf("NO\n");
					return ;	
				}
				else{
					A[now].FIR=it.SEC+1;
					continue;
				}
			}
			if(A[now].SEC==it.SEC){
				++now;
				continue;
			}
			it.FIR=A[now].SEC+1;
			++now;
		}
		if(now==A.size()){
			printf("NO\n");
			return ;
		}
		if(A[now].FIR<it.FIR&&!ok){
			printf("NO\n");
			return ;
		}
		while(now!=A.size()&&A[now].FIR<it.FIR){
			if(A[now].SEC<it.FIR) ++now;
			else break;
		}
		if(now==A.size()) {
			printf("NO\n");
			return ;
		}
		if(A[now].FIR<=it.FIR){
			A[now].FIR=it.FIR;
			i--;
			continue;
		}
		ok=1;
		int need=it.SEC-it.FIR+1;
		while(now!=A.size()&&need){
			if(A[now].SEC-A[now].FIR+1==need){
				need=0;
				++now;
				break;
			}
			if(A[now].SEC-A[now].FIR+1>need){
				A[now].FIR+=need;
				need=0;
				break;
			}
			need-=A[now].SEC-A[now].FIR+1;
			++now;
		}
		if(need){
			printf("NO\n");
			return ;
		}
	}
	if(now!=A.size()&&!ok) printf("NO\n");
	else printf("YES\n");
}
int main(){
	int q;
	scanf("%d",&q);
	while(q--) solve();
	return 0;
}