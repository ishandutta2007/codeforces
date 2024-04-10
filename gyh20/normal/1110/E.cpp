#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int A[100002],B[100002],n;
int main(){
	n=read();
	for(re int i=1;i<=n;++i)A[i]=read();
	for(re int i=1;i<=n;++i)B[i]=read();
	if((A[1]^B[1])||(A[n]^B[n]))return puts("No"),0;
	for(re int i=1;i<n;++i)A[i]=A[i+1]-A[i],B[i]=B[i+1]-B[i];
	sort(A+1,A+n),sort(B+1,B+n);
	for(re int i=1;i<n;++i)if(A[i]^B[i])return puts("No"),0;
	puts("Yes");
}