#include<bits/stdc++.h>
using namespace std;
int ans[3005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		memset(ans,0,sizeof(ans));
		ans[1]=ans[2]=1;
		for(int i=1,p=2,lst=3;lst<=2000;i++,p++){
			for(int j=lst;j<lst+y;j++)ans[j]=p;
			lst+=y;
		}
		cout<<ans[x]<<endl;
	}
}