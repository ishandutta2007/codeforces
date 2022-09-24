#include<bits/stdc++.h>
using namespace std;
int n,K,ans[100005],a[100005],b[100005],P;
int f(int x){
	if(x>n)return x-n;
	if(x<1)return x+n;
	return x;
}
void Do(int p){
	for(int i=1;i<=n;i++){
		if(i!=p)b[f(i+1)]+=(a[i]+(a[i]&1))/2,b[f(i-1)]+=(a[i]-(a[i]&1))/2;else b[f(i+1)]+=a[i];
	}
	for(int i=1;i<=n;i++)a[i]=b[i],b[i]=0;
}
int main(){
	cin>>n>>K;
	if(n<=5){
		for(int i=1;i<=n;i++)cout<<"? "<<i<<endl,cin>>ans[i];
		for(int p=1;p<=n;p++){
			for(int i=1;i<=n;i++)a[i]=K;
			bool flag=1;
			for(int c=1;c<=n;c++){
				if(a[c]!=ans[c]){
					flag=0;
					break;
				}
				Do(p);
			}
			if(flag)return cout<<"! "<<p<<endl,0;
		}
	}
	int B=sqrt(n)+1;
	for(int i=1;i<=n;i++)a[i]=K;
	for(int i=1,x;i<=B;i++)cout<<"? "<<1<<endl,cin>>x;
	for(int i=n-(n-1)/B*B,x;i<=n;i+=max(1,min(B,n-i))){
		cout<<"? "<<i<<endl,cin>>x;
		if(x>K){
			while(1){
				cout<<"? "<<i<<endl,cin>>x;
				if(x==K)return cout<<"! "<<i<<endl,0;
				i=f(i-1);
			}
		}
	}
}