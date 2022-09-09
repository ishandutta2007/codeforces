#include<iostream>
using namespace std;
int a[100010];
int s[100010]={};
int m[100010]={};
int main(){
	int n,d,ss=0,k=0;
	cin>>n>>d;
	for(int i=1;i<=n;++i)cin>>a[i],s[i]=s[i-1]+a[i];
	m[n]=s[n];
	for(int i=n-1;i>=1;--i){
		if(s[i]>m[i+1])m[i]=s[i];
		else m[i]=m[i+1];
	}
	for(int i=1;i<=n;++i)if(s[i]+ss>d){
		cout<<-1;
		return 0;
	}
	else if(a[i]==0&&s[i]+ss<0){
			if(m[i]-s[i]>d){
				cout<<-1;
				return 0;
			}
			else ss+=d-(m[i]-s[i])-(ss+s[i]),k++;
	}
	cout<<k;
	return 0;
}