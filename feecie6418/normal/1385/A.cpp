#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int x,y,z;
		cin>>x>>y>>z;
		if(x!=y&&x!=z&&y!=z)puts("NO");
		else if(x==y&&x==z)printf("YES\n%d %d %d\n",x,y,z);
		else if(x==y){
			if(x<z)puts("NO");
			else printf("YES\n%d %d %d\n",x,z,z);
		}
		else if(y==z){
			if(y<x)puts("NO");
			else printf("YES\n%d %d %d\n",x,x,z);
		}
		else {
			if(z<y)puts("NO");
			else printf("YES\n%d %d %d\n",y,z,y);
		}
	}
	return 0;
}