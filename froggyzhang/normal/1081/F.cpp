#include<bits/stdc++.h>
using namespace std;
#define N 303
typedef long long ll;
int n,m,a[N];
inline int Ask(int l,int r){
	cout<<"? "<<l<<' '<<r<<endl;
	int x;
	cin>>x;
	return x;	
}
int Get(int l,int r){
	int tmp;
	do{Ask(l,r);tmp=Ask(l,r);}while(tmp==m);
	int jb=(r-l+1+tmp-(n-m))/2;
	do{Ask(l,r);tmp=Ask(l,r);}while(tmp!=m);
	return jb;	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(n==m*2-1||n==m*2+1){
		static int c[N];
		for(int i=1;i<n;++i){
			c[i]=Get(i,i+1);
		}
		a[1]=m;
		for(int i=2;i<n;i+=2)a[1]-=c[i];
		for(int i=2;i<=n;++i)a[i]=c[i-1]-a[i-1];
	}
	else{
		for(int i=1;i<=n;++i){
			a[i]=Get(i,i);	
		}	
	}
	cout<<"! ";
	for(int i=1;i<=n;++i){
		cout<<a[i];	
	}
	cout<<endl;
	return 0;
}