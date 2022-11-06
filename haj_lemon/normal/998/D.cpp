#include<bits/stdc++.h>
using namespace std;
int main(){
	int f[100010]={0},ansn,n,g[1010];
	cin>>n;
	if (n<=20){
		memset(f,0,sizeof(f));ansn=0;
		for (int i=0;i<=n;i++){
			for (int j=0;j<=n-i;j++){
				for (int k=0;k<=n-i-j;k++){
					f[i+j*5+k*10+(n-i-j-k)*50]++;
				}
			}
		}
		for (int i=n;i<=n*50;i++) if (f[i]!=0) ansn++;
		cout<<ansn<<endl;
	}else{
		cout<<733+((long long)n-20)*(49)<<endl;
	}
	return 0;
}