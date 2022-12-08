#include<bits/stdc++.h>
using namespace std;
const int N=1010;
bitset<N>t;
int n;
int calc(int k) {
	return n-1-(n-1)/k-k+1;
}
int main() {
	int k;
	scanf("%d",&n);
	if(n<=3) {
		puts("0");
		return 0;
	}
	k=sqrt(n-1);
	while(k<n&&calc(k)<calc(k+1))k++;
	while(k>1&&calc(k)<calc(k-1))k--;
	int R=calc(k);
	while(t.count()<R) {
		printf("%d",k);
		int kk=k;
		for(int i=1;i<n&&kk;i++)
			if(i%k!=0&&t[i]==0) {
				printf(" %d",i);
				t[i]=1;
				kk--;
			}
		while(kk)kk--,printf(" 1");
		cout<<endl;
		cin>>kk;
		for(int i=kk,j=1;j<=k;j++,i=i%n+1)
			t[i]=0;
	}
	cout<<0<<endl;
	return 0;
}