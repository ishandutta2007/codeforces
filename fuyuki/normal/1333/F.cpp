#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=5e5+1;
int n,a[N],c[N];
int main(){
	cin>>n;
	FOR(i,1,n)FOR(j,2,n/i)a[i*j]=i;
	FOR(i,1,n)c[a[i]]++;
	FOR(i,1,n)while(c[i]--)cout<<i<<' ';
	return 0;
}