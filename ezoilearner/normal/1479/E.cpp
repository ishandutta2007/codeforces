#include<bits/stdc++.h>
using namespace std;
#define rez resize
const int Mod=998244353;
const int D2=998244351;
typedef vector<int> poly;

namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
	int Fast_Pow(int a,int b){
		int res=1;
		while(b){
			if(b&1)res=1ll*res*a%Mod;
			a=1ll*a*a%Mod;
			b>>=1;
		}
		return res;
	}
}using namespace modular;

#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n,m,S,B;
#define Maxn 40010 
#define cout cerr
int a[Maxn];
int val[Maxn],vali[Maxn];

int invv[24],len,bit,inv[1<<16|5];
vector<int> rev[24],w[24];
inline void init_w(int lm=1<<15){
    w[14].rez(1<<14);w[14][0]=1;w[14][1]=Fast_Pow(3,(Mod-1)/lm);
    for(int i=2;i<lm/2;++i)
        w[14][i]=1ll*w[14][i-1]*w[14][1]%Mod;
    for(int i=13;i>=0;--i){
        w[i].rez(1<<i);
        for(int j=0;j<(1<<i);++j)w[i][j]=w[i+1][j<<1];
    }
    inv[0]=inv[1]=1;
    for(int i=2;i<=lm;++i)inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
}

int fact[Maxn],ifac[Maxn];
void init(){
	fact[0]=1;
	rep(i,1,S)fact[i]=mul(fact[i-1],i);
	ifac[0]=1;
	rep(i,1,S)ifac[i]=mul(ifac[i-1],inv[i]);
}

void init_r(int up){
	len=1;bit=0;
	while(len<up)len<<=1,bit++;
	if(invv[bit])return;
	rev[bit].rez(len);
	for(int i=0;i<len;++i)rev[bit][i]=(rev[bit][i>>1]>>1)|((i&1)<<(bit-1));
	invv[bit]=inv[len];
}    
void NTT(poly &A,int type){
    for(int i=0;i<len;++i)
        if(i<rev[bit][i])swap(A[i],A[rev[bit][i]]);
    for(int i=1,t=0;i<len;i<<=1,++t)
        for(int j=0;j<len;j+=i<<1)
            for(int k=0;k<i;++k){
                int x=A[j+k];
                int y=1ll*w[t][k]*A[j+k+i]%Mod;
                A[j+k]=add(x,y);
                A[j+k+i]=dec(x,y);
            }
    if(type==1)return;
    reverse(++A.begin(),A.end());
    for(int i=0;i<len;++i)A[i]=1ll*A[i]*invv[bit]%Mod;
}

void FFT(poly &p,int d){
	rep(i,0,d){
		p[i]=mul(mul(ifac[d-i],ifac[i]),p[i]);
		if((i+d)&1)p[i]=dec(0,p[i]);
	}
	p.rez(len);
	NTT(p,1);
}

int iS;
poly poly_shift(poly p,poly _p,int d,int shift){
	shift=mul(shift,iS);
	poly q;q.rez(len);
	rep(i,0,2*d){
		val[i]=dec(add(shift,i),d);
		if(val[i]==0)val[i]=1;
		vali[i]=Fast_Pow(val[i],Mod-2);
		if(i<2*d)q[i]=vali[i];
	}
	NTT(q,1);
	rep(i,0,len-1)q[i]=mul(q[i],_p[i]);
	NTT(q,-1);
	int t=1;rep(i,0,d)t=mul(t,val[i]);
	rep(i,d,2*d-1){
		q[i]=mul(q[i],t);
		if(add(shift,i-d)<=d)q[i]=p[add(shift,i-d)];
		t=mul(t,vali[i-d]);
		t=mul(t,val[i+1]);
	}
	int cur=0;
	if(add(shift,d)<=d)cur=p[add(shift,d)];
	else{
		rep(i,0,d){
			p[i]=mul(mul(ifac[d-i],ifac[i]),p[i]);
			if((i+d)&1)p[i]=dec(0,p[i]);
			cur=add(cur,mul(p[i],vali[2*d-i]));
		}
		cur=mul(cur,t);
	}q.push_back(cur);
	rep(i,0,d)q[i]=q[i+d];q.rez(d+1);return q;
}

poly P,Q,R,_P,_Q,_R;
poly P0,P1,P2,P3;
poly Q1,Q2,Q3;
poly R0,R1,R2,R3;
int p(int x){return dec(2*n,x);}
int q(int x){return dec(n,x);}

int h1[Maxn],h2[Maxn],iQ;
int calc(int a){
	int res=0;
	for(int i=0;i<a/B;++i){
		if(i)res=add(res,mul(mul(Q[i+1],P[i-1]),R[i]));
		else res=add(res,mul(Q[i+1],R[i]));
	}
	int t=Q[a/B+1];
	if(a/B>0)t=mul(t,P[a/B-1]);
	int at=a/B*B;
	h1[0]=t;
	rep(i,at+1,a)h1[i-at]=mul(h1[i-at-1],p(i));
	int cur=min(at+B,n-1);h2[cur-at+1]=1;
	per(i,cur,at+1)h2[i-at]=mul(h2[i-at+1],q(i));
	rep(i,at+1,a)res=add(res,mul(h1[i-at],h2[i-at+1]));
	res=mul(res,iQ);
	res=add(res,1);
	res=mul(res,D2);
	return res;
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	init_w();
	rd(m);
	rep(i,1,m)rd(a[i]),n+=a[i];
	S=1;while(1ll*S*S<n)S++;
	while(S&(S-1))S=(S|(S-1))+1;iS=Fast_Pow(S,Mod-2);
	init();
	B=1;
	P.rez(2);P[0]=p(1),P[1]=p(S+1);R=P;
	Q.rez(2);Q[0]=q(1),Q[1]=q(S+1);
	while(B<S){
		init_r(B*2);
		_P=P;FFT(_P,B);
		_Q=Q;FFT(_Q,B);
		_R=R;FFT(_R,B);
		P1=poly_shift(P,_P,B,B);
		P2=poly_shift(P,_P,B,mul(S,B));
		P3=poly_shift(P,_P,B,mul(S+1,B));
		P0=P;rep(i,0,B)P[i]=mul(P[i],P1[i]);
		P.rez(2*B+1);rep(i,B+1,2*B)P[i]=mul(P2[i-B],P3[i-B]);
		Q1=poly_shift(Q,_Q,B,B);
		Q2=poly_shift(Q,_Q,B,mul(S,B));
		Q3=poly_shift(Q,_Q,B,mul(S+1,B));
		rep(i,0,B)Q[i]=mul(Q[i],Q1[i]);
		Q.rez(2*B+1);rep(i,B+1,2*B)Q[i]=mul(Q2[i-B],Q3[i-B]);
		R1=poly_shift(R,_R,B,B);
		R2=poly_shift(R,_R,B,mul(S,B));
		R3=poly_shift(R,_R,B,mul(S+1,B));
		R0=R;R.rez(2*B+1);
		rep(i,0,B)R[i]=mul(R0[i],Q1[i]);rep(i,B+1,2*B)R[i]=mul(R2[i-B],Q3[i-B]);
		rep(i,0,B)R[i]=add(R[i],mul(P0[i],R1[i]));rep(i,B+1,2*B)R[i]=add(R[i],mul(P2[i-B],R3[i-B]));
		B<<=1;
	}
	rep(i,1,B)P[i]=mul(P[i],P[i-1]);
	per(i,B,0)
		if(i*B>=n-1)Q[i]=1;
		else{
			if((i+1)*B<n-1)Q[i]=mul(Q[i],Q[i+1]);
			else{
				Q[i]=1;
				rep(j,i*B+1,n-1)Q[i]=mul(Q[i],q(j));
			}
		}Q.rez(B+2);Q[B+1]=1;
	iQ=Fast_Pow(Q[0],Mod-2);
	int ans=dec(0,calc(n-1));
	rep(i,1,m)ans=add(ans,calc(a[i]-1));
	printf("%d\n",ans);
	return 0;
}