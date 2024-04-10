#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,x,y,z;
int main(){
	t=read();
	while(t--){
		x=read(),y=read(),z=read();
		if(x!=y&&y!=z&&z!=x){
			puts("NO");
			continue;
		}
		else if(x==y){
			if(z>x){
			puts("NO");
			continue;
			}
			else printf("YES\n%d %d %d\n",z,x,z);
		}
		else if(x==z){
			if(y>x){
			puts("NO");
			continue;
			}
			else printf("YES\n%d %d %d\n",x,y,y);
		}
		else if(y==z){
			if(x>z){
			puts("NO");
			continue;
			}
			else printf("YES\n%d %d %d\n",x,x,y);
		}
	}
}