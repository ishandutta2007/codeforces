#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define N 1000010
using namespace std;
typedef long long ll;
int n,k,c,a[N],d[N],n1[N],n2[N],f1[N],f2[N],t[N];bool v[N];
int main(){
	scanf("%d%d",&n,&k);
	if(k==1){
		rep(i,1,n)printf("1 ");return 0;
	}
	rep(i,1,n)scanf("%d",&a[i]);
	for(int i=n;i;--i){
		while(c&&d[c]<=a[i])--c;
		d[++c]=a[i];a[i]=c;t[i]=i;
	}
	rep(i,1,n){int x=i-1;
		for(;x&&(a[x]>a[i]||a[t[x]]-a[x]<=a[t[i]]-a[i]);x=f2[x]){
			int y=x;for(;y&&a[t[i]]>=a[y];y=f1[y])v[y]=1;
			if(y){
				n1[y]=t[i];f1[t[i]]=y;t[i]=t[x];
			}
		}
		if(x)n2[x]=i,f2[i]=x;else c=i;
		if(i>=k){
			printf("%d ",a[t[c]]-a[c]+1);
			if(!v[i-k+1]){
				v[i-k+1]=1;t[c]=n1[i-k+1];f1[n1[i-k+1]]=0;
				if(n2[c]&&a[t[c]]-a[c]<=a[t[n2[c]]]-a[n2[c]]){
					for(int j=i-k+1;j;j=n1[j])v[j]=1;
					f2[n2[c]]=0;c=n2[c];
				}
			}
		}
	}
}