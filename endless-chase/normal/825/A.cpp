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
	int n,sum=0,flag=0;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
		sum++;
		flag=0;
	}
        if(s[i]=='0'&&flag==0) {
		cout<<sum;sum=0;flag=1;continue;
	}
        if(s[i]=='0'&&flag==1) cout<<"0";
    }
    cout<<sum<<endl;
	return 0;
}