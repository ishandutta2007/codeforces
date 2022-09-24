#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int mod=998244353,g=3,invg=(mod+1)/3;
int n,k,A,c[40005],tr[40005],tmp[40005],gy[40005],f[40005],s[40005]={1},t[40005]={0,1};
int wk[20][40005],wk2[20][40005];
ll a[20005];
int Power(int x,int y) {
	int ret=1;
	while(y) {
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
void GetTr(int l) {
	for(int i=0; i<l; i++)tr[i]=(tr[i>>1]>>1)|((i&1)?(l>>1):0);
}
inline int Add(int x,int y){
    x+=y;
    if(x>=mod)x-=mod;
    return x;
}
inline int Del(int x,int y){
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
void Calcinv(int a[],int b[],int l){
	if(l==1){
		b[0]=Power(a[0],mod-2);
		return ;
	}
	Calcinv(a,b,(l+1)/2);
	int len=1;
	while(len<l*2)len<<=1;
	GetTr(len);
	memcpy(tmp,a,sizeof(int)*l);
	for(int i=l;i<len;i++)tmp[i]=0;
	NTT(tmp,len,1),NTT(b,len,1);
	for(int i=0;i<len;i++)b[i]=(2-1ll*tmp[i]*b[i]%mod+mod)%mod*b[i]%mod;
	NTT(b,len,-1);
	for(int i=l;i<len;i++)b[i]=0;
}
void CalcMod(int f[],int l[],int n,int m,int c[]){
	if(n<m){
		fill(c,c+n,0);
		for(int i=0;i<m;i++)c[i]=f[i];
		return ;
	}
	static int t[40005];
	memset(t,0,sizeof(t));
	reverse(l,l+m+1);
	reverse(f,f+n+1);
	Calcinv(l,t,n-m+1);
	int len=1;
	while(len<=2*n)len<<=1;
	GetTr(len);
	NTT(t,len,1),NTT(f,len,1);
	for(int i=0;i<len;i++)t[i]=1ll*t[i]*f[i]%mod;
	NTT(t,len,-1);
	reverse(t,t+n-m+1);
	for(int i=n-m+1;i<len;i++)t[i]=0;
	reverse(l,l+m+1);
	NTT(t,len,1),NTT(l,len,1);
	for(int i=0;i<len;i++)t[i]=1ll*t[i]*l[i]%mod;
	NTT(t,len,-1),NTT(f,len,-1),NTT(l,len,-1),reverse(f,f+n+1);
	fill(c,c+n,0);
	for(int i=0;i<m;i++)c[i]=(f[i]-t[i]+mod)%mod;
}
void BM(ll *a,int n,vector<ll> &ans){
	ans.clear();
	vector<ll> lst;
	int w=0;ll delta=0;
	for(int i=1;i<=n;i++){
		ll tmp=0;
		for(int j=0;j<ans.size();j++)
			tmp=(tmp+a[i-1-j]*ans[j])%mod;
		if((a[i]-tmp)%mod==0) continue;
		if(!w){
			w=i;delta=a[i]-tmp;
			for(int j=i;j;j--) ans.push_back(0);
			continue;
		}
		vector<ll> now=ans;
		ll mul=(a[i]-tmp)*Power(delta,mod-2)%mod;
		if(ans.size()<lst.size()+i-w) ans.resize(lst.size()+i-w);
		ans[i-w-1]=(ans[i-w-1]+mul)%mod;
		for(int j=0;j<lst.size();j++) ans[i-w+j]=(ans[i-w+j]-mul*lst[j])%mod;
		if(now.size()-i<lst.size()-w){
			lst=now;w=i;delta=a[i]-tmp;
		}
	}
}
string str;
int m,ch[45][26],tot,F[2005][45][45],ed[45];
void Ins(){
	int p=0;
	for(auto i:str){
		if(!ch[p][i-'a'])ch[p][i-'a']=++tot;
		p=ch[p][i-'a'];
	}
	ed[p]=1;
}
int main(){
	cin>>m>>n,n--;
	for(int i=1;i<=m;i++)cin>>str,Ins();
	F[0][0][0]=1;
	for(int i=0;i<2000;i++){
		for(int j=0;j<=tot;j++){
			for(int k=0;k<=tot;k++){
				if(!F[i][j][k])continue;
				for(int l=0;l<26;l++){
					if(!ch[j][l]||!ch[k][l])continue;
					F[i+1][ch[j][l]][ch[k][l]]=(F[i+1][ch[j][l]][ch[k][l]]+F[i][j][k])%mod;
					if(ed[ch[j][l]])F[i+1][0][ch[k][l]]=(F[i+1][0][ch[k][l]]+F[i][j][k])%mod;
					if(ed[ch[k][l]])F[i+1][ch[j][l]][0]=(F[i+1][ch[j][l]][0]+F[i][j][k])%mod;
					if(ed[ch[j][l]]&&ed[ch[k][l]])F[i+1][0][0]=(F[i+1][0][0]+F[i][j][k])%mod;
				}
			}
		}
		a[i]=F[i][0][0];
	}
	for(int i=1;i<=15;i++){
		int w=Power(g,(mod-1)/(1<<i));
		for(int j=0,u=1;j<(1<<i-1);j++,u=1ll*u*w%mod)wk[i][j]=u;
		w=Power(invg,(mod-1)/(1<<i));
		for(int j=0,u=1;j<(1<<i-1);j++,u=1ll*u*w%mod)wk2[i][j]=u;
	}
	s[0]=1,t[1]=1;
	vector<ll> ans;
	BM(a,1999,ans);
	for(ll &i:ans)i=(i+mod)%mod;
	k=ans.size();
	for(int i=1;i<=k;i++)f[i]=ans[i-1];
	for(int i=0;i<k;i++)a[i]=a[i+1];
	reverse(f,f+k+1),f[k]=1;
	for(int i=0;i<k;i++)f[i]=mod-f[i];
	int len=1;
	while(len<=2*k)len<<=1;
	int css=0,cst=1;
	while(n){
		GetTr(len);
		NTT(t,len,1);
		if(n&1){
			NTT(s,len,1);
			for(int i=0;i<len;i++)s[i]=1ll*s[i]*t[i]%mod;
			NTT(s,len,-1),css+=cst;
			CalcMod(s,f,css,k,gy),css=min(css,k-1);
			memcpy(s,gy,sizeof(gy));
		}
		for(int i=0;i<len;i++)t[i]=1ll*t[i]*t[i]%mod;
		GetTr(len);
		NTT(t,len,-1),cst*=2;
		CalcMod(t,f,cst,k,gy),cst=min(cst,k-1);
		memcpy(t,gy,sizeof(gy));
		n>>=1;
	}
	int sum=0;
	for(int i=0;i<k;i++)sum=(sum+1ll*s[i]*a[i])%mod;
	cout<<sum;
}