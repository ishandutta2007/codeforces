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
void ope1(vector<int> &v){
	for(int i=0;i<v.size();i+=2){
		swap(v[i],v[i+1]);
	}
}
void ope2(vector<int> &v){
	rep(i,v.size()/2){
		swap(v[i],v[i+v.size()/2]); 
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> v(2*n);
	rep(i,2*n){
		cin>>v[i];
	}
	vector<int> sot(2*n);
	rep(i,2*n) sot[i]=i+1;
	vector<int> old=v;
	map<vector<int> ,bool> app;
	int cnt=0;
	int ans=1e9;
	for(int i=0;;i^=1){
		if(sot==v){
			check_min(ans,cnt);
			break;
		}
		app[v]=1;
		if(i==0) ope1(v);
		else ope2(v);
		if(app[v]) break;
		++cnt;
	}
	v=old;
	cnt=0;
	app.clear();
	for(int i=0;;i^=1){
		if(sot==v){
			check_min(ans,cnt);
			break;
		}
		app[v]=1;
		if(i==1) ope1(v);
		else ope2(v);
		if(app[v]) break;
		++cnt;
	}
	if(ans==1e9) ans=-1;
	cout<<ans<<endl;
	return 0;
}