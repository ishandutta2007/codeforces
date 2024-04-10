#include<bits/stdc++.h>
using namespace std;
#define fl fwrite(o_str,1,top,stdout),top=0
const int MAXL=1<<22;
char i_str[MAXL],*i_s,*i_t;
inline char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
inline long long read() {
	long long x=0,f=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc())
		if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x;
}
const int mod=1e9+7;
struct mat {
	int v[210][210],n,m;
	mat() {
		memset(v,0,sizeof(v));
		n=m=0;
	}
	mat operator *(const mat &a) const {
		mat b;
		b.n=n,b.m=a.m;
		for(int i=0; i<n; i++)
			for(int j=0; j<a.m; j++)
				for(int k=0; k<m; k++)
					b.v[i][j]=(b.v[i][j]+1ll*v[i][k]*a.v[k][j])%mod;
		return b;
	}
} ans,tas;
int main() {
	long long n=read();
	int m=read();
	if(m>n)return puts("1"),0;
	for(int i=0;i<m;i++)ans.v[0][i]=1;
	ans.n=1;
	ans.m=tas.n=tas.m=m;
	tas.v[m-1][0]=tas.v[m-1][m-1]=1;
	for(int i=0;i<m-1;i++)tas.v[i][i+1]=1;
	long long b=n-m+1;
	while(b) {
		if(b&1)ans=ans*tas;
		tas=tas*tas;
		b>>=1;
	}
	printf("%d\n",ans.v[0][m-1]);
	return 0;
}