#include<bits/stdc++.h>
using namespace std;
#define N 1005
int main(){
	int n;
	scanf("%d",&n);
	int a[105];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int b[105];
	for(int i=0;i<n;i++)
	b[i]=a[i];
	sort(b,b+n);
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++){
			if(b[i]==a[j])
			{
				for(int k=j;k>i;k--)
				swap(a[k],a[k-1]),printf("%d %d\n",k,k+1);
				break;
			}
		} 
}