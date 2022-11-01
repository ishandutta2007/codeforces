#include<bits/stdc++.h>
using namespace std;
int bin[10],bit[30],mp[30];
int n,k,x;
int main(){
	bin[1]=1; bin[2]=2; bin[3]=4; bin[4]=8;
	for (int i=1;i<=16;i++)
		bit[i]=bit[i/2]+(i&1);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		int p=0;
		for (int j=1;j<=k;j++)
			scanf("%d",&x),p+=x*bin[j];
		mp[p]=1;
	}
	for (int i=0;i<bin[k]*2;i++)
		for (int j=0;j<bin[k]*2;j++)
			if ((i&j)==0&&mp[i]&mp[j])
				return puts("YES"),0;
	puts("NO");
}