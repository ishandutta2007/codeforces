#include<bits/stdc++.h>
using namespace std;
int a[105],c[55];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
			if(!c[a[i]])c[a[i]]=1,cout<<a[i]<<' ';
		}
		puts(""),memset(c,0,sizeof(c));
	}
	return 0;
}