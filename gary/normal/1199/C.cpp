//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int ai;
int max_=-INF;
map<int,int> tot;
vector<int> ta;
int main(){
	int n,I;
	scanf("%d %d",&n,&I);
	rb(i,1,n){
		scanf("%d",&ai);
		tot[ai]++;
//		sum+=ai;
	}
	//n<=400000,I<=1e8
	I*=8;
	I/=n;
	if(int(log2(double(n)))<I){
		puts("0");
		return 0;
	}
	int K=1<<I;
	map<int,int> :: IT ite;
	for(ite=tot.begin();ite!=tot.end();ite++){
		ta.PB(ite->SEC);
	}
	if(ta.size()<=K){
		puts("0");
		return 0;
	}
	int SZ=ta.size();
	max_=0;
	rb(i,0,K-1){
		max_+=ta[i];
	}
	int tmp_max=max_;
	rb(i,1,SZ-1){
		if(i+K-1>=SZ){
			break;
		}
		tmp_max-=ta[i-1];
		tmp_max+=ta[i+K-1];
		max_=max(max_,tmp_max);
	}
	cout<<n-max_<<endl;
	return 0;
}