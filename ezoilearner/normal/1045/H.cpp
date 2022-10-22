#include<bits/stdc++.h>
using namespace std;
const int Mod=1000000007;
const int N=200000;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define Maxn 100010
#define cout cerr
#define FR first
#define SE second
char ch1[Maxn],ch2[Maxn];
int fact[N+10],ifac[N+10],inv[N+10];
namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
}using namespace modular;
void init(){
	fact[0]=1;
	rep(i,1,N)fact[i]=mul(fact[i-1],i);
	inv[0]=inv[1]=1;
	rep(i,2,N)inv[i]=mul(Mod-Mod/i,inv[Mod%i]);
	ifac[0]=1;
	rep(i,1,N)ifac[i]=mul(ifac[i-1],inv[i]);
}
int C(int a,int b){
	if(a<b)return 0;
	return mul(fact[a],mul(ifac[b],ifac[a-b]));
}

//a 00 b 01 c 10 d 11
int gao(int a,int b,int c,int d){
	if(a<0||b<0||c<0||d<0)return 0;
	if(c<b||c>b+1)return 0;
	if(c==b){
		if(b==0){
			if(a>0)return 0;
			return C(d+c,c);
		}
		return mul(C(d+c,c),C(a+c-1,c-1));
	}
	return mul(C(a+c-1,c-1),C(d+c-1,c-1));
}
int a,b,c,d,n;
int calc(char *A,bool type){
	int len=strlen(A);
	reverse(A,A+len);len--;
	while(len&&A[len]=='0')len--;
	if(type){
		rep(i,0,len)
			if(A[i]=='1'){
				rep(j,0,i-1)A[j]='1';
				A[i]='0';
				break;
			}
		while(len&&A[len]=='0')len--;
	}
	if(len==0&&A[len]=='0')return 0;
	if(len+1<n)return 0;
	int res=gao(a,b,c,d);
	if(len+1>n)return res;
	int _a=0,_b=0,_c=0,_d=0;
	per(i,len-1,0){
		if(A[i]=='0'){
			if(A[i+1]=='1')res=dec(res,gao(a-_a,b-_b,c-_c,d-_d-1));
			else res=dec(res,gao(a-_a,b-_b-1,c-_c,d-_d));
		}
		if(A[i+1]=='0'){
			if(A[i]=='0')_a++;
			else _b++;
		}else{
			if(A[i]=='0')_c++;
			else _d++;
		}
	}
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
	init();
	scanf("%s",ch1);
	scanf("%s",ch2);
	rd(a);rd(b);rd(c);rd(d);n=a+b+c+d+1;
	printf("%d\n",dec(calc(ch2,0),calc(ch1,1)));
	return 0;
}