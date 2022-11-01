#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,temp=0;
    cin >> n;
    int a[n],sum[n];
    for(int i=0;i<n;i++)
    {

        cin >> a[i];
        sum[i]=a[i]+temp;
        temp=sum[i];
    }
    map<int,int>pileno;
    int currentpile=0;
    for(int i=0;i<sum[n-1];i++){
        if(sum[currentpile]>=i+1)pileno[i+1]=currentpile+1;
        else {currentpile++; i--;}
        //cout<< i<<endl;
    }
    int m;
    cin >>m;
    int b[m];
    for(int i=0;i<m;i++){
        cin >>b[i];
        cout<< pileno[b[i]]<<"\n";
    }
    //cout << "Hello world!" << endl;
    return 0;
}