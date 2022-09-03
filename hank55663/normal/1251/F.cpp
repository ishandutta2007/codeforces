
#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define pii pair<int,int>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int mod=998244353,root=3,MAXNUM=1<<23;
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
	return (bigmod((a*a)%mod,b/2)*(b%2?a:1ll))%mod;
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
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
struct poly{
	std::vector<unsigned int> co;
	int n;//polynomial degree = n
	poly(int d){n=d;}
    poly(){}
	void ntt_inv(int NN){
		int r=0,st,N;
		unsigned int a,b;
		while((1<<r)<(NN>>1))++r;//inv:r=0
		for(N=2;N<=NN;N<<=1,--r){
        //inv for(N=NN;N>1;N>>=1,r++)
			for(st=0;st<NN;st+=N){
				int i,ss=st+(N>>1);
				for(i=(N>>1)-1;i>=0;--i){
					a=co[st+i]; b=(ps[i<<r]*co[ss+i])%mod;
                                //inv b=co[ss+i];
					co[st+i]=a+b; if(co[st+i]>=mod)co[st+i]-=mod;
					co[ss+i]=a+mod-b; if(co[ss+i]>=mod)co[ss+i]-=mod;
                    //inv co[ss+i]=((a+P-b)*ps[i<<r])%p;
				}
			}
		}
	}
	void ntt(int NN){
        int r=0,st,N;
		unsigned int a,b;
		r=0;
        for(N=NN;N>1;N>>=1,r++){
			for(st=0;st<NN;st+=N){
				int i,ss=st+(N>>1);
				for(i=(N>>1)-1;i>=0;--i){
					a=co[st+i]; //b=(ps[i<<r]*co[ss+i])%P;
                                b=co[ss+i];
					co[st+i]=a+b; if(co[st+i]>=mod)co[st+i]-=mod;
					co[ss+i]=((a+mod-b)*ps[i<<r])%mod; if(co[ss+i]>=mod)co[ss+i]-=mod;
                    
				}
			}
		}
	}
};
poly operator*(const poly &_a,const poly& _b){
    poly a=_a,b=_b;
    int k=_a.n+b.n,i,N=1;
    while(N<=k)N*=2;
    a.co.resize(N,0); b.co.resize(N,0);
    int r=bigmod(root,(mod-1)/N),Ni=inv(N,mod);
    ps[0]=1;
    for(i=1;i<N;++i)ps[i]=(ps[i-1]*r)%mod;
    a.ntt(N);b.ntt(N);
    for(i=0;i<N;++i)a.co[i]=((long long)a.co[i]*b.co[i])%mod;
    r=inv(r,mod);
    for(i=1;i<N/2;++i)std::swap(ps[i],ps[N-i]);
    a.ntt_inv(N);
    for(i=0;i<N;++i)a.co[i]=((long long)a.co[i]*Ni)%mod;
    a.n=_a.n+_b.n;
    a.co.resize(a.n+1);
    return a;
}
LL fra[300005];
LL INV[300005];
void build(){
    fra[0]=1;
    for(int i = 1;i<300005;i++)
        fra[i]=fra[i-1]*(i)%mod;
    INV[300000]=f_pow(fra[300000],mod-2);
    for(int i = 299999;i>=0;i--)
        INV[i]=INV[i+1]*(i+1)%mod;
}
LL C(int a,int b){
    return fra[a]*INV[b]%mod*INV[a-b]%mod;
}
int main(){
    build();
    int n,k;
    scanf("%d %d",&n,&k);
    int a[300005],b[5];
    map<int,int> m;
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]),m[a[i]]++;
    for(int i = 0;i<k;i++)
        scanf("%d",&b[i]);
    poly ans[5];
    MEM(ans);
    //fill(ans,ans+6000005,0);
    for(int i = 0;i<k;i++){
        int tot1=0,tot2=0;
        for(auto it:m){
            if(it.x>=b[i])break;
            if(it.y==1)tot1++;
            else tot2++;
        }
        poly p1(tot1),p2(tot2*2);
        //p1.n=tot1,p2.n=tot2*2;
        for(int j=0;j<=tot1;j++){
            p1.co.pb(C(tot1,j)*f_pow(2,j)%mod);
        }
        for(int j=0;j<=tot2*2;j++){
            p2.co.pb(C(tot2*2,j));
        }
       /* for(auto it:p1.co){
            printf("%d ",it);
        }
        printf("\n");
        for(auto it:p2.co){
            printf("%d ",it);
        }
        printf("\n");*/
        ans[i]=p1*p2;
        /*for(auto it:ans[i].co){
            printf("%d ",it);
        }
        printf("\n");*/
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        x/=2;
        LL res=0;
        for(int i=0;i<k;i++){
            if(x>b[i]&&x-b[i]-1<=ans[i].n){
                res+=ans[i].co[x-b[i]-1];
               // printf("%d %d ",ans[i].co[x-b[i]-1],x-b[i]-1);
            }
        }
        printf("%lld\n",res%mod);
    }
}