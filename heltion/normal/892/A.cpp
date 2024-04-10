#include<iostream>
#include<algorithm>
using namespace std;
const int N=100000;
int a[N],b[N];
int main(){
	int n;
	long long s=0;
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)cin>>b[i];
	int mm=max(b[0],b[1]),m=min(b[0],b[1]);
	for(int i=2;i<n;++i)if(b[i]>=mm)m=mm,mm=b[i];else if(b[i]>=m)m=b[i];
	for(int i=0;i<n;++i)s+=a[i],n=s<=m+mm?n:0;
	cout<<(n?"YES":"NO");
}