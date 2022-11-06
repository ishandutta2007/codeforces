#include<stdio.h>
#define N 100011
int a[N],b[N];
void fsort(int l,int r){
	if(l>=r-1)return;
	int m=l+r>>1;
	fsort(l,m),fsort(m,r);
	int L=l,R=m,j=l;
	while(L<m&&R<r){
		if(a[L]<a[R])b[j]=a[L],++L;
		else b[j]=a[R],++R;
		++j;
	}
	while(L<m)b[j]=a[L],++L,++j;
	while(R<r)b[j]=a[R],++R,++j;
	int i;for(i=l;i<r;++i)a[i]=b[i];
	return;
}
int gcd(int i,int j){
	if(!j)return i;else return gcd(j,i%j);
}
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;++i)scanf("%d",a+i);
	fsort(0,n);
	int mi=0;
	for(i=1;i<n;++i)mi=gcd(mi,a[i]-a[i-1]);
	long long ans=0;
	for(i=1;i<n;++i)ans+=(a[i]-a[i-1])/mi-1;
	printf("%I64d",ans);
	return 0;
}