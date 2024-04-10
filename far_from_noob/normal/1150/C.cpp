#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    int n;
    cin >>n;
    int temp;
    int count1=0 ,count2=0;
    for(int i=0;i<n;i++){
        cin >>temp;
        if(temp==1)count1++;
        else count2++;
    }   
    if(count1==0 )for(int i=0;i<n;i++)cout<<"2 ";
    if(count1>=1){
        if(count2==0)for(int i=0;i<count1;i++)cout<< "1 ";
        else{
            cout<< "2 1 ";
            for(int i=0;i<count2-1;i++)cout<< "2 ";
            for(int i=0;i<count1-1;i++)cout<< "1 ";
        }
    }
	return 0;
}