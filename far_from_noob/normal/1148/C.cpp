#include <iostream>
#include<bits/stdc++.h>
# define fo(i,n) for(int i=0;i < (n);i++)
#define ll long long
using namespace std;
 map<int ,int>index;
 vector<int>v[2005];
 int a[1000000];
 int count1=0;
 void swap1(int x,int  y){
int temp=a[y];
a[y]=a[x];
a[x]=temp;
index[a[x]]=x;
index[a[y]]=y;
count1++;
return;
}
//void maxheight(int hmax,vector<int>v[],)
void swap(int x,int  y){
int temp=a[y];
a[y]=a[x];
a[x]=temp;
index[a[x]]=x;
index[a[y]]=y;
cout<<x<<" "<<y<<endl;
return;
}
int main()
{
    int n;
    cin>>n;
    int b[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        index[a[i]]=i;
    }
    for(int i=0;i< n/2 -1;i++){
        if(index[n/2-i]!=n/2-i){
        if(abs(index[n/2-i]-n/2+i)>=n/2)swap1(index[n/2-i],n/2-i);
        else if(index[n/2-i]>n/2){
            swap1(1,index[n/2-i]);
            swap1(1,n);
            swap1(n/2-i,n);
        }
        else{
            swap1(n,index[n/2-i]);
            swap1(n/2-i,n);
        }}
        if(index[n/2+1+i]!=n/2+1+i){
        if(abs(index[n/2+1+i]-n/2-1-i)>=n/2)swap1(index[n/2+1+i],n/2+1+i);
        else if(index[n/2+1+i] > n/2){
            swap1(1,index[n/2+1+i]);
            swap1(1,n/2+1+i);
        }
        else {
            swap1(index[n/2+1+i],n);
            swap1(1,n);
            swap1(1,n/2+1+i);
        }}


    }
    if(a[1]==1);
    else swap1(1,n);
    cout<<count1<<endl;
    for(int i=1;i<=n;i++){
        //cin>>a[i];
        a[i]=b[i];
        index[a[i]]=i;
    }
    for(int i=0;i< n/2 -1;i++){
        if(index[n/2-i]!=n/2-i){
        if(abs(index[n/2-i]-n/2+i)>=n/2)swap(index[n/2-i],n/2-i);
        else if(index[n/2-i]>n/2){
            swap(1,index[n/2-i]);
            swap(1,n);
            swap(n/2-i,n);
        }
        else{
            swap(n,index[n/2-i]);
            swap(n/2-i,n);
        }}
        if(index[n/2+1+i]!=n/2+1+i){
        if(abs(index[n/2+1+i]-n/2-1-i)>=n/2)swap(index[n/2+1+i],n/2+1+i);
        else if(index[n/2+1+i] > n/2){
            swap(1,index[n/2+1+i]);
            swap(1,n/2+1+i);
        }
        else {
            swap(index[n/2+1+i],n);
            swap(1,n);
            swap(1,n/2+1+i);
        }}


    }
    if(a[1]==1);
    else swap(1,n);
    //for(int i=1;i<=n;i++)cout<<a[i]<<endl;





    return 0;
}