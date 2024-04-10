#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,ans=0;
	scanf("%d",&a);
	while(a>0){
		ans+=a%8==1;
		a/=8;
	}
	return printf("%d",ans),0;
}