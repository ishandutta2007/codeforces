#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
int main() {
    int n,k;
    cin >>n>>k;
    int a[k];
    for(int i=0;i<k;i++){
        cin >> a[i];
        //count[a[i]]++ ;
    }
    int indexmin[n+2],indexmax[n+2];
    for(int i=0;i<n+2;i++){
        indexmin[i]=-1;
        indexmax[i]=-1;
    }
    int temp[n+1];
    for(int i=0;i<n+1;i++)temp[i]=0;
    //cout<<temp[a[0]];
    for(int i=0;i<k;i++){
        if(temp[a[i]] ==0){indexmin[a[i]]=i;indexmax[a[i]]=i;temp[a[i]]++;}
        else indexmax[a[i]]=i;
    }
    int countans=3*n-2,count=0;
    //cout<<countans;
    //cout<<indexmin[1]<<indexmax[4];
    for(int i=1;i<n+1;i++){
        if(indexmin[i]!=-1){
            countans--;
            if(indexmin[i]<indexmax[i+1])count++;
            if(indexmin[i-1] != -1 && indexmax[i-1] > indexmin[i])count++;

        }
    }
    cout<< countans-count;


}