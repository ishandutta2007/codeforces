//* AuThOr GaRyMr *//
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
mp a[200000+10];int tot[200000+10];
vector<pair<mp,int > >  v;
int main(){
	int n,q;
	cin>>n>>q;
	rb(i,1,200000){
		a[i]=II(-1,-1);
	}
	rep(i,n){
		int ai;
		scanf("%d",&ai);
		if(a[ai].FIR==-1) a[ai].FIR=i+1;
		a[ai].SEC=i+1;
		tot[ai]++;
	}
	rb(i,1,200000){
		if(a[i].FIR!=-1)
		v.PB(II(a[i],tot[i]));
	}
	sort(ALL(v));
	int start=-1,end_=-1,res=0,maxi=1;
	v.PB(II(II(INF,INF),INF));
	for(auto it:v){
		int h,t,hav;
		h=it.FIR.FIR,t=it.FIR.SEC,hav=it.SEC;
//		cout<<it<<" "<<
		if(h>end_){
//			cout<<end_<<" "<<start<<" "<<maxi<<endl;
			res+=end_-start+1;
			res-=maxi;
			maxi=hav;
			start=h,end_=t;
		}
		else{
			maxi=max(maxi,hav);
			end_=max(end_,t);
		}
	}
	cout<<res<<endl;
	return 0;
}