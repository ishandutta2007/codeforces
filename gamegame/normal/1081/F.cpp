#include<iostream>
using namespace std;
int n,t,ot;
bool inv[301];
int sum[301];
int o[301];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> t;
	ot=t;
	if(n%2==0){
		for(int i=1; i<=n ;i++){
			int nt;
			while(true){
				cout << "? " << i << ' ' << i << endl;
				cin >> nt;
				if((nt%2!=t%2)^(i%2==0)){
					for(int j=1; j<=i ;j++) inv[j]^=1;
					o[i]=nt-t;
					for(int j=1; j<i ;j++){
						if(inv[j]) o[i]+=o[j];
						else o[i]-=o[j];
					}
					if(inv[i]) o[i]=-o[i];
					t=nt;
					break;
				}
				else{
					for(int j=i; j<=n ;j++) inv[j]^=1;
					t=nt;
				}
			}
		}
		cout << "! ";
		for(int i=1; i<=n ;i++){
			cout << (o[i]==1);
		}
		cout << endl;
	}
	else{
		for(int i=2; i<=n ;i+=2){
			int nt;
			while(true){
				cout << "? " << i-1 << ' ' << i << endl;
				cin >> nt;
				if(nt%2==t%2){
					for(int j=1; j<=i ;j++) inv[j]^=1;
					sum[i]=nt-t;
					for(int j=2; j<=i-2 ;j+=2){
						if(inv[j]) sum[i]+=sum[j];
						else sum[i]-=sum[j];
					}
					if(inv[i]) sum[i]=-sum[i];
					t=nt;
					break;
				}
				else{
					for(int j=i-1; j<=n ;j++) inv[j]^=1;
					t=nt;
				}
				
			}
		}
		//compute o[n]
		o[n]=ot-(n-ot);
		for(int i=2; i<=n ;i+=2){
			o[n]-=sum[i];
		}
		for(int i=n; i>=3 ;i-=2){
			//compute o[i-1] and o[i-2]
			int nt;
			while(true){
				cout << "? " << i-1 << ' ' << i << endl;
				cin >> nt;
				if(nt%2==t%2){
					for(int j=i-1; j<=n ;j++) inv[j]^=1;
					o[i-1]=nt-t;
					for(int j=n; j>=i ;j--){
						if(inv[j]) o[i-1]+=o[j];
						else o[i-1]-=o[j];
					}
					if(inv[i-1]) o[i-1]=-o[i-1];
					o[i-2]=sum[i-1]-o[i-1];
					t=nt;
					break;
				}
				else{
					for(int j=1; j<=i ;j++) inv[j]^=1;
					t=nt;
				}
			}
		}
		cout << "! ";
		for(int i=1; i<=n ;i++){
			cout << (o[i]==1);
		}
		cout << endl;
	}
}