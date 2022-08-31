#include<iostream>
#include<algorithm>
using namespace std;
int n,d;
int main(){
	cin >> n >> d;
	char temp;
	int ans=0,cur=0;
	for(int i=1; i<=d ;i++){
		bool ok=true;
		for(int j=1; j<=n ;j++){
			cin >> temp;
			ok&=temp-48;
		}
		if(!ok){
			cur++;
			ans=max(ans,cur);
		}
		else{
			cur=0;
		}
	}
	cout << ans << endl;
}