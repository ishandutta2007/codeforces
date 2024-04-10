#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	if(n>28)cout<<m;
	else cout<<m%(1<<n);
}