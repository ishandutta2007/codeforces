#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define G 3
#define GI 332748118
#define I 911660635
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
namespace Sqrt
{
	int mul;
	struct Complex
	{
		int a,b;Complex(int x,int y){a=x,b=y;}
		friend Complex operator*(Complex a,Complex b){return Complex((1ll*a.a*b.a+1ll*a.b*b.b%P*mul)%P,(1ll*a.a*b.b+1ll*a.b*b.a)%P);}
	};
	Complex Pow(Complex a,int b){Complex ans(1,0);while(b)(b&1)&&(ans=ans*a,0),a=a*a,b>>=1;return ans;}
	int sqrt(int x){int a=rand()%P;while(pow((1ll*a*a-x+P)%P,P-1>>1)==1)a=rand()%P;mul=(1ll*a*a-x+P)%P;Complex y={a,1};int ans=Pow(y,P+1>>1).a;return min(ans,P-ans);}
}
using Sqrt::sqrt;
struct poly
{
	int N,K;vector<int>a;poly(){N=K=0;a.clear();}poly(int x){N=K=1;a.resize(1);a[0]=x;}poly(int M,vector<int>x){N=M;K=1;while(K<N)K<<=1;a=x;a.resize(K);}
	void NTT(int opt)
	{
		vector<int>r(K);For(i,0,K-1)r[i]=(r[i>>1]>>1)|((i&1)*(K>>1));For(i,0,K-1)if(i<r[i])swap(a[i],a[r[i]]);
		for(int i=2;i<=K;i<<=1){int W=pow(opt==1?G:GI,(P-1)/i);for(int j=0;j<K;j+=i){int w=1;For(k,0,(i>>1)-1){int x=a[j+k],y=1ll*w*a[j+k+(i>>1)]%P;a[j+k]=(x+y)%P;a[j+k+(i>>1)]=(x-y+P)%P;w=1ll*w*W%P;}}}
		if(opt==-1){int x=pow(K,P-2);For(i,0,K-1)a[i]=1ll*a[i]*x%P;}
	}
	poly ChangeLength(int x){poly ans;ans.N=x;ans.K=1;while(ans.K<x)ans.K<<=1;ans.a=a;ans.a.resize(ans.K);For(i,min(N,x),ans.K-1)ans[i]=0;return ans;}
	int&operator[](int x){return a[x];}
	friend poly operator+(poly a,poly b){a.N=max(a.N,b.N);a.K=max(a.K,b.K);a.a.resize(a.K);b.a.resize(a.K);For(i,0,a.N-1)a[i]=(a[i]+b[i])%P;return a;}
	friend poly operator+(poly a,int b){a[0]=(a[0]+b)%P;return a;}
	friend poly operator-(poly a){For(i,0,a.N-1)a[i]=(P-a[i])%P;return a;}
	friend poly operator-(poly a,poly b){return a+(-b);}
	friend poly operator-(poly a,int b){return a+(P-b);}
	friend poly operator*(poly a,poly b){int L=a.N+b.N-1;a=a.ChangeLength(L);b=b.ChangeLength(L);a.NTT(1);b.NTT(1);For(i,0,a.K-1)a[i]=1ll*a[i]*b[i]%P;a.NTT(-1);return a;}
	friend poly operator*(poly a,int b){For(i,0,a.N-1)a[i]=1ll*a[i]*b%P;return a;}
	friend pair<poly,poly>operator/(poly a,poly b){a=a.Reduce();b=b.Reduce();if(a.N<b.N)return {poly(0),a};poly c=(a.Reverse()*b.Reverse().ChangeLength(a.N-b.N+1).Inv()).ChangeLength(a.N-b.N+1).Reverse(),d=(a-b*c).ChangeLength(b.N-1);return {c,d};}
	friend poly operator/(poly a,int b){return a*pow(b,P-2);}
	friend poly operator<<(poly a,int b){poly c(a.N+b,vector<int>(0));For(i,b,a.N+b-1)c[i]=a[i-b];return c;}
	poly Reduce(){int x=N;while(x>1&&!a[x-1])x--;return ChangeLength(x);}
	poly Reverse(){poly ans;ans.N=N;ans.K=K;ans.a.resize(K);For(i,0,N-1)ans[i]=a[N-1-i];return ans;}
	poly MulT(poly b){if(b.N>N)b=b.ChangeLength(N);return (Reverse()*b).ChangeLength(N).Reverse();}
	poly Inv()
	{
		if(N==1)return poly(pow(a[0],P-2));
		poly tmp=ChangeLength(N+1>>1).Inv();return (tmp*2-tmp*tmp*(*this)).ChangeLength(N);
	}
	poly Sqrt()
	{
		if(N==1)return sqrt(a[0]);
		poly tmp=ChangeLength(N+1>>1).Sqrt();return ((tmp+(*this)*tmp.ChangeLength(N).Inv())/2).ChangeLength(N);
	}
	poly Delta(){poly ans;ans.N=N;ans.K=K;ans.a.resize(ans.K);For(i,0,N-2)ans[i]=1ll*(i+1)*a[i+1]%P;return ans;}
	poly Sum(){poly ans;ans.N=N;ans.K=K;ans.a.resize(ans.K);For(i,1,N-1)ans[i]=1ll*pow(i,P-2)*a[i-1]%P;return ans;}
	poly Ln(){return (Delta()*Inv()).ChangeLength(N).Sum().ChangeLength(N);}
	poly Exp()
	{
		if(N==1)return poly(1);
		poly tmp=ChangeLength(N+1>>1).Exp();return (tmp*(poly(1)-tmp.ChangeLength(N).Ln()+*this)).ChangeLength(N);
	}
	poly Pow(int x){return (Ln()*x).Exp();}
	poly Cos(){return (((*this)*I).Exp()+((*this)*(P-I)).Exp())/2;}
	poly Sin(){return (((*this)*I).Exp()-((*this)*(P-I)).Exp())/2/I;}
	void Print(){For(i,0,N-1)cout<<a[i]<<" \n"[i==N-1];}
};
struct Getval
{
	int M,K;poly f;vector<int>Point;vector<poly>mul;Getval(poly a,vector<int>point){f=a;M=point.size();Point=point;}
	int GetMxnode(int node,int l,int r){if(l==r)return node;int mid=l+r>>1;return max(GetMxnode(node<<1,l,mid),GetMxnode(node<<1|1,mid+1,r));}
	poly GetvalPre(int node,int l,int r){if(l==r)return mul[node]=poly(2,vector<int>{1,(P-Point[l])%P});int mid=l+r>>1;return mul[node]=GetvalPre(node<<1,l,mid)*GetvalPre(node<<1|1,mid+1,r);}
	void GetvalWork(poly f,int node,int l,int r,vector<int>&ans){if(l>=M)return;f=f.ChangeLength(r-l+1);if(l==r){ans[l]=f[0];return;}int mid=l+r>>1;GetvalWork(f.MulT(mul[node<<1|1]),node<<1,l,mid,ans);GetvalWork(f.MulT(mul[node<<1]),node<<1|1,mid+1,r,ans);}
	vector<int>GetVal(){K=max(M,f.N);f=f.ChangeLength(K);Point.resize(K);mul.resize(GetMxnode(1,0,K-1)+1);mul[1]=GetvalPre(1,0,K-1);vector<int>ans(M);GetvalWork(f.MulT(mul[1].ChangeLength(K).Inv()),1,0,K-1,ans);return ans;}
};
struct Getpoly
{
	int N;vector<int>x,y,val;Getpoly(int M,vector<int>a,vector<int>b){N=M;x=a;y=b;}
	poly GetpolyPre(int l,int r){if(l==r)return poly(2,vector<int>{P-x[l],1});int mid=l+r>>1;return GetpolyPre(l,mid)*GetpolyPre(mid+1,r);}
	poly GetpolyWork(int l,int r,poly&mul){if(l==r)return mul=poly(2,vector<int>{P-x[l],1}),poly(1ll*y[l]*pow(val[l],P-2)%P);int mid=l+r>>1;poly a,b;poly c=GetpolyWork(l,mid,a),d=GetpolyWork(mid+1,r,b);return mul=a*b,b*c+a*d;}
	poly GetPoly(){poly g=GetpolyPre(0,N-1);val=Getval(g.Delta(),x).GetVal();return GetpolyWork(0,N-1,g);}
};
int N,K;
struct mat
{
	poly a[3][3];mat(){a[1][1]=a[1][2]=a[2][1]=a[2][2]=0;}poly*operator[](int x){return a[x];}
	mat operator*(mat b){mat ans;For(i,1,2)For(j,1,2)For(k,1,2)ans[i][j]=ans[i][j]+(a[i][k]*b[k][j]).ChangeLength(K+1);return ans;}
}base;
mat pow(mat a,int b){mat ans;ans[1][1]=ans[2][2]=poly(1);while(b)(b&1)&&(ans=ans*a,0),a=a*a,b>>=1;return ans;}
int main(){cin>>N>>K;base[1][1]=poly(2,vector<int>{1,1});base[1][2]=poly(2,vector<int>{0,1});base[2][1]=poly(1);poly ans=pow(base,N)[1][1];For(i,1,K)cout<<ans[i]<<" \n"[i==K];return 0;}