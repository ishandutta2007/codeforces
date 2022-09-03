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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL fra[200005];
LL inv[200005];
const int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL ans[200005];
int mobi[200005];
int prime[200005];
int P=998244353,root=3,MAXNUM=1<<23;
// Remember coefficient are mod P
/*
p=a*2^n+1 degree(poly) <= 2^n
n		2^n 				p 					a 		root
16  	65536 			    65537 				1 		3
20 	    1048576		 	    7340033 			7 		3
23                          998244353           119     3          
*/
    std::vector<long long> ps(MAXNUM);
    std::vector<int> rev(MAXNUM);
        int bigmod(long long a,int b){
        if(b==0)return 1;
            return (bigmod((a*a)%P,b/2)*(b%2?a:1ll))%P;
    }
struct poly{

    static int inv(int a,int b){
        if(a==1)return 1;
        return (((long long)(a-inv(b%a,a))*b+1)/a)%b;
    }

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
					a=co[st+i];// b=(ps[i<<r]*co[ss+i])%P;
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
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(k==1){
        printf("1\n");
        return;
    }
    fra[0]=1;
    for(int i = 1;i<=200000;i++){
        fra[i]=fra[i-1]*i%mod;
    }
    inv[200000]=f_pow(fra[200000],mod-2);
    for(int i = 199999;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    MEMS(ans);
    fill(mobi,mobi+n+1,1);
    fill(prime,prime+n+1,1);
    for(int i = 2;i<=n;i++){
        if(prime[i]){
            for(int j = i;j<=n;j+=i){
                prime[j]=0;
                mobi[j]*=-1;
                if(j/i%i==0)mobi[j]=0;
            }
        }
    }
    LL res=0;
    for(int i = n;i>=1;i--){
        if(ans[(n-1)/i+1]==-1){
         //   printf("%d\n",(n-1)/i+1);
            int t=min(k,(n+i-1)/i);
            LL val[200005];
            val[0]=0;
            val[1]=1;
           // ans[(n-1)/i+1]=f_pow(t,(n+i-1)/i);
            val[1]=1;
            for(int j = 2;j<=t;j++){
                val[j]=f_pow(j,(n+i-1)/i);
            }
            poly p1(t),p2(t);
            for(int j = 0;j<=t;j++){
                p1.co[j]=(val[j]*inv[j])%mod;
                if(j&1)
                p2.co[j]=mod-inv[j];
                else p2.co[j]=inv[j];
            }
            p2.co[0]=0;
           // for(auto it:p1.co)printf("%d ",it);
           // printf("\n");
          //  for(auto it:p2.co)printf("%d ",it);
           // printf("\n");
            p1=p1*p2;
         //  for(auto it:p1.co)printf("%d ",it);
           // printf("\n");
            ans[(n-1)/i+1]=0;
            for(int j = 1;j<=t;j++){
                // printf("%lld %lld %lld ",val[j],fra[j],p1.co[j]);
                val[j]=val[j]+fra[j]*p1.co[j];
                val[j]%=mod;
                val[j]+=mod;
                val[j]%=mod;
                val[j]=val[j]*inv[j]%mod;
                ans[(n-1)/i+1]+=val[j];
              //  printf("%lld ",val[j]);
            }
           // printf("?\n");
               /* ans[(n-1)/i+1]+=(f_pow(j,(n+i-1)/i)-f_pow(j-1,(n+i-1)/i)*j)%mod*inv[j]%mod;
                
                ans[(n-1)/i+1]%=mod;
                ans[(n-1)/i+1]+=mod;
                ans[(n-1)/i+1]%=mod;
                printf("%d %lld %lld\n",(n-1)/i+1,ans[(n-1)/i+1],(f_pow(j,(n+i-1)/i)-f_pow(j-1,(n+i-1)/i)*j)%mod);
               //  printf("! %d %lld\n",n/i,ans[n/i]);
            }*/
              //printf("%d %lld\n",(n-1)/i+1,ans[(n-1)/i+1]);
            for(int j=2;j<=(n+i-1)/i;j++){
             ans[(n-1)/i+1]-= ans[(((n-1)/i+1)+j-1)/j];
            // printf("%lld?\n",ans[(n-1)/i+1],((n-1)/i+1))
             ans[(n-1)/i+1]%=mod;
             ans[(n-1)/i+1]+=mod;
             ans[(n-1)/i+1]%=mod;
            }
        }
      //  printf("%d %lld\n",(n-1)/i+1,ans[(n-1)/i+1]);
        /*if(i==1)
        res+=ans[(n-1)/i+1];//*mobi[i]%mod;
        else
        res-=ans[(n-1)/i+1];
        res=(res%mod+mod)%mod;*/
    }
    printf("%lld\n",ans[n]);
}
int main(){
    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}