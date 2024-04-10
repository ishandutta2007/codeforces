#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=610,mod=1e9+7,maxn=600;
int a[N],sta1[N],sta2[N],Mi[N],f1[N][N],f2[N][N],fl[N],nf[N],ID[N][2],p1[N],p2[N],f3[N][N],Ni1[N],Ni2[N];
int mi(int x,int t){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}
int ni(int x) {return mi((x+mod)%mod,mod-2);}

bool cmp(int n1,int n2) {return (std::abs(n1)>std::abs(n2));}

struct node{
	int x,c,ty;
}g[N];
bool cmp2(node n1,node n2){
	if(n1.c==n2.c) return (n1.ty<n2.ty);
	return (n1.c>n2.c);
}
ll Abs(ll x){
	if(x<0) return -x;
	return x;
}

int mymax(int x,int y) {return (x>y?x:y);}

int main()
{
	
	fl[0]=1;for(int i=1;i<=maxn;i++) fl[i]=(ll)fl[i-1]*i%mod;
	nf[maxn]=ni(fl[maxn]);for(int i=maxn-1;i>=0;i--) nf[i]=(ll)nf[i+1]*(i+1)%mod;
	
	int n,K;
	scanf("%d%d",&n,&K);
	
	Mi[0]=1;for(int i=1;i<=n;i++) Mi[i]=(ll)Mi[i-1]*2%mod;
	
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	int tot1=0,tot2=0;
	for(int i=1;i<=n;i++){
		if(a[i]<0) sta1[++tot1]=a[i];
		else sta2[++tot2]=a[i];
	}
	
	sort(sta1+1,sta1+tot1+1,cmp);
	sort(sta2+1,sta2+tot2+1,cmp);
	
	f1[0][0]=f2[0][0]=1;
	for(int i=0;i<=tot1;i++)
		for(int j=0;j<=i;j++)
			for(int k=i+1;k<=tot1;k++)
				f1[k][j+1]=(f1[k][j+1]+(ll)f1[i][j]*(mod+sta1[k]))%mod;
	for(int i=0;i<=tot2;i++)
		for(int j=0;j<=i;j++)
			for(int k=i+1;k<=tot2;k++)
				f2[k][j+1]=(f2[k][j+1]+(ll)f2[i][j]*sta2[k])%mod;
	f3[tot1+1][0]=1;
	for(int i=tot1+1;i>=1;i--)
		for(int j=0;j<=tot1+1-i;j++)
			for(int k=i-1;k>=1;k--)
				f3[k][j+1]=(f3[k][j+1]+(ll)f3[i][j]*(mod+sta1[k]))%mod;
	
	int tot=0;
	for(int i=1;i<=tot1;i++) g[++tot].x=i,g[tot].c=std::abs(sta1[i]),g[tot].ty=1;
	for(int i=1;i<=tot2;i++) g[++tot].x=i,g[tot].c=std::abs(sta2[i]),g[tot].ty=2;
	sort(g+1,g+tot+1,cmp2);
	int Summ=0;
	for(int i=1;i<=tot;i++){
		if(g[i].ty==1) Summ++;
		ID[i][0]=Summ;ID[i][1]=i-Summ;
		if(g[i].ty==1) p1[Summ]=i;
		else p2[i-Summ]=i;
	}
	
	for(int i=1;i<=tot1;i++) Ni1[i]=ni(sta1[i]);
	for(int i=1;i<=tot2;i++) Ni2[i]=ni(sta2[i]);
	
	int Ans=0;
	for(int i=1;i<=tot1;i++)
		for(int j=1;j<=tot2;j++){
			int Sum1=0,Sum2=0;
			for(int k=1;k<K;k++){
				int t=(ll)f1[i][k]*f2[j][K-k]%mod;
				if(k%2==0) Sum1=(Sum1+t)%mod;
				else Sum2=(Sum2+t)%mod;
			}
			int t=mymax(p1[i],p2[j]);
			Ans=(Ans+(ll)Sum1*Mi[n-t])%mod;
			int id=ID[t][0]+1;
			for(int k=ID[t][1]+1;k<=tot2;k++){
				while(id<=tot1&&Abs((ll)sta2[k]*sta2[j])<=Abs((ll)sta1[i]*sta1[id])) id++;
				Ans=(Ans+(ll)Sum2*Mi[tot2-k]%mod*Mi[tot1+1-id]%mod*sta2[k]%mod*Ni1[i])%mod;
			}
			id=ID[t][1]+1;
			for(int k=ID[t][0]+1;k<=tot1;k++){
				while(id<=tot2&&Abs((ll)sta1[i]*sta1[k])<Abs((ll)sta2[j]*sta2[id])) id++;
				Ans=(Ans+(ll)Sum2*Mi[tot1-k]%mod*Mi[tot2+1-id]%mod*(sta1[k]+mod)%mod*Ni2[j])%mod;
			}
		}
		
	for(int i=1;i<=tot2;i++){
		int t=Mi[n-p2[i]];
		Ans=(Ans+(ll)f2[i][K]*t)%mod;
	}
	for(int i=1;i<=tot1;i++){
		if(K%2==0){
			int t=Mi[n-p1[i]];
			Ans=(Ans+(ll)f1[i][K]*t)%mod;
		}
		else{
			int tt=ID[p1[i]][1];
			for(int j=tt+1;j<=tot2;j++){
				Ans=(Ans+(ll)f1[i][K]*ni(sta1[i])%mod*sta2[j]%mod*Mi[tot2-j]%mod*Mi[tot1-i])%mod;
			}
		}
	}
	
	for(int i=1;i<K;i+=2){
		int Sum1=0,Sum2=0;
		for(int j=0;j<=tot1;j++) Sum1=(Sum1+f1[j][i])%mod;
		for(int j=0;j<=tot2;j++) Sum2=(Sum2+f2[j][K-i])%mod;
		Ans=(Ans+(ll)Sum1*Sum2)%mod;
	}
	if(K%2==1){
		for(int i=tot1;i>=1;i--){
			Ans=(Ans+(ll)f3[i][K]*Mi[i-1])%mod;
		}
	}
	
	printf("%d\n",Ans);
	
	return 0;
}