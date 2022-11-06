#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
bool ans=0;
int n,a[110];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=0;i<(1<<n);i++){
		int sum=0;
		for (int k=i,j=1;j<=n;j++){
			if (k%2==1)sum=sum+a[j];else sum=sum+360-a[j];
			k/=2;
		}
		if (sum%360==0) ans=1;
	}
	if (ans) puts("YES");else puts("NO");	
	return 0;
}