#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define fo(i,n) for(int i=0;i<n;i++)
int min(int a,int b){
if(a>b)return b;
else return a;
}
int max(int a,int b){
if(a>b)return a;
else return b;
}
int swap(int a,int b){
int temp=a;
a=b;
b=temp;
}
int n,k,t,m,q;
int main() {
    cin>>n;
    int flag=0,start=0;
    map<int,int>position;
    int hand[n],pile[n];
    fo(i,n)cin>>hand[i];
    fo(i,n){cin>>pile[i];
    if(pile[i]>0)position[pile[i]]=i+1;
    }
    if(position[1]>0){
        for(int i=position[1];i<=n;i++){
            if(i-position[1]==pile[i-1]-1)start++;
            else {flag=1;break;}
        }
    }
    for(int i=start+1;i<=n;i++)if(position[i]>=i-start)flag=1;
    if(flag==1)start=0;
    int count=0;
    int temp=0;
    //cout<<start<<position[1];
    for(int i=start+1;i<=n;i++){
        if(position[i]<=temp){
            count++;
            temp++;
        }
        else {
            count+=position[i]-temp+1;
            temp+=position[i]-temp+1;

        }
    }
    cout<<count;
    return 0;
}