/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
8. CSPday2 meal
9.-or
10.
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
vector<pair<LL,LL> > v;
multiset<LL> mini; 
bool cmp(pair<LL,LL> A,pair<LL,LL> B){
	if(A.FIR!=B.FIR) return A.FIR<B.FIR;
	return A.SEC>B.SEC; 
}
int main(){
	cin>>n;
	rb(i,1,n){
		LL a ,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		v.PB(II(a,c));
		v.PB(II(b-c,-c)); 
	}
	LL res=0,time_=0;
	sort(ALL(v),cmp);
	int SZ=v.size();
	rep(i,SZ){
		LL fi,se;
		fi=v[i].FIR;
		se=v[i].SEC;
		if(se>0){
			mini.insert(se);
		}
		else{
			mini.erase(mini.lower_bound(-se));
		}
		LL nex;
		if(mini.size()){
			nex=v[i+1].FIR;
			if(time_>fi+*mini.begin()){
				time_=fi+*mini.begin();
			}
			if(time_<=nex){
			time_=max(time_,fi);
			res+=((nex-time_)/(*mini.begin()));
			time_+=((nex-time_)/(*mini.begin()))*(*mini.begin());	
			}
			
			while(time_<=nex){
				time_+=*mini.begin();
				res++;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}