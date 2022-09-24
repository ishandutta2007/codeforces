#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,a[505][505];
int main(){
	cin>>n,memset(a,-1,sizeof(a));
	a[1][1]=a[n][n]=0;
	int p=1,q=1;
	while(n-p+n-q>=n){
		cout<<"? "<<p+1<<' '<<q<<' '<<n<<' '<<n<<endl;
		string ret;
		cin>>ret;
		if(ret=="YES")p++;
		else q++;
		a[p][q]=0;
	}
	p=n,q=n;
	while(p-1+q-1>=n){
		cout<<"? "<<1<<' '<<1<<' '<<p<<' '<<q-1<<endl;
		string ret;
		cin>>ret;
		if(ret=="YES")q--;
		else p--;
		a[p][q]=0;
	}
	cout<<"! ";
	p=1,q=1;
	while(p!=n||q!=n){
		if(a[p+1][q]==0)p++,cout<<"D";
		else q++,cout<<"R";
	}
	cout<<endl;
}