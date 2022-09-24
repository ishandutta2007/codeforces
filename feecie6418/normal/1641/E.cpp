#include<bits/stdc++.h>
const int mod=998244353,g=3,invg=998244354/3;
using namespace std;
typedef vector<int> poly;
int n,m,a[300005],s[300005],pw2[300005]={1},ipw2[300005]={1},A[300005],B[300005],C[300005];
int Power(int x,int y) {
	int ret=1;
	while(y) {
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
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
void Solve1(int l,int r,int dlt){
	if(l==r)return ;
	int mid=(l+r)/2;
	//a:mid+1~r
	//b:l~mid
	vector<int> a,b;
	a.resize(2*(r-mid-1)+1);
	b.resize(mid-l+1);
	for(int i=mid+1;i<=r;i++)a[2*i-2*(mid+1)]=A[i];
	for(int i=l;i<=mid;i++)b[mid-i]=B[i];
	poly c=a*b;
	for(int i=0;i<c.size();i++){
		int pos=i-mid+2*(mid+1);
		pos=max(pos,0);
		C[pos]=(C[pos]+1ll*dlt*c[i])%mod;
	}
	Solve1(l,mid,dlt),Solve1(mid+1,r,dlt);
}
void Solve2(int l,int r,int dlt){
	if(l==r)return ;
	int mid=(l+r)/2;
	//a:mid+1~r
	//b:l~mid
	vector<int> a,b;
	a.resize(2*(mid-l)+1);
	b.resize(mid-l+1);
	for(int i=l;i<=mid;i++)a[2*i-2*l]=A[i];
	for(int i=mid+1;i<=r;i++)b[r-i]=B[i];
	poly c=a*b;
	for(int i=0;i<c.size();i++){
		int pos=i-r+2*l;
		pos=max(pos,0);
		C[pos]=(C[pos]+1ll*dlt*c[i])%mod;
	}
	Solve2(l,mid,dlt),Solve2(mid+1,r,dlt);
}
int main(){
	cin>>n>>m;
	GetG(18);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=300000;i++)pw2[i]=2*pw2[i-1]%mod,ipw2[i]=1ll*ipw2[i-1]*(mod+1)/2%mod;
	for(int i=1,x;i<=m;i++)cin>>x,s[x]=1;
	for(int i=1;i<=300000;i++)s[i]+=s[i-1];
	int ans=0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<i;j++){
//			if(s[j]==s[j-1])continue;
//			ans=(ans+1ll*a[i]*i%mod*pw2[s[j]-1]%mod*ipw2[s[2*i-j]])%mod;
//			ans=(ans-1ll*a[i]*j%mod*pw2[s[j]-1]%mod*ipw2[s[2*i-j]]%mod+mod)%mod;
//		}
//	}
	for(int i=1;i<=n;i++){
		A[i]=1ll*a[i]*i%mod;
		if(s[i]!=s[i-1])B[i]=pw2[s[i]-1];
	}
	Solve1(1,n,1);
	for(int i=1;i<=n;i++){
		A[i]=a[i];
		if(s[i]!=s[i-1])B[i]=1ll*i*pw2[s[i]-1]%mod;
	}
	Solve1(1,n,mod-1);
	for(int i=0;i<=300000;i++){
		ans=(ans+1ll*ipw2[s[i]]*C[i])%mod;
		C[i]=0;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			if(s[j]==s[j-1])continue;
//			ans=(ans+1ll*a[i]*j%mod*pw2[s[max(2*i-j,0)]]%mod*ipw2[s[j]])%mod;
//			ans=(ans-1ll*a[i]*i%mod*pw2[s[max(2*i-j,0)]]%mod*ipw2[s[j]]%mod+mod)%mod;
//		}
//	}
	for(int i=1;i<=n;i++){
		A[i]=1ll*a[i]*i%mod;
		if(s[i]!=s[i-1])B[i]=ipw2[s[i]];
	}
	Solve2(1,n,mod-1);
	for(int i=1;i<=n;i++){
		A[i]=a[i];
		if(s[i]!=s[i-1])B[i]=1ll*i*ipw2[s[i]]%mod;
	}
	Solve2(1,n,1);
	for(int i=0;i<=300000;i++){
		ans=(ans+1ll*pw2[s[i]]*C[i])%mod;
		C[i]=0;
	}
	cout<<1ll*ans*pw2[m]%mod*Power(pw2[m]-1,mod-2)%mod;
}