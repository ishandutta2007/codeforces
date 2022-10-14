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
int n,k;
struct NTT{
	int MOD;
	int g;
	int len;
	int rev[1<<16];
	NTT(int M,int G){
		MOD=M,g=G;
	}
	void butterfly(vector<int> & v){
		rep(i,len){
			rev[i]=rev[i>>1]>>1;
			if(i&1) rev[i]|=len>>1; 
		}
		rep(i,len) if(rev[i]>i) swap(v[i],v[rev[i]]);
	}
	LL quick(LL A,LL B){
		if(B==0) return 1;
		LL  tmp=quick(A,B>>1);
		tmp*=tmp;
		tmp%=MOD;
		if(B&1)
			tmp*=A,tmp%=MOD;
	 	return tmp;
	}
	int inv(int x){
		return quick(x,MOD-2);
	}
	vector<int> ntt(vector<int> v,int ty){
		for(auto & it: v){
			it%=MOD;
		}
		butterfly(v);
		vector<int> nex;
		for(int l=2;l<=len;l<<=1){
			nex.clear();
			nex.resize(len);
			int step=quick(g,(MOD-1)/l);
			if(ty==-1) step=inv(step); 
			for(int j=0;j<len;j+=l){
				int now=1;
				for(int k=0;k<l/2;++k){
					int A,B;
					A=v[j+k];
					B=v[j+l/2+k];
					B=1ll*now*B%MOD;
					nex[j+k]=(A+B)%MOD;
					nex[j+k+l/2]=(A-B+MOD)%MOD;
					now=1ll*now*step%MOD;
				}
			}
			v=nex;
		}
		return v;
	}
	void getlen(int x){
		len=1;
		while(len<x){
			len<<=1;
		}
	}
	vector<int> mul(vector<int> A,vector<int> B){
		getlen(A.size()+B.size());
		A.resize(len);
		B.resize(len);
		A=ntt(A,1);
		B=ntt(B,1);
		rep(i,len) A[i]=1ll*A[i]*B[i]%MOD;
		A=ntt(A,-1);
		int iv=inv(len);
		rep(i,len){
			A[i]=1ll*A[i]*iv%MOD;
		}
		while(!A.empty()&&A.back()==0) A.pop_back();
		if(A.size()>k+1) A.resize(k+1);
		return A;
	}
}t1(7340033,3),t2(23068673,3),t3(104857601,3);
__int128_t m1=23068673ll*104857601,c1;
__int128_t m2=7340033ll*104857601,c2;
__int128_t m3=23068673ll*7340033,c3;
__int128_t nn;
int fac[30000+20];
const int MOD=1e9+7;
vector<int> poly_mul(vector<int> A,vector<int> B){
	vector<int> r1,r2,r3;
	r1=t1.mul(A,B);
	r2=t2.mul(A,B);
	r3=t3.mul(A,B);
	int le=max(max(r1.size(),r2.size()),r3.size());
	r1.resize(le);
	r2.resize(le);
	r3.resize(le);
//	for(auto it:A){
//		cout<<it<<" ";
//	}
//	cout<<endl;
//	for(auto it:B){
//		cout<<it<<" ";
//	}
//	cout<<"Re"<<endl;
//	for(auto it:r3){
//		cout<<it<<" ";
//	}
//	cout<<endl;
	rep(i,le){
		r1[i]=((c1*r1[i]+c2*r2[i]+c3*r3[i])%nn)%MOD;
	}
//	rep(i,le){
//		cout<<r1[i]<<' ';
//	}
//	cout<<endl;
	
	return r1;
}
LL quick(LL A,LL B){
	if(B==0) return 1;
	LL  tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1)
		tmp*=A,tmp%=MOD;
 	return tmp;
}
LL quick(LL A,LL B,int mod){
	if(B==0) return 1;
	LL  tmp=quick(A,B>>1,mod);
	tmp*=tmp;
	tmp%=mod;
	if(B&1)
		tmp*=A,tmp%=mod;
 	return tmp;
}
vector<int> I;
vector<int> calc(int m){
	if(m==1){
		return I;
	}
	if(m&1){
		vector<int> tmp=calc(m-1);
		rep(i,tmp.size()){
			tmp[i]=1ll*tmp[i]*quick(2,i)%MOD;
		}
		tmp=poly_mul(tmp,I);
		return tmp;
	}
	else{
		vector<int> tmp=calc(m>>1);
		vector<int> t=tmp;
		rep(i,t.size()){
			t[i]=1ll*t[i]*quick(2,i*(m>>1))%MOD;
		}
		tmp=poly_mul(t,tmp);
		return tmp;
	}
}
int c(int A,int B){
	return 1ll*fac[A]*quick(fac[B],MOD-2)%MOD*quick(fac[A-B],MOD-2)%MOD;
}
int main(){
	c1=quick(m1%7340033,7340033-2,7340033);
	c2=quick(m2%23068673,23068673-2,23068673);
	c3=quick(m3%104857601,104857601-2,104857601);
	nn=m3*104857601;
	c1*=m1;
	c2*=m2;
	c3*=m3;
	cin>>n>>k;
	I.resize(k+1);
	if(n>k){
		cout<<0<<endl;
		return 0;
	}
	fac[0]=1;
	rb(i,1,k){
		fac[i]=1ll*i*fac[i-1]%MOD;
	}
	rb(i,1,k) I[i]=quick(fac[i],MOD-2);
	vector<int> f=calc(n);
	int rest=0;
	rb(i,1,k){
		f[i]=1ll*f[i]*fac[i]%MOD;
		rest+=1ll*c(k,i)*f[i]%MOD;
//		cout<<c(k,i)<<' '<<f[i]<<endl;
		if(rest>=MOD) rest-=MOD;
	}
	cout<<rest<<endl;
	return 0;
}