#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans,A,B,num0;
char s[1000002];
int main(){
	t=read();
	while(t--){
		n=read(),ans=0;
		vector<int>A;
		for(re int i=1;i<=n;++i)A.push_back(read());
		sort(A.begin(),A.end());
		num0=0;
		while(A.size()+num0>1&&A.size()){
			vector<int>B;
			if(num0){
				--num0;
				B.push_back(A[0]);
			}
			for(re int j=0;j+1<A.size();++j)B.push_back(A[j+1]-A[j]);
			sort(B.begin(),B.end());
			vector<int>C;
			for(re int i=0;i<B.size();++i)if(B[i])C.push_back(B[i]);else ++num0;
			A=C;
		}
		if(num0)puts("0");
		else printf("%d\n",A[0]);
	}
}