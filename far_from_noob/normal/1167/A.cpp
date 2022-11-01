#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        char a[n];
        int flag=-1;
        for(int i=0;i<n;i++){cin >>a[i];
        if(flag==-1 && a[i]-'0'==8)flag=i;

        }
        if(flag!=-1 && n-flag >=11)cout<<"YES"<<endl;
        else cout<< "NO"<<endl;

    }
    //cout << "Hello world!" << endl;
    return 0;
}