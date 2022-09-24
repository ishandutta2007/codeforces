#include<iostream>
#include<cstdio>
using namespace std;
double ans;
int n;
int main()
{
    cin>>ans>>n;
    double ret=1,k=1.000000011l;
    while(n){
    	if(n&1)ret*=k;
    	k*=k;
    	n>>=1;
	}
	printf("%.12lf\n",ans*ret);
    return 0;
}