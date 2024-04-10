#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,temp2=0;
    cin >>n;
    char a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]=='+')temp2++;
        else temp2--;
    }
    int countmin=0,temp=0;
    for(int i=0;i<n;i++){
        if(a[i]=='+')temp++;
        else temp--;
        if(temp< countmin)countmin=temp;

    }
    cout<< temp2-countmin;

    //cout << "Hello world!" << endl;
    return 0;
}