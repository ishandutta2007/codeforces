#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
} 
int n,m,t;
int main(){
	t=read();
	while(t--){
		n=read();
		printf("%d\n",n);
	}
}