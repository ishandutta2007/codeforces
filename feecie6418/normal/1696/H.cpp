#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int n,K,fp[605][605],fn[605][605],gn[605][605],n1,n2,a[605],b[605],pw2[605]={1};
int sign,ans=0,ia[605],ib[605],inva[605],invb[605],h[605][605],s1[605],s2[605];
int sfp[605][605],sfn[605][605],sgn[605][605];
int main(){
	cin>>n>>K;
	for(int i=1,x;i<=n;i++){
		cin>>x,pw2[i]=pw2[i-1]*2%mod;
		if(x>=0)a[++n1]=x;
		else b[++n2]=x;
	}
	sort(a+1,a+n1+1),reverse(a+1,a+n1+1),sort(b+1,b+n2+1);
	for(int i=1,j=1;i<=n1+1;i++){
		while(j!=n2+1&&abs(b[j])>abs(a[i]))ib[j]=++sign,j++;
		if(i!=n1+1)ia[i]=++sign;
	}
	fp[0][0]=fn[0][0]=1;
	sfp[0][0]=sfn[0][0]=1;
	for(int i=1;i<=n1;i++){
		inva[i]=Power(a[i],mod-2),sfp[i][0]=1;
		for(int j=1;j<=i;j++){
			fp[i][j]=(fp[i][j]+1ll*a[i]*sfp[i-1][j-1])%mod;
			sfp[i][j]=(sfp[i-1][j]+fp[i][j])%mod;
		}
	}
	for(int i=1;i<=n2;i++){
		invb[i]=Power(b[i]+mod,mod-2),s1[i]=(s1[i-1]+1ll*(b[i]+mod)*pw2[n2-i])%mod,s2[i]=(s2[i-1]+pw2[n2-i])%mod;
		sfn[i][0]=1;
		for(int j=1;j<=i;j++){
			fn[i][j]=(fn[i][j]+1ll*(b[i]+mod)*sfn[i-1][j-1])%mod;
			sfn[i][j]=(sfn[i-1][j]+fn[i][j])%mod;
		}
	}
	sgn[n2+1][0]=gn[n2+1][0]=1;
	for(int i=n2;i>=1;i--){
		sgn[i][0]=1;
		for(int j=1;j<=n2-i+1;j++){
			gn[i][j]=(gn[i][j]+1ll*(b[i]+mod)*sgn[i+1][j-1])%mod;
			sgn[i][j]=(sgn[i+1][j]+gn[i][j])%mod;
		}
	}
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			int t=max(ia[i],ib[j]),pos=n2+1;
			for(int l=j+1;l<=n2;l++)if(ib[l]>t){pos=l;break;}
			for(int k=i+1,l=pos-1;k<=n1;k++){
				if(ia[k]<t)continue;
				while(l<n2&&1ll*a[i]*a[k]<1ll*b[j]*b[l+1])l++;
				h[i][j]=(h[i][j]+1ll*(s1[l]-s1[pos-1]+mod)*inva[i]%mod*pw2[n1-k])%mod;
				h[i][j]=(h[i][j]+1ll*a[k]*invb[j]%mod*pw2[n1-k]%mod*(s2[n2]-s2[l]+mod))%mod;
			}
			//k=n1+1
			for(int l=j+1;l<=n2;l++){
				if(ib[l]<max(ia[i],ib[j]))continue;
				h[i][j]=(h[i][j]+1ll*inva[i]*(b[l]+mod)%mod*pw2[n2-l])%mod;
			}
			//l=n2+1 
			for(int k=i+1;k<=n1;k++){
				if(ia[k]<max(ia[i],ib[j]))continue;
				h[i][j]=(h[i][j]+1ll*invb[j]*a[k]%mod*pw2[n1-k])%mod;
			}
			//k,l
			h[i][j]=(h[i][j]+1)%mod;
		}
	}
	for(int o=1;o<K;o++){//K
		for(int i=o;i<=n1;i++){
			for(int j=K-o;j<=n2;j++){
				if((K-o)%2==0)ans=(ans+1ll*fp[i][o]*fn[j][K-o]%mod*pw2[sign-max(ia[i],ib[j])])%mod;
				else ans=(ans+1ll*fp[i][o]*fn[j][K-o]%mod*h[i][j])%mod;
			}
		}
	}
	//K
	for(int i=1;i<=n1;i++)ans=(ans+1ll*fp[i][K]*pw2[sign-ia[i]])%mod;
	//K
	if(K%2==0){
		for(int i=1;i<=n2;i++)ans=(ans+1ll*fn[i][K]*pw2[sign-ib[i]])%mod;
	}
	else {
		//
		for(int i=n2;i>=1;i--)ans=(ans+1ll*gn[i][K]*pw2[i-1])%mod;
		//
		for(int i=1;i<=n2;i++){
			for(int j=1;j<=n1;j++){
				if(ia[j]<ib[i])continue;
				ans=(ans+1ll*fn[i][K]*invb[i]%mod*a[j]%mod*pw2[n1-j+n2-i])%mod;
			}
		}
	}
	cout<<ans;
}