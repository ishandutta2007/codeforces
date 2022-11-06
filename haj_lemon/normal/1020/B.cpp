#include<bits/stdc++.h>
using namespace std;
int n,p[100010],vi[10010],x;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>p[i];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) vi[j]=true;
		x=i;
		while (vi[x]){
			vi[x]=false;x=p[x];
		}
		cout<<x<<' ';
	}
	cout<<endl;
	return 0;
}