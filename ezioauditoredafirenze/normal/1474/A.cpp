#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long n,i;
	string str;
	cin>>n>>str;
	long long b[n],cur=1+str[0]-'0';
	b[0]=1;
	for(i=1;i<n;i++){
		if(cur==0){
			b[i]=1;
		}
		else if(cur==1){
			if(str[i]=='1'){
				b[i]=1;
			}
			else{
				b[i]=0;
			}
		}
		else{
			if(str[i]=='0'){
				b[i]=1;
			}
			else{
				b[i]=0;
			}
		}
		cur=(str[i]-'0')+b[i];
	}
	for(i=0;i<n;i++)
		cout<<b[i];
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}