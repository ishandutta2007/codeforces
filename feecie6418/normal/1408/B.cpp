#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005],t[105];
int main(){
	int y;
	cin>>y;
	while(y--){
		int cnt=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(!t[a[i]])cnt++;
			t[a[i]]++;
		}
		if(k==1&&t[a[1]]==n)puts("1");
		else if(k==1)puts("-1");
		else if(cnt<=k)puts("1");
		else cout<<(cnt-2)/(k-1)+1<<endl;
		for(int i=1;i<=n;i++)t[a[i]]=0;
	}
	return 0;
}