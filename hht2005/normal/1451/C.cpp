#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
char a[maxn],b[maxn];
int A[28],B[28];
int main() {
	int T,n,k;
	scanf("%d",&T);
	while(T--) {
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		scanf("%d%d",&n,&k);
		scanf("%s%s",a+1,b+1);
		for(int i=1;i<=n;i++)A[a[i]-'a']++;
		for(int i=1;i<=n;i++)B[b[i]-'a']++;
		int FL=1;
		for(int i=0;i<26;i++) {
			if(A[i]<B[i]||(A[i]-B[i])%k) {
				FL=0;
				break;
			}
			A[i+1]+=A[i]-B[i];
		}
		puts(FL?"Yes":"No");
	}
	return 0;
}