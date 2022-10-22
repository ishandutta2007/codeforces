#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

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

int n;ll Mod;
#define Maxn 100010
int B[Maxn],C[Maxn],len=1,bit=0;
int rev[Maxn*3];

namespace modular{
	ll add(ll a,ll b){return a+b>=Mod?a+b-Mod:a+b;}
	ll dec(ll a,ll b){return a-b<0?a-b+Mod:a-b;}
	ll mul(ll a,ll b){return (a*b-(ll)((long double)a*b/Mod)*Mod+Mod)%Mod;}
	ll Fast_Pow(ll a,ll b){
		ll res=1;
		while(b){
			if(b&1)res=mul(res,a);
			a=mul(a,a);
			b>>=1;
		}
		return res;
	}
}using namespace modular;

int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}

ll wn[Maxn];ll g;
bool Judge(ll x){
	for(int i=2;1ll*i*i<=x;++i)
		if(x%i==0)return false;
	return true;
}
ll pr[20];int cnt;
mt19937 mt_rand(time(0));
vector<ll> w[30];
#define rez resize
void init_wn(){
	while(len<2*n){
		len<<=1;bit++;
	}
	if(len==2){
		len<<=1;bit++;
	}
	rep(i,0,len-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	ll lim=1ll*len*n/gcd(len,n);
	while(Mod<1e5)Mod+=lim;
	while(!Judge(Mod+1))Mod+=lim;Mod++;
	ll cur=Mod-1;
	for(int i=2;1ll*i*i<=cur;++i)
		if(cur%i==0){
			pr[++cnt]=i;
			while(cur%i==0)cur/=i;
		} 
	if(cur>1)pr[++cnt]=cur;
	while(true){
		g=1ull*mt_rand()*mt_rand()%(Mod-1)+1;
		bool fl=true;
		rep(i,1,cnt)
			if(Fast_Pow(g,(Mod-1)/pr[i])==1){
				fl=false;
				break;
			}
		if(fl)break;
	}	
	wn[0]=1;wn[1]=Fast_Pow(g,(Mod-1)/n);
	rep(i,2,n)wn[i]=mul(wn[i-1],wn[1]);
	w[bit-1].rez(len/2);
	w[bit-1][0]=1;w[bit-1][1]=Fast_Pow(g,(Mod-1)/len);rep(i,2,len/2-1)w[bit-1][i]=mul(w[bit-1][i-1],w[bit-1][1]);
	per(i,bit-2,0){
		w[i].rez(1<<i);
		rep(j,0,(1<<i)-1)w[i][j]=w[i+1][j<<1];
	}
}

ll f[Maxn*3],hh[Maxn*3];
void NTT(ll *A,int type){
	rep(i,0,len-1)
		if(i<rev[i])swap(A[i],A[rev[i]]);
	for(int i=1,t=0;i<len;i<<=1,++t)
		for(int j=0;j<len;j+=i<<1)
			for(int k=0;k<i;++k){
				ll x=A[j+k],y=mul(A[j+k+i],w[t][k]);
				A[j+k]=add(x,y);A[j+k+i]=dec(x,y);
			}
	
	if(type==1)return;
	reverse(A+1,A+len);
	ll ilen=Fast_Pow(len,Mod-2);
	rep(i,0,len-1)A[i]=mul(A[i],ilen);
}

ll h[Maxn*3];
void calc(ll *A){
	rep(i,0,n-1)h[i]=mul(A[i],wn[1ll*i*(i+1)/2%n]);rep(i,n,len-1)h[i]=0;
	NTT(h,1);
	rep(i,0,len-1)h[i]=mul(h[i],f[i]);
	NTT(h,-1);
	rep(i,0,n-1){
		A[i]=h[i+n];
		A[i]=mul(A[i],wn[1ll*i*(i-1)/2%n]);
	}
}

ll iB[Maxn],nC[Maxn];
ll dA[Maxn];

int main(){
	rd(n);
	rep(i,0,n-1){
		rd(B[i]);
	}
	rep(i,0,n-1){
		rd(C[i]);
	}
	init_wn();
	rep(i,0,2*n-1)f[i]=wn[n-1ll*(i-n)*(i-n-1)/2%n];
	NTT(f,1);
	rep(i,0,n-1)iB[i]=B[(n-i)%n];
	calc(iB);
	ll cur=dec(0,(Mod+1)/2);
	rep(i,0,n-1)nC[i]=dec(C[i],C[(i-1+n)%n]);
	calc(nC);
	rep(i,0,n-1){
		dA[i]=mul(nC[i],cur);
		iB[i]=Fast_Pow(iB[i],Mod-2);
		dA[i]=mul(dA[i],iB[i]);
	}
	calc(dA);
	reverse(dA+1,dA+n);
	ll in=Fast_Pow(n,Mod-2);
	rep(i,0,n-1)dA[i]=mul(dA[i],in);
	cur=0;
	rep(i,0,n-1){
		if(Mod-dA[i]<dA[i])dA[i]-=Mod;
		if(abs(dA[i])>5600){
			puts("0");
			return 0;
		}
		cur+=dA[i];
	}
	if(cur!=0){
		puts("0");
		return 0;
	}
	ll _a=0,_b=0,_c=-C[0];
	rep(i,0,n-1){
		//(x+cur-B[i])
		_a++;_b+=2*(cur-B[i]);_c+=1ll*(cur-B[i])*(cur-B[i]);
		cur+=dA[i+1];
	}
	set<ll> ans;
	if(_b*_b-4*_a*_c>=0){
		ll s=ll(sqrt(_b*_b-4*_a*_c)+0.5);
		if(s*s!=_b*_b-4*_a*_c){
			puts("0");
			return 0;
		}
		if((-_b+s)%(2*_a)==0)ans.insert((-_b+s)/(2*_a));
		if((-_b-s)%(2*_a)==0)ans.insert((-_b-s)/(2*_a));
	}
	printf("%d\n",ans.size());
	for(set<ll>::iterator it=ans.begin();it!=ans.end();it++){
		ll val=(*it);
		rep(i,0,n-1){
			printf("%lld ",val);
			val+=dA[i+1];
		}
		puts("");
	}
	return 0;
}