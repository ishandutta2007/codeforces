/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
typedef complex<double> Comp;
const double PI=3.14159265358979323846;
const Comp I(0,1);
int len;
int rev[1048576];
void butterfly(vector<Comp> & v){
	rep(i,len){
		rev[i]=rev[i>>1]>>1;
		if(i&1) rev[i]|=len>>1; 
	}
	rep(i,len) if(rev[i]>i) swap(v[i],v[rev[i]]);
}
vector<Comp> fft(vector<Comp> v,int ty){
	butterfly(v);
	vector<Comp> nex;
	for(int l=2;l<=len;l<<=1){
		nex.clear();
		nex.resize(len);
		Comp step(cos(2.0*PI/l),sin(2.0*ty*PI/l));
		for(int j=0;j<len;j+=l){
			Comp now(1,0);
			for(int k=0;k<l/2;++k){
				Comp A,B;
				A=v[j+k];
				B=v[j+l/2+k];
				B=now*B;
				nex[j+k]=A+B;
				nex[j+k+l/2]=A-B;
				now=now*step;
			}
		}
		v=nex;
	}
	return v;
}
int get(int x){
	int y=1;
	while(y<x) y<<=1;
	return y;
}
vector<int> mul(vector<int> A,vector<int> B){
	vector<Comp> a,b;
	len=get(A.size()+B.size());
	a.resize(len);
	b.resize(len);
	rep(i,A.size()) a[i]=Comp(A[i],0);
	rep(i,B.size()) b[i]=Comp(B[i],0);
	a=fft(a,1);
	b=fft(b,1);
	rep(i,len) a[i]*=b[i];
	a=fft(a,-1);
	vector<int> ret;
	ret.resize(len);
	rep(i,len) ret[i]=floor(a[i].real()+0.5)/len;
	int reall=0;
	rep(i,len) ret[i]=(ret[i]>0)*2;
	rep(i,len) if(ret[i]) reall=i+1;
	ret.resize(reall);
	return ret;
}
int n;
vector<int> a;
vector<int> quick(int k){
	if(k==1){
		return a;
	}
	vector<int> ret=quick(k>>1);
	ret=mul(ret,ret);
	if(k&1){
		ret=mul(ret,a);	
	} 
	return ret;
}
int main(){
	scanf("%d",&n);
	int k;
	cin>>k;
	vector<int> rest;
	a.resize(1001);
	rb(i,1,n){
		int ai;
		scanf("%d",&ai);
		a[ai]=1;
	}
	rest=quick(k);
	rep(i,rest.size()){
		if(rest[i]){
			printf("%d ",i);
		}
	}
	return 0;
}