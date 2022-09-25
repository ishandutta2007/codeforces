#include<bits/stdc++.h>
using namespace std;
#define N 123
typedef long long ll;
int n,a[N],w[N];
int A,B;
pair<int,int> Ask(int x){
	cout<<"+ "<<x<<endl;
	int a,b;
	cin>>a>>b;
	int da=a-A,db=b-B;
	A=a,B=b;
	return make_pair(da,db);
}
int Get(int x){
	for(int i=1;;++i){
		if((i-1)*i/2==x)return i;
	}	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>A>>B;
	for(int i=n-1;i>=3;--i){
		w[i]=Ask(i).second;
	}
	int t1=Ask(1).second; // a[2](a[3]+1)
	int t2=Ask(2).second; // (a[1]+1)(a[3]+1)+(a[3]+1)(a[4]+1)
	auto [jb,t3]=Ask(1);  // (a[2]+1)(a[3]+1)
	a[3]=t3-t1-1;
	a[1]=Get(jb)-1;
	a[2]=t1/(a[3]+1);
	a[4]=(t2-(a[1]+1)*(a[3]+1))/(a[3]+1)-1;
	for(int i=3;i<=n-2;++i){
		a[i+2]=(w[i]-a[i-2]*a[i-1]-a[i-1]*(a[i+1]+1))/(a[i+1]+1)-1;	
	}
	++a[n];
	cout<<'!';
	for(int i=1;i<=n;++i){
		cout<<' '<<a[i];
	}
	cout<<endl;
	return 0;
}