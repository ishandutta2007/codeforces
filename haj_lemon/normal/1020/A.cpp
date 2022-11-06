#include<bits/stdc++.h>
using namespace std;
long long n,h,a,b,k,t1,t2,f1,f2;
int main(){
	cin>>n>>h>>a>>b>>k;
	while (k--){
		cin>>t1>>f1>>t2>>f2;
		if (t1==t2){
					cout<<abs(t1-t2)+abs(f1-f2)<<endl;
			
		}else{
			if (f1<a&&f2<a){
				cout<<abs(t1-t2)+abs(a-f1)+abs(a-f2)<<endl;
			}else{
				if (f1>b&&f2>b){
					cout<<abs(t1-t2)+abs(b-f1)+abs(b-f2)<<endl;
				}else{
					cout<<abs(t1-t2)+abs(f1-f2)<<endl;
				}
			}
		}
	}
	return 0;
}