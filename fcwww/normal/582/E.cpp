#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define mod 1000000007
char str[550];
int n,qx[20],qy[20],cnt;
int inv2=(mod+1)/2,LEN=1<<16;
ll f[170][(1<<16)+50],g[3][(1<<16)+50];
void fort(ll *a,int len,int flg) {
	int i,j,k,t;
	for(k=2;k<=len;k<<=1) {
		t=k>>1; for(i=0;i<len;i+=k) for(j=i;j<i+t;j++) {
			if(flg==1) a[j+t]=(a[j+t]+a[j])%mod;
			else a[j+t]=(a[j+t]-a[j])%mod; 
		}
	}
}
void fandt(ll *a,int len,int flg) {
	int i,j,k,t;
	for(k=2;k<=len;k<<=1) {
		t=k>>1; for(i=0;i<len;i+=k) for(j=i;j<i+t;j++) {
			if(flg==1) a[j]=(a[j]+a[j+t])%mod;
			else a[j]=(a[j]-a[j+t])%mod;
		}
	}
}
int build(int l,int r) {
	int p=++cnt,i,t,j;
	if(l==r) {
		int s=0;
		for(i=0;i<4;i++) {
			s=0;
			if(str[l]=='?'||str[l]=='A'+i) {
				for(j=0;j<16;j++) if(j&(1<<i)) {
					s+=(1<<j);
				}
				f[p][s]++;
			}
			s=0;
			if(str[l]=='?'||str[l]=='a'+i) {
				for(j=0;j<16;j++) if(!(j&(1<<i))) {
					s+=(1<<j);
				}
				f[p][s]++;
			}
		}
		return p;
	}
	t=0;
	for(i=l;i<=r;i++) {
		if(str[i]=='(') t++;
		if(str[i]==')') t--;
		if(t==0) break;
	}
	int mid=i+1;
	int ls=build(l+1,mid-2),rs=build(mid+2,r-1);
	if(str[mid]=='|') {
		fort(f[ls],LEN,1); fort(f[rs],LEN,1);
		for(i=0;i<LEN;i++) f[p][i]=f[ls][i]*f[rs][i]%mod;
		fort(f[p],LEN,-1);
	}else if(str[mid]=='&') {
		fandt(f[ls],LEN,1); fandt(f[rs],LEN,1);
		for(i=0;i<LEN;i++) f[p][i]=f[ls][i]*f[rs][i]%mod;
		fandt(f[p],LEN,-1);
	}else {
		memcpy(g[0],f[ls],sizeof(ll)*LEN);
		memcpy(g[1],f[rs],sizeof(ll)*LEN);
		fort(f[ls],LEN,1); fort(f[rs],LEN,1);
		for(i=0;i<LEN;i++) f[p][i]=f[ls][i]*f[rs][i]%mod;
		fort(f[p],LEN,-1);
		fandt(g[0],LEN,1); fandt(g[1],LEN,1);
		for(i=0;i<LEN;i++) g[2][i]=g[0][i]*g[1][i]%mod;
		fandt(g[2],LEN,-1);
		for(i=0;i<LEN;i++) f[p][i]=(f[p][i]+g[2][i])%mod;
	}
	return p;
}
int main() {
	int m;
	scanf("%s%d",str+1,&m);
	n=strlen(str+1);
	int i,j,x;
	for(i=1;i<=m;i++) {
		for(j=0;j<4;j++) scanf("%d",&x),qx[i]+=(x<<j);
		scanf("%d",&qy[i]);
	}
	int rt=build(1,n),ans=0;
	for(i=0;i<LEN;i++) {
		for(j=1;j<=m;j++) {
			if(qy[j]!=((i>>qx[j])&1)) break;
		}
		if(j>m&&f[rt][i]) ans=(ans+f[rt][i])%mod;
	}
	printf("%d\n",(ans+mod)%mod);
}