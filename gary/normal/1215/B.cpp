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
int a[200000+10];
vector<int> nev;
LL sum1[200000+10],sum2[200000+10],color[200000+10],is_[200000+10];
int main(){
	int n;
	cin>>n;
	rb(i,1,n) scanf("%d",&a[i]);
	LL res1,res2;
	res1=res2=0;
	rb(i,1,n) if(a[i]<0) nev.PB(i);
	if(!nev.empty()){
		int is=1;
		int co=1;
		for(auto it:nev){
			color[is]=co;
			co^=1;
			is++;
		}
		color[is]=co;
		int las=0;
		is=1;
		for(auto it:nev){
			is_[is++]=it-las;
			las=it;
		}
		is_[is]=1+n-las;
		rl(i,is,1){
			sum1[i]=sum1[i+1];
			sum2[i]=sum2[i+1];
			if(color[i]==1) sum1[i]+=is_[i];
			else sum2[i]+=is_[i];
		}
//		res1+=nev.size();
		rb(i,1,is){
			if(color[i]==1){
				res1+=(is_[i])*sum2[i+1];
			}
			else{
				res1+=(is_[i])*sum1[i+1];
			}
//			cout<<is_[i]<<endl;
//			res1+=is_[i]+1;
//			cout<<res1<<endl;
		}
//		res1-=is_[is]+1;
	}
	res2=(LL)(n)*(LL)(n+1)/(LL)(2)-res1;
	cout<<res1<<" "<<res2<<endl;
	return 0;
}