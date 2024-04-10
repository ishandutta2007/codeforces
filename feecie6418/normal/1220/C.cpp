#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int N=510000,inf=1e9,mod=998244353;
int n,has[150];
char a[1000005];
int main(){
	cin>>a+1,n=strlen(a+1);
	for(int i=1;i<=n;i++){
		bool ok=0;
		for(int j=0;j<a[i]-'a';j++)if(has[j])ok=1;
		has[a[i]-'a']=1;
		if(ok)cout<<"Ann\n";
		else cout<<"Mike\n";
	}
}