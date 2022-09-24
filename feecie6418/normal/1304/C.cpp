#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,nowt,t[105],l[105],r[105];
int fs[105];//1 2
int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>n>>nowt;
		for(int i=1; i<=n; i++)cin>>t[i]>>l[i]>>r[i];
		bool flag=0;
		for(int i=1; i<=n; i++) {
			for(int j=i+1;j<=n;j++){
				if((l[j]-r[i]>t[j]-t[i])||(l[i]-r[j]>t[j]-t[i])){
					flag=1;
					break;
				}
			} 
			if(flag||l[i]>nowt+t[i]||r[i]<nowt-t[i]){
				flag=1;
				break;
			}
		}
		if(flag)puts("No");
		else puts("Yes");
	}
	return 0;
}