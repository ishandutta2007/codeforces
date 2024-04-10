#include <bits/stdc++.h>

int n,f[5005],len[5005];
char a[5005];

int main(){
	scanf("%s",a+1);
	n=std::strlen(a+1);
	int k=log2(n);
	std::memset(f,0,sizeof(f));
	for(int S=0;S<(1<<k);++S)f[S]=1;
	for(int i=1;i<=n-((1<<k)-1);++i){
		char c='z'+1;
		
		for(int j=0;j<(1<<k);++j)
			if (f[j])for(int l=0;l<k;++l)f[j|(1<<l)]=1;
		for(int j=0;j<(1<<k);++j)
			if(f[j]&&a[i+j]<c)c=a[i+j];
		for(int j=0;j<(1<<k);++j)if(c!=a[i+j])f[j]=0;
		printf("%c",c);
	}
	return 0;
}