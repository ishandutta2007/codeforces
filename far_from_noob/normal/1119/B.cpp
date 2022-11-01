#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,h;
    cin >> n>>h;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i]=a[i];
    }
    int flag,height=h;
    for(int i=n;i>0;i--){
           // cout<<i<<endl;
        sort(b,b+i);
        flag=0;
        for(int j=i-1;j>=0;j=j-2){
            if(j==0 ){
                if(h>=b[j])
                break;
                else flag=1;
            }

            else if(b[j]<=h){
                h=h-b[j];
            }
            else {
                flag=1;
                break;
            }
        }
        h=height;
        for(int p=0;p<n;p++){
        b[p]=a[p];
        }
        if(flag==0){
            flag=i;
            break;
        }
        else flag=0;
    }
    cout << flag;



    return 0;
}