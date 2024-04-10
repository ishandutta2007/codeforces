#include<bits/stdc++.h>
#define Low(x) pow(2,(int)(log(x-0.1)/log(2))+1)
using namespace std;

typedef long long ll;
const int mod=998244353,o=3;
int mi(int x,int t){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}
int ni(int x) {return mi(x,mod-2);}
 
int mymax(int x,int y) {return (x>y?x:y);}
 
inline void add(int &x){
	x+=(x>>31)&mod;
}
 
namespace polynomial{
	vector<int> g,O(1);
	struct poly{
		vector<int> a;
		void DFT(int len,int ty){
			a.resize(len);
			if(g.size()<len){
				g.resize(len);
				while(O.size()<=len){
					int one=mi(o,(mod-1)/O.size());
					int t=O.size(),tt=1;
					for(int j=0;j<t;j++){
						O.push_back(tt);
						tt=(ll)tt*one%mod;
					}
				}
			}
			if(ty) for(int i=1;i<len/2;i++) swap(a[i],a[len-i]);
			for(int i=0;i<len;i++){
				g[i]=g[i/2]/2+(len/2)*(i&1);
				if(i<g[i]) swap(a[i],a[g[i]]);
			}
			
			int *b=a.data(),*st=O.data();
			for(int i=2;i<=len;i*=2){
				for(int *j=b;j!=b+len;j+=i){
					for(int *t2=j,*t3=j+i/2,*t=st+i;t2!=j+i/2;t2++,t3++,t++){
						int tmp=(ll)*t3**t%mod;
						add(*t3=*t2-tmp);
						add(*t2+=tmp-mod);
					}
				}
			}
			if(ty){
				int Nlen=ni(len);
				for(int i=0;i<len;i++) a[i]=(ll)a[i]*Nlen%mod;
			}
		}
	};
	
	poly operator + (poly A,poly B){
		int len=mymax(A.a.size(),B.a.size());
		A.a.resize(len);B.a.resize(len);
		for(int i=0;i<len;i++) A.a[i]=(A.a[i]+B.a[i])%mod;
		return A;
	}
	
	poly operator * (poly A,poly B){
		int len=Low(A.a.size()+B.a.size()-1);
		A.DFT(len,0);B.DFT(len,0);
		for(int i=0;i<len;i++) A.a[i]=(ll)A.a[i]*B.a[i]%mod;
		A.DFT(len,1);
		return A;
	}
}
using namespace polynomial;

const int N=2e5+100,maxn=2e5;
int fl[N],nf[N],Ans[N];

int main()
{
	
	fl[0]=1;for(int i=1;i<=maxn;i++) fl[i]=(ll)fl[i-1]*i%mod;
	nf[maxn]=ni(fl[maxn]);for(int i=maxn-1;i>=0;i--) nf[i]=(ll)nf[i+1]*(i+1)%mod;
	
	int n;
	scanf("%d",&n);
	
	poly A,B;A.a.resize(n+1);B.a.resize(n);
	for(int i=0;i<=n;i++) A.a[i]=nf[n-i];
	for(int i=0;i<=n-1-(n+1)/2;i++) B.a[i]=(ll)fl[i]*ni(n-1-i)%mod;
	
	A=A*B;
	for(int i=1;i<=n;i++) Ans[i]=(ll)A.a[i+n-1]*fl[n-i]%mod;
	
	A.a.resize(0);B.a.resize(0);
	A.a.resize(n+1);B.a.resize(n);
	for(int i=(n+1)/2;i<n;i++) A.a[i]=fl[i-1];
	for(int i=0;i<n;i++) B.a[i]=nf[n-1-i];
	
	A=A*B;
	for(int i=1;i<=n;i++) Ans[i]=(Ans[i]+(ll)A.a[i+n-2]*fl[n-i]%mod*(i-1))%mod;
	
	for(int i=1;i<=n;i++) printf("%d ",(fl[n-1]-Ans[i]+mod)%mod);
	printf("\n");
	
	return 0;
}