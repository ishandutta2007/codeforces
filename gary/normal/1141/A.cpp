#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	if(m%n!=0) {
		printf("-1\n");
		return 0;
	}
	int h=m/n,ans=0;
//	cout<<h<<endl;
	while(h%3==0){
		h/=3;
		ans++;
	}
	while(h%2==0){
		h/=2;
		ans++;
	}
	if(h==1){
		printf("%d\n",ans);
		
	}
	else{
		printf("-1\n");
	}
	return 0;
}