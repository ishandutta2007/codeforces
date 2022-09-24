#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int p[25]={0,2,3,5,7,11,13,17,19,23,29,31},a[1005],col[1005],n;
int main(){
	int T;
	cin>>T;
	while(T--){
		int c[1005]={0};
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=11;j++){
				if(a[i]%p[j]==0){
					col[i]=j;
					c[++c[0]]=j;
					break;
				}
			}
		}
		sort(c+1,c+c[0]+1);
		c[0]=unique(c+1,c+c[0]+1)-c-1;
		cout<<c[0]<<endl;
		for(int i=1;i<=n;i++)cout<<lower_bound(c+1,c+c[0]+1,col[i])-c<<' ';
		cout<<endl;
	}
	
}