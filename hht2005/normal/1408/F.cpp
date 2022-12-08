#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,k,j,cnt=0;
	scanf("%d",&n);
	for(k=1,j=0;k*2<n;k<<=1,j++);
	for(int l=1;l<k;l<<=1)
		for(int p=0;p<l;p++)
			for(int o=1;o<=k;o+=l+l)
				cnt++;
	printf("%d\n",cnt*2);
	for(int l=1;l<k;l<<=1)
		for(int o=1;o<=k;o+=l+l)
			for(int p=0;p<l;p++)
			printf("%d %d\n",o+p,o+p+l);
	for(int l=1;l<k;l<<=1)
		for(int o=1;o<=k;o+=l+l)
			for(int p=0;p<l;p++)
			printf("%d %d\n",o+p+n-k,o+p+l+n-k);
	return 0;
}