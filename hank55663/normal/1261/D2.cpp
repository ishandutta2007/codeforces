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
#define MXN 200005
int P=998244353,root=3,MAXNUM=1<<23;
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
	void ntt(int NN){
        int r=0,st,N;
		unsigned int a,b;
		r=0;
		//for(N=2;N<=NN;N<<=1,--r){
        for(N=NN;N>1;N>>=1,r++){
			for(st=0;st<NN;st+=N){
				int i,ss=st+(N>>1);
				for(i=(N>>1)-1;i>=0;--i){
					a=co[st+i]; b=(ps[i<<r]*co[ss+i])%P;
                                //inv b=co[ss+i];
					co[st+i]=a+b; if(co[st+i]>=P)co[st+i]-=P;
					//co[ss+i]=a+P-b; if(co[ss+i]>=P)co[ss+i]-=P;
                    co[ss+i]=((a+P-b)*ps[i<<r])%P;
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
    LL f_pow(LL a,LL b){
        LL res=1,temp=a;
        while(b){
            if(b&1)res=res*temp%P;
            temp=temp*temp%P;
            b>>=1;
        }
        return res;
    }
    poly f_pow(int kk){
        poly a=*this;
        int k=n*kk,i,N=1;
        while(N<=k)N*=2;
        a.co.resize(N,0);
		int r=bigmod(root,(P-1)/N),Ni=inv(N,P);
		ps[0]=1;
		for(i=1;i<N;++i)ps[i]=(ps[i-1]*r)%P;
		a.ntt(N);
		for(i=0;i<N;++i)a.co[i]=f_pow(a.co[i],kk);//((long long)a.co[i]*b.co[i])%P;
		r=inv(r,P);
		for(i=1;i<N/2;++i)std::swap(ps[i],ps[N-i]);
		a.ntt_inv(N);
		for(i=0;i<N;++i)a.co[i]=((long long)a.co[i]*Ni)%P;
		a.n=n*kk; return a;
    }
};
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int h[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&h[i]);
    }
    int cnt=0;
    LL ans=1;
    for(int i = 0;i<n;i++){
        if(h[i]!=h[(i+1)%n])cnt++;
        else{
            ans=ans*k%P;
        }
    }
    poly a(2);
    a.co[0]=1;
    a.co[2]=1;
    a.co[1]=k-2;
    a=a.f_pow(cnt);
    
    /*printf("%d %d\n",cnt,a.n);
    for(auto it:a.co){
        printf("%d ",it);
    }*/
    LL sum=0;
    for(int i = cnt+1;i<=2*cnt;i++){
        sum+=a.co[i];
        sum%=P;
    }
    printf("%lld\n",ans*sum%P);
}
/*
9 4 
1 0 1 0 1 0 0 1 1
1 2
2 4
2 3
4 5
1 6
6 7
6 8
7 9

*/