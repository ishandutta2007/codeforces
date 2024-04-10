#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define double long double
using namespace std;
int P=998244353,root=3,MAXNUM=1<<23;
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
};
const int mod=998244353;
void solve(){
    int n,k,f;
    scanf("%d %d %d",&n,&k,&f);
    if(f>k*2){
        printf("0\n");
        return;
    }
    poly p(k);
    for(int i=0;i<=k;i++)p.co[i]=1;
    for(int i = 2;i<=n;i++){
         //       for(int i = 0;i<=k;i++)printf("%d ",p.co[i]);
        //printf("\n");
        p=p*p;
        //for(int i = 0;i<=2*k;i++)printf("%d ",p.co[i]);
        //printf("\n");
        LL sum=0;
        poly q(k);
        for(int i = 2*k;i>=0;i--){
           
            sum%=mod;
            if(i<=k){
                q.co[i]=(sum+p.co[i]*1ll*(k-i+1))%mod;
            } sum=sum+p.co[i];sum%=mod;
        }
        p=q;
    }
    p=p*p;
    printf("%d\n",p.co[f]);
}
int main(){
    int t=1;000;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/