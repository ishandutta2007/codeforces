#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    int n,flag=0,i;
    cin>>n;
    if(n<25)cout<<-1;
    else {
        for( i=5;i<n;i++){
            if(n%i==0){
                if(n/i>=5)flag=1;
                else flag=0;
                break;
            }
        }
        if(flag==0)cout<<-1;
        else {
                int l=n/i;
                for(int j=0;j<i;j++){
                    for(int k=0;k<l;k++){
                        if((k%5 + j%5)%5== 0)cout<<"a";
                        if((k%5 + j%5)%5== 1)cout<<"e";
                        if((k%5 + j%5)%5== 2)cout<<"i";
                        if((k%5 + j%5)%5== 3)cout<<"o";
                        if((k%5 + j%5)%5== 4)cout<<"u";
                    }
                    //cout<<endl;
                }
        }
    }


    return 0;
}