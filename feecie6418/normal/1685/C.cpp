#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,s[400005];
char a[400005];
void Solve(){
	cin>>n>>a+1;
	bool ok=1;
	for(int i=1;i<=2*n;i++){
		s[i]=s[i-1]+(a[i]=='('?1:-1);
		if(s[i]<0)ok=0;
	}
	if(ok){
		puts("0");
		return ;
	}
	int pl=0,mxl=0,mxlp=0;
	while(s[pl+1]>=0){
		pl++;
		if(s[pl]>mxl)mxl=s[pl],mxlp=pl;
	}
	int pr=2*n,mxr=0,mxrp=2*n;
	while(s[pr-1]>=0){
		pr--;
		if(s[pr]>mxr)mxr=s[pr],mxrp=pr;
	}
	bool ok1=1;
	for(int i=mxlp;i<=mxrp;i++){
		if(s[i]>mxl+mxr)ok1=0;
	}
	if(ok1){
		cout<<1<<'\n';
		cout<<mxlp+1<<' '<<mxrp<<'\n';
		return ;
	}
	int pos=max_element(s,s+2*n+1)-s;
	cout<<2<<'\n';
	cout<<1<<' '<<pos<<'\n';
	cout<<pos+1<<' '<<2*n<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve(); 
}