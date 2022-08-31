#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int,int>m;
int main(){
	int n;
	cin >> n;
	int a;
	long long ans=0;
	for(int i=1; i<=n ;i++){
		cin >> a;
		for(long long int j=1; j<=2e9 ;j*=2){
			ans+=m[j-a];
			if(m[j-a]==0) m.erase(j-a);
		}
		m[a]++;
	}
	cout << ans << endl;
}