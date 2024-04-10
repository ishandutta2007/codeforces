#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >>n;
    long long a[n],b[n],a1[n];
    for(int i=0;i<n;i++){
        cin >>a[i]>>b[i];
        a1[i]=a[i];
    }
    /*map<int ,int>index;
    for(int i=0;i<n;i++)index[i]=a[i];*/
    sort(a,a+n);
    long long currentlast=0;
    for(int i=0;i<n;){
        int temp=1;
        for(int j=i+1;j<n;j++){
            if(a[j]== a[i])temp++;
            else break;
        }
        int index[temp],temp2=0;
        for(int j=0;j<n;j++){
            if(a1[j]==a[i]){
                index[temp2]=b[j];
                //cout<< b[j]<<endl;
                temp2++;
            }
        }
        sort(index,index+temp);
        if(index[0] >= currentlast) currentlast = index[temp-1];
        else currentlast =a[i];
        i=i+temp;
    }
    cout<< currentlast;
    return 0;
}