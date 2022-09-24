#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> poly;
const int mod=998244353,g=3,invg=(mod+1)/3;
namespace ECSY {
    int w,mod;
    struct Complex {
        int a,b;
        Complex(int aa=1,int bb=0){a=aa,b=bb;}
        Complex operator *(const Complex yy) const {
            return Complex((1ll*a*yy.a+1ll*b*yy.b%mod*w)%mod,(1ll*a*yy.b+1ll*b*yy.a)%mod);
        }
    };
    int Power(int x,int y,int mod){
        int ret=1;
        while(y) {
            if(y&1)ret=1ll*ret*x%mod;
            x=1ll*x*x%mod,y>>=1;
        }
        return ret;
    }
    Complex Power(Complex x,int y){
        Complex ret;
        while(y) {
            if(y&1)ret=ret*x;
            x=x*x,y>>=1;
        }
        return ret;
    }
    int Cipolla(int n,int p){
        if(!n)return 0;
        if(Power(n,(p-1)/2,p)==p-1)return -1;
        int a;
        do a=1ll*rand()*rand()%p; while(Power((1ll*a*a-n+p)%p,(p-1)/2,p)!=p-1);
        w=(1ll*a*a-n+p)%p,mod=p;
        return Power(Complex(a,1),(p+1)/2).a;
    }
};
int Power(int x,int y){
    int r=1;
    while(y){
        if(y&1)r=1ll*r*x%mod;
        y>>=1,x=1ll*x*x%mod;
    }
    return r;
}
int ta[300005],tb[300005],tr[300005],wk[20][300005],wk2[20][300005],inv[300005];
void GetTr(int l){
    for(int i=0;i<l;i++)tr[i]=((tr[i>>1]>>1)|(i%2?(l>>1):0));
}
void GetG(int lim){
    for(int i=1;i<=lim;i++){
        int w=Power(g,(mod-1)/(1<<i));
        for(int j=0,u=1;j<(1<<i-1);j++,u=1ll*u*w%mod)wk[i][j]=u;
        w=Power(invg,(mod-1)/(1<<i));
        for(int j=0,u=1;j<(1<<i-1);j++,u=1ll*u*w%mod)wk2[i][j]=u;
    }
    inv[1]=1;
    for(int i=2;i<(1<<lim);i++)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
}
int Add(int x,int y){
    x+=y;
    if(x>=mod)x-=mod;
    return x;
}
int Del(int x,int y){
    x-=y;
    if(x<0)x+=mod;
    return x;
}
void NTT(int *a,int n,int flag){
    for(int i=0;i<n;i++)if(i<tr[i])swap(a[i],a[tr[i]]);
    for(int i=1,t=1;i<n;i<<=1,t++){
        for(int j=0;j<n;j+=(i<<1)){
            for(int k=0;k<i;k++){
                int x=a[j+k],y;
                if(flag==1)y=1ll*a[i+j+k]*wk[t][k]%mod;
                else y=1ll*a[i+j+k]*wk2[t][k]%mod;
                a[j+k]=Add(x,y),a[i+j+k]=Del(x,y);
            }
        }
    }
    if(flag==-1)for(int i=0,u=Power(n,mod-2);i<n;i++)a[i]=1ll*a[i]*u%mod;
}
poly operator *(const poly &a,const poly &b){
    int sa=a.size(),sb=b.size(),sr=sa+sb-1;
    poly ret(sr);
    if(sr<70){
        for(int i=0;i<sa;i++)for(int j=0;j<sb;j++)ret[i+j]=(ret[i+j]+1ll*a[i]*b[j])%mod;
        return ret;
    }
    int len=1;
    while(len<sr)len<<=1;
    GetTr(len);
    for(int i=0;i<len;i++)ta[i]=tb[i]=0;
    for(int i=0;i<sa;i++)ta[i]=a[i];
    for(int i=0;i<sb;i++)tb[i]=b[i];
    NTT(ta,len,1),NTT(tb,len,1);
    for(int i=0;i<len;i++)ta[i]=1ll*ta[i]*tb[i]%mod;
    NTT(ta,len,-1);
    for(int i=0;i<sr;i++)ret[i]=ta[i];
    return ret;
}
poly operator +(poly a,poly b){
    int sa=a.size(),sb=b.size(),sr=max(sa,sb);
    a.resize(sr);
    for(int i=0;i<sr;i++)if(i<sb)a[i]=Add(a[i],b[i]);
    return a;
}
poly operator -(poly a,poly b){
    int sa=a.size(),sb=b.size(),sr=max(sa,sb);
    a.resize(sr);
    for(int i=0;i<sr;i++)if(i<sb)a[i]=Del(a[i],b[i]);
    return a;
}
poly operator +(poly a,int b){
    if(!a.size())a.resize(1);
    a[0]=(a[0]+b)%mod;
    return a;
}
poly operator +(int b,poly a){
    if(!a.size())a.resize(1);
    a[0]=(a[0]+b)%mod;
    return a;
}
poly operator -(poly a,int b){
    if(!a.size())a.resize(1);
    a[0]=(a[0]-b+mod)%mod;
    return a;
}
poly operator -(int b,poly a){
    if(!a.size())a.resize(1);
    a[0]=(b-a[0]+mod)%mod;
    for(int i=1;i<a.size();i++)a[i]=(mod-a[i])%mod;
    return a;
}
poly operator *(poly a,int k){
    for(int i=0,sa=a.size();i<sa;i++)a[i]=1ll*a[i]*k%mod;
    return a;
}
poly operator *(int k,poly a){
    for(int i=0,sa=a.size();i<sa;i++)a[i]=1ll*a[i]*k%mod;
    return a;
}
poly Inv(poly a){
    poly ret(1),t,t2;
    assert(a[0]),ret[0]=Power(a[0],mod-2);
    for(int l=1;l<a.size();l<<=1)t2=a,t2.resize(l<<1),t=t2*ret,t.resize(l<<1),t=t*ret,t.resize(l<<1),ret=ret*2-t;
    return ret.resize(a.size()),ret;
}
poly Der(poly a){// 
    int sa=a.size();
    for(int i=0;i<sa-1;i++)a[i]=1ll*a[i+1]*(i+1)%mod;
    return a.pop_back(),a;
}
poly Int(poly a){// 
    int sa=a.size();
    a.push_back(0);
    for(int i=sa;i;i--)a[i]=1ll*a[i-1]*inv[i]%mod;
    return a[0]=0,a;
}
poly Ln(poly a){
    int t=a.size();
    assert(a[0]==1);
    return a=Int(Inv(a)*Der(a)),a.resize(t),a;
}
poly Exp(poly a){
    poly ret(1),t,t2;
    assert(a[0]==0),ret[0]=1;
    for(int l=1;l<a.size();l<<=1)t=a,t.resize(l<<1),ret.resize(l<<1),t=ret*(Ln(ret)-t),t.resize(l<<1),ret=ret-t;
    return ret.resize(a.size()),ret;
}
poly operator /(poly a,poly b){
    int n=a.size()-1,m=b.size()-1;
    if(n<m)return vector<int>{0};
    reverse(a.begin(),a.end()),reverse(b.begin(),b.end());
    poly inv,s;
    b.resize(n-m+1),inv=Inv(b);
    s=a*inv,s.resize(n-m+1),reverse(s.begin(),s.end());
    return s;
}
poly operator %(poly a,poly b){
    int m=b.size()-1;
    poly t;
    t=a-(a/b)*b,t.resize(min((int)t.size(),m));
    return t;
}
poly Sqrt(poly a){
    int x=ECSY::Cipolla(a[0],mod),inv=Power(a[0],mod-2);
    assert(x!=-1),a=a*inv,a=Exp(Ln(a)*((mod+1)/2)),a=a*min(x,mod-x);
    return a;
}
int n,m;
int main(){
    GetG(18);
    cin>>n>>m;
    if(n%2==0){
		poly f(n+5);
		f[0]=1;
		for(int i=2;i<=n;i+=2){
			f[i]=1ll*f[i-2]*(m+i/2)%mod*(m-i/2+1)%mod;
			f[i]=1ll*f[i]*Power(i,mod-2)%mod*Power(i-1,mod-2)%mod;
		}
		f[0]=0;
		for(int i=2;i<=n;i+=2)if((i/2)%2==0)f[i]=(mod-f[i])%mod;
    	poly g(n+5);
		for(int i=2;i<=n;i+=2)g[i]=1ll*f[i]*(i/2)%mod;
		cout<<(g*(Inv(1-f)))[n]<<'\n';
		return 0;
	}
	poly h(n+5);
	int m0=m/2;
	poly f(n+5);
	f[0]=1;
	for(int i=2;i<=n;i+=2){
		f[i]=1ll*f[i-2]*(m0+i/2)%mod*(m0-i/2+1)%mod;
		f[i]=1ll*f[i]*Power(i,mod-2)%mod*Power(i-1,mod-2)%mod;
	}
	f[0]=0;
	for(int i=2;i<=n;i+=2)if((i/2)%2==0)f[i]=(mod-f[i])%mod;
	h[1]=m0;
	for(int i=3;i<=n;i+=2){
		h[i]=1ll*h[i-2]*Power(i,mod-2)%mod*Power(i-1,mod-2)%mod;
		h[i]=1ll*h[i]*(m0+i/2)%mod*(m0-i/2)%mod;
	}
	for(int i=1;i<=n;i+=2)if((i/2)%2==1)h[i]=(mod-h[i])%mod;
	h=h*Inv(1-f);
	while(h.size()>n+5)h.pop_back();
	if(m&1)h[1]=(h[1]+1)%mod;
	poly t=h;
	for(int i=1;i<=n;i+=2)t[i]=1ll*t[i]*i%mod;
	cout<<(t*Inv(1-h))[n];
}