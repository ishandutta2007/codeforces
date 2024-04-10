#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n>>m;
    int a[n][m],b[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >>b[i][j];
        }
    }
    int flag=0;
    int count1a=0,count1b=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1)count1a++;
            if(b[i][j]==1)count1b++;
        }
        if((count1a+count1b)%2 ==0 ){
            count1a=0;count1b=0;
        }
        else {
            flag=1;
            break;
        }
    }
    if (flag==1)cout<< "No";
    count1a=0;count1b=0;
    if(flag==0){
           // cout<<"ab kya";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[j][i]==1)count1a++;
                if(b[j][i]==1)count1b++;

            }
            if((count1a+count1b)%2 ==0 ){
            count1a=0;count1b=0;
        }
        else {
            flag=1;
            break;
        }

        }

        if(flag==0)cout<<"Yes";
        else cout<<"No";
    }
    return 0;
}