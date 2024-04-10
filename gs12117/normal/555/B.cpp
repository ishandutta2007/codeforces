#include<stdio.h>
#include<algorithm>
int n,m;
long long int lr[200100][2];
struct qry{
	long long int mmin,mmax;
	int orig;
	bool operator<(const qry&r)const{
		return mmax<r.mmax;
	}
};
struct brg{
	long long int len;
	int orig;
	bool operator<(const brg&r)const{
		return len<r.len;
	}
};
brg a[200100];
qry b[200100];
int liv[200100];
int uft[200100];
int ans[200100];
int uftf(int x){
	if(x==uft[x])return x;
	return uft[x]=uftf(uft[x]);
}
int bsrc(long long int x){
	int i,j;
	j=-1;
	for(i=20;i>=0;i--){
		j+=(1<<i);
		if(j>=m||a[j].len>=x)j-=(1<<i);
	}
	return j+1;
}
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%I64d%I64d",&lr[i][0],&lr[i][1]);
	}
	for(i=0;i<m;i++){
		scanf("%I64d",&a[i].len);
		a[i].orig=i;
	}
	for(i=0;i<n-1;i++){
		b[i].mmin=lr[i+1][0]-lr[i][1];
		b[i].mmax=lr[i+1][1]-lr[i][0];
		b[i].orig=i;
	}
	n--;
	std::sort(a,a+m);
	std::sort(b,b+n);
	for(i=0;i<=m;i++){
		uft[i]=i;
	}
	j=0;
	for(i=0;i<n;i++){
		while(j<m&&b[i].mmax>=a[j].len){
			liv[j]=1;
			j++;
		}
		k=bsrc(b[i].mmin);
		k=uftf(k);
		if(liv[k]==0){
			printf("No");
			return 0;
		}
		liv[k]=0;
		uft[k]=k+1;
		ans[b[i].orig]=a[k].orig;
	}
	puts("Yes");
	for(i=0;i<n;i++){
		printf("%d ",ans[i]+1);
	}
}