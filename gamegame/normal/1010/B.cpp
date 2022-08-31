#include<iostream>
using namespace std;
int m,n;
int p[30];
int main(){
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for(int i=0; i<n ;i++){
		cout << 1 << endl;
		cin >> p[i];
		if(p[i]==0) return 0;
	}
	int l=1,r=m,mid;
	int cnt=0;
	while(l!=r){
		mid=(l+r)/2;
		cout << mid << endl;
		int ret;
		cin >> ret;
		ret*=p[cnt];
		cnt=(cnt+1)%n;
		if(ret==0) return 0;
		if(ret==-1) r=mid-1;
		else l=mid+1;
	}
	cout << l << endl;
}