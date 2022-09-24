#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[505],b[505][505];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int px=i,py=i;
		for(int j=1;j<=a[i];j++){
			b[px][py]=a[i];
			if(py==1||b[px][py-1])px++;
			else py--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)printf("%d ",b[i][j]);
		puts("");
	}
}