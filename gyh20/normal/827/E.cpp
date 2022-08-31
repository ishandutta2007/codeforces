
#include<bits/stdc++.h>
#define re register
#define cp complex<double>
using namespace std;
int rev[2000002],c[2000002];
cp wi[2000002];
long long ans;
int n;
char s[500002];
inline int make(re int n){
	re int l=ceil(log2(n));n=1<<l;
	for(re int i=0;i<n;++i)rev[i]=rev[i>>1]>>1|((i&1)<<(l-1));
	return n;
}
inline void FFT(re cp*A,re int n,re int f){
	for(re int i=0;i<n;++i)if(i<rev[i])swap(A[i],A[rev[i]]);
	for(re int i=1;i<n;i<<=1){
		wi[0]=1;re cp wn=exp((cp){0,f*acos(-1)/i});
		for(re int j=1;j<i;++j)wi[j]=wi[j-1]*wn;
		for(re int j=0;j<n;j+=i<<1)
			for(re int k=0;k<i;++k){
				re cp x=A[j+k],y=A[j+k+i]*wi[k];
				A[j+k]=x+y,A[j+k+i]=x-y;
			}
	}
	if(f==-1)for(re int i=0;i<n;++i)A[i]/=n;
}
cp A[2000002],B[2000002];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",s+1),n=strlen(s+1);
		for(re int i=1;i<=n;++i)if(s[i]=='V')A[n-i]=1;else if(s[i]=='K')B[i]=1;
		re int k=make(n+n+1);
		FFT(A,k,1),FFT(B,k,1);
		for(re int i=0;i<k;++i)A[i]*=B[i];
		FFT(A,k,-1);
		for(re int i=0;i<k;++i)if(A[i].real()>0.2)c[abs(i-n)]=1;
		vector<int>xx;
		for(re int i=1;i<=n;++i){
				re bool f=0;
			for(re int j=i;j<=n&&!f;j+=i)f|=c[j];
			if(!f&&(i^n))xx.push_back(i);
		}
		xx.push_back(n);sort(xx.begin(),xx.end());
		printf("%d\n",xx.size());
		for(auto z:xx)printf("%d ",z);
		puts("");
		fill(A,A+k,0),fill(B,B+k,0),fill(c,c+k,0);
	}
}