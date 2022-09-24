#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
typedef pair<int,int> pr;
typedef vector<int> ve;
int n,s[1005];
string f[1005],a;
int main(){
	cin>>a,f[0]=a[0];
	for(int i=1;i<a.length();i++){
		if(a[i]+f[i-1]<f[i-1]+a[i]){
			s[i]^=1,s[i-1]^=1,f[i]=a[i]+f[i-1];
		}
		else f[i]=f[i-1]+a[i];
	}
	for(int i=0;i<a.length();i++)cout<<s[i]<<' ';
}