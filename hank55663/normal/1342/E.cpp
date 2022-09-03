#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
const int P=998244353,root=3,MAXNUM=1<<20;
const int mod=998244353;
// Remember coefficient are mod P
/*
p=a*2^n+1 degree(poly) <= 2^n
n		2^n 				p 					a 		root
16  	65536 			    65537 				1 		3
20 	    1048576		 	    7340033 			7 		3
23                          998244353           119     3          
*/
int bigmod(long long a,int b){
	if(b==0)return 1;
	return (bigmod((a*a)%P,b/2)*(b%2?a:1ll))%P;
}
int inv(int a,int b){
	if(a==1)return 1;
	return (((long long)(a-inv(b%a,a))*b+1)/a)%b;
}
std::vector<long long> ps(MAXNUM);
std::vector<int> rev(MAXNUM);
LL f_pow(unsigned int a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%P;
        temp=temp*temp%P;
        b>>=1;
    }
    return res;
}
struct poly{
	std::vector<unsigned int> co;
	int n;//polynomial degree = n
	poly(int d){n=d;co.resize(n+1,0);}
	void ntt(int NN){
		int r=0,st,N;
		unsigned int a,b;
		r=0;
		//for(N=2;N<=NN;N<<=1,--r){
        for(N=NN;N>1;N>>=1,r++){
			for(st=0;st<NN;st+=N){
				int i,ss=st+(N>>1);
				for(i=(N>>1)-1;i>=0;--i){
					a=co[st+i]; //b=(ps[i<<r]*co[ss+i])%P;
                                b=co[ss+i];
					co[st+i]=a+b; if(co[st+i]>=P)co[st+i]-=P;
					//co[ss+i]=a+P-b; if(co[ss+i]>=P)co[ss+i]-=P;
                    co[ss+i]=((a+P-b)*ps[i<<r])%P;
				}
			}
		}
	}
	void ntt_inv(int NN){
        int r=0,st,N;
		unsigned int a,b;
		while((1<<r)<(NN>>1))++r;//inv:r=0
		for(N=2;N<=NN;N<<=1,--r){
        //inv for(N=NN;N>1;N>>=1,r++)
			for(st=0;st<NN;st+=N){
				int i,ss=st+(N>>1);
				for(i=(N>>1)-1;i>=0;--i){
					a=co[st+i]; b=(ps[i<<r]*co[ss+i])%P;
                                //inv b=co[ss+i];
					co[st+i]=a+b; if(co[st+i]>=P)co[st+i]-=P;
					co[ss+i]=a+P-b; if(co[ss+i]>=P)co[ss+i]-=P;
                    //inv co[ss+i]=((a+P-b)*ps[i<<r])%p;
				}
			}
		}
	}
    poly operator*(const poly& _b)const{
		poly a=*this,b=_b;
		int k=n+b.n,i,N=1;
		while(N<=k)N*=2;
		a.co.resize(N,0); b.co.resize(N,0);
		int r=bigmod(root,(P-1)/N),Ni=inv(N,P);
		ps[0]=1;
		for(i=1;i<N;++i)ps[i]=(ps[i-1]*r)%P;
		a.ntt(N);b.ntt(N);
		for(i=0;i<N;++i)a.co[i]=((long long)a.co[i]*b.co[i])%P;
		r=inv(r,P);
		for(i=1;i<N/2;++i)std::swap(ps[i],ps[N-i]);
		a.ntt_inv(N);
		for(i=0;i<N;++i)a.co[i]=((long long)a.co[i]*Ni)%P;
		a.n=n+_b.n; return a;
	}

    poly pow2()const{
		poly a=*this;
		int k=n*2,i,N=1;
		while(N<=k)N*=2;
		a.co.resize(N,0); //b.co.resize(N,0);
		int r=bigmod(root,(P-1)/N),Ni=inv(N,P);
		ps[0]=1;
		for(i=1;i<N;++i)ps[i]=(ps[i-1]*r)%P;
		a.ntt(N);
		for(i=0;i<N;++i)a.co[i]=((long long)a.co[i]*a.co[i])%P;
		r=inv(r,P);
		for(i=1;i<N/2;++i)std::swap(ps[i],ps[N-i]);
		a.ntt_inv(N);
		for(i=0;i<N;++i)a.co[i]=((long long)a.co[i]*Ni)%P;
		a.n=n+n; return a;
	}
};
poly f_pow(poly a,int n,int k){
    poly tmp=a,res(0);
    res.co[0]=1;
    while(n){
        if(n&1){
            res=res*tmp;
            if(res.n>k){
                res.n=k;
                res.co.resize(k+1);
            }
        }
        tmp = tmp.pow2();
        if(tmp.n>k){
            tmp.n=k;
            tmp.co.resize(k+1);
        }
        n>>=1;
    }
    return res;
}
LL fra[200005];
LL invf[200005];
int main(){

    srand(time(NULL));
    int n=rand()%200000+1;
    LL k=rand()%n;
    //printf("%d %lld\n",n,k);
    scanf("%d %lld",&n,&k);
    if(k>=n){
        printf("0\n");
        return 0;
    }
    fra[0]=1;
    for(int i = 1;i<=n;i++){
        fra[i]=fra[i-1]*i%mod;
    }
    invf[n]=f_pow(fra[n],mod-2);
    for(int i = n-1;i>=0;i--){
        invf[i]=invf[i+1]*(i+1)%mod;
    }
    if(k==0){
        printf("%lld\n",fra[n]);
        return 0;
    }
    int less=n-k;
    poly p(n-1);
    for(int i = 0;i<n;i++){
        p.co[i]=invf[i+1];
    }
   // printf("%lld\n",p.co[k]);
    p=f_pow(p,less,k);
    LL ans=p.co[k];
    //printf("%lld\n",ans);
    ans=ans*fra[n]%mod;
    //printf("%lld\n",ans);
    ans=ans*fra[n]%mod*invf[less]%mod*invf[k]%mod*2%mod;
    printf("%lld\n",ans);
}

/*

3 2 +2
3 1 +1
2 1 +1
3 1 +1
2 1 +1

*/
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/