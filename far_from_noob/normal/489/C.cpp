#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main() {
    int n, s,s1;
    cin >>n>> s;
    s1=s;
    int max[n],min[n];
    if(n==1 && s==0)
    cout << "0 0";
    else if(s>9*n || s<1)
    cout<< "-1 -1";   
    else{
    for(int i=0;i<n;i++){
        if(s>9)
        max[i]=9;
        else max[i]=s;
        s=s-max[i];
    }
    if(s1<=9*(n-1)+1){
    min[0]=1;
    s=s1;
    s=s-1;
    for(int i=1;i<n;i++){
        if(s>9)
        min[n-i]=9;
        else min[n-i]=s;
        s=s-min[n-i];
    }
    }
    else{
    s=s1;
    for(int i=0;i<n;i++){
        if(s>9)
        min[n-1-i]=9;
        else min[n-1-i]=s;
        s=s-min[n-1-i];
    }
    }
    for(int i=0;i<n;i++){
        cout<< min[i];
    }    
    cout<< " ";
    for(int i=0;i<n;i++){
        cout<< max[i];
    }    
    }
	// your code goes here
	return 0;
}