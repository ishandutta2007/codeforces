#include<bits/stdc++.h>
using namespace std;
#define re register
inline long long read(){
	re long long  t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
} 
int main(){
    re long long r=read(),g=read(),b=read();
    printf("%lld\n",min(min(min((r+g+b)/3,r+g),r+b),b+g));
}