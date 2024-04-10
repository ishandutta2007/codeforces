#include <bits/stdc++.h>
using namespace std;
int prime(int a){
    int i;
    int count=0;
    for(i=2;i<=min(((int)sqrt(a))+4,a-1);i++){
        if(a%i==0){
            count++;
            break;
        }}
    return count;}    
        
int power(int a){
    if(ceil(log2(a))==floor(log2(a))){
        return 1;
    }
    else{
        return 0;
    }
}    
int main(){
    int t,i;
    cin>>t;
    int a[t];
    for(i=0;i<t;i++){
        cin>>a[i];
    }
        
    for(i=0;i<t;i++){
        if(a[i]%2==0 && a[i]!=2){
            if( power(a[i])==1 || prime(a[i]/2)==0){
                cout<<"FastestFinger"<<endl;
            }
            else{
                cout<<"Ashishgup"<<endl;
            }
            }
        else if(a[i]%2!=0 && a[i]>1){
            cout<<"Ashishgup"<<endl;
        }   
        else if(a[i]==1){
            cout<<"FastestFinger"<<endl;
        }
        else if(a[i]==2){
            cout<<"Ashishgup"<<endl;
        }
            
        }}