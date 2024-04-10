#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    int n;
    cin >>n ;
    int boys[n];
    for (int i=0;i<n;i++){
        cin>> boys[i];
    }
    int m;
    cin >>m ;
    int girls[m];
    for (int i=0;i<m;i++){
        cin>> girls[i];
    }
    sort(boys,boys+n);
    sort (girls,girls+m);
    int count=0,lastelement=-1;
    for(int i=0;i<n;i++)
    {
        int temp=0;
        for(int j=lastelement+1;j<m;j++){
            if(boys[i]-1==girls[j])
             {
                temp=1;
                count++;
                lastelement=j;
                break;
            }
            if(boys[i]==girls[j])
            {
                temp=1;
                count++;
                lastelement=j;
                break;
            }
            if(boys[i]+1==girls[j])
            {
                temp=1;
                count++;
                lastelement=j;
                break;
           }    
        }
        
    }
    cout << count;
	return 0;
}