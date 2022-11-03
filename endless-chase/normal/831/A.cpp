#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<sstream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[110];
	for(int i=1;i<=n;i++)
            cin>>a[i];
        a[n+1]=100000000000;
        int p=2;
        while(a[p]>a[p-1]) p++;
        while(a[p]==a[p-1]) p++;
        while(a[p]<a[p-1]) p++;
        if(p<=n) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
	return 0;
}