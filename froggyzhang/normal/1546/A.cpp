#include <iostream>
using namespace std;
int main(){
     int T;
     cin>>T;
     while(T--){
        int n,a[101],b[101];
		cin>>n;
		for(int i=1;i<=n;++i)
		cin>>a[i];
		for(int i=1;i<=n;++i)
		cin>>b[i];
		int x[100],y[100];
		int xc=0,yc=0;
		for(int i=1;i<=n;++i){
			while(a[i]>b[i])a[i]--,x[xc++]=i;
			while(a[i]<b[i])a[i]++,y[yc++]=i;
		}
		if(xc==yc){
			cout<<xc<<endl;
			for(int i=0;i<xc;++i){
				cout<<x[i]<<" "<<y[i]<<endl;
			}
		}
		else{
			cout<<-1<<endl;
		}
     }
}