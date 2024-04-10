#include<bits/stdc++.h>
using namespace std;
int n,l;
double a[100005];
int main(){
	int y;
	cin>>y;
	while(y--){
		cin>>n>>l;
		for(int i=1;i<=n;i++)cin>>a[i];
		a[n+1]=l;
		int i=0,j=n+1;
		double ans=0,s1=1,s2=1;
		while(i<j-1){
			if((a[i+1]-a[i])/s1<=(a[j]-a[j-1])/s2){
				double o=(a[i+1]-a[i])/s1;
				a[j]-=o*s2;
				ans+=o;
				s1++;
				i++;
			}
			else {
				double o=(a[j]-a[j-1])/s2;
				a[i]+=o*s1;
				ans+=o;
				s2++;
				j--;
			}
		}
		ans+=(a[j]-a[i])/(s1+s2);
		printf("%.10lf\n",ans);
		for(int i=0;i<=n+1;i++)a[i]=0;
	}
	return 0;
}