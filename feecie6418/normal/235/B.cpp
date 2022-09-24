#include<iomanip>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n;
double ans[100005],f[100005],a[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=(f[i-1]+1)*a[i];
		ans[i]=ans[i-1]+(2*f[i-1]+1)*a[i];
	}
	printf("%.10lf\n",ans[n]);
    return 0;
}