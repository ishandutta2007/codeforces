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
typedef complex<double> Comp;
const double PI=3.14159265358979323846;
const Comp I(0,1);
const int len=1<<18;
int rev[len];
void butterfly(vector<Comp> &v){
	rep(i,len){
		rev[i]=rev[i>>1]>>1;
		if(i&1) rev[i]|=len>>1;
	}
	rep(i,len) if(rev[i]>i) swap(v[i],v[rev[i]]);
}
vector<Comp> fft(vector<Comp> v,int ty){
	v.resize(len);
	butterfly(v);
	for(int l=2;l<=len;l<<=1){
		Comp step(cos(2.0*PI/l),sin(2.0*PI*ty/l));
		for(int j=0;j<len;j+=l){
			Comp now(1,0);
			for(int k=0;k<l/2;++k){
				Comp A,B;
				A=v[j+k];
				B=now*v[j+k+l/2];
				v[j+k]=A+B;
				v[j+k+l/2]=A-B;
				now*=step;
			}
		}
	}
	return v;
}
vector<LL> mul(vector<int> A,vector<int> B){
	vector<Comp> AA(len,Comp(0,0)),BB(len,Comp(0,0));
	rep(i,len) AA[i]=Comp(A[i],0),BB[i]=Comp(B[i],0);
	AA=fft(AA,1);
	BB=fft(BB,1);
	rep(i,len) AA[i]*=BB[i];
	AA=fft(AA,-1);
	vector<LL> ret(len);
	rep(i,len){
		double tmp=AA[i].real()/len;
		ret[i]=llround(tmp);
	}
	return ret;
}
vector<LL> add(vector<LL> A,vector<LL> B){
	rep(i,len) A[i]+=B[i];
	return A;
}
const int MAXN=1e5+1;
int n,m,q;
int a[MAXN],b[MAXN];
vector<LL> cnt;// cnt[i] the number of i
vector<LL> emx,emn;
vector<LL> fmx,fmn;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,m) scanf("%d",&b[i]);
	vector<int> A,B;
	A=vector<int> (len,0);
	B=vector<int> (len,0);
	rb(i,1,n) A[a[i]]++;
	rb(j,1,m) B[b[j]]++;
	cnt=mul(A,B);
	A=vector<int> (len,0);
	B=vector<int> (len,0);
	rb(i,1,n-1) A[min(a[i],a[i+1])]++;
	rb(j,1,m) B[b[j]]++;
	emn=mul(A,B);
	A=vector<int> (len,0);
	B=vector<int> (len,0);
	rb(j,1,m-1) B[min(b[j],b[j+1])]++;
	rb(i,1,n) A[a[i]]++;
	emn=add(emn,mul(A,B));
	A=vector<int> (len,0);
	B=vector<int> (len,0);
	rb(i,1,n-1) A[max(a[i],a[i+1])]++;
	rb(j,1,m) B[b[j]]++;
	emx=mul(A,B);
	A=vector<int> (len,0);
	B=vector<int> (len,0);
	rb(j,1,m-1) B[max(b[j],b[j+1])]++;
	rb(i,1,n) A[a[i]]++;
	emx=add(emx,mul(A,B));
	A=vector<int> (len,0);
	B=vector<int> (len,0);
	rb(i,1,n-1) A[min(a[i],a[i+1])]++;
	rb(j,1,m-1) B[min(b[j],b[j+1])]++;
	fmn=mul(A,B);
	A=vector<int> (len,0);
	B=vector<int> (len,0);
	rb(i,1,n-1) A[max(a[i],a[i+1])]++;
	rb(j,1,m-1) B[max(b[j],b[j+1])]++;
	fmx=mul(A,B);
	rep(i,len) if(i) cnt[i]+=cnt[i-1],emx[i]+=emx[i-1],fmx[i]+=fmx[i-1];
	rl(i,len-2,0) emn[i]+=emn[i+1],fmn[i]+=fmn[i+1];
	while (q--){
		int x;
		scanf("%d",&x);
		LL v1,e1,g1,v2,e2,g2;
		v1=cnt[len-1]-cnt[x-1];
		v2=cnt[x-1];
		e1=emn[x];
		e2=emx[x-1];
		g1=fmn[x];
		g2=fmx[x-1];
		printf("%lld\n",v1-v2-e1+e2-g2+g1);
	}
	return 0;
}