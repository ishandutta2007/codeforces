#include <iostream>
using namespace std;
int n,m;
int arr[5005];
int main(){
	cin>>n>>m;
	
	for (int x=1;x<=n;x++) arr[x]=1000000+x*5005;
	
	int curr=0;
	
	for (int x=1;x<=n && curr<m;x++){
		if (curr+(x-1)/2<=m){
			arr[x]=x;
			curr+=(x-1)/2;
		}
		else{
			arr[x]=(x-1)+(x-(m-curr)*2);
			curr=m;
		}
	}
	
	if (curr!=m){
		cout<<-1;
		return 0;
	}
	for (int x=1;x<=n;x++) cout<<arr[x]<<" ";
}