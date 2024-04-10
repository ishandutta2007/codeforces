#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{   int n;
    cin >>n;
    int a[n],b[n+1][11];
    for(int i=0;i<n+1;i++){
        for(int j=1;j<=10;j++)b[i][j]=0;
    }
    map<int ,int>count;
    for(int i=0;i<n;i++){
        cin >> a[i];
        for(int j=1;j<=10;j++){
            if(j==a[i])b[i+1][j]=b[i][j]+1;
            else b[i+1][j]=b[i][j];
        }

    }
    for(int i=n-1;i>=0;i--){
        //cout<<"fuck";
        int flag=0;
        int c[10];
        for(int j=1;j<=10;j++){
            c[j-1]=b[i+1][j];
            //if(i==5)cout<< c[j-1]<<" ";
        }
        sort(c,c+10);
        for(int j=9;j>0;j--){
            if(c[8]==0 ){flag=2; break;}
            if(c[j]==1){flag=2; break;}
            if(c[j]==c[j-1])continue;
            if(c[j]>c[j-1]){
                //if(i==4)cout<<j;
                if(c[j-1]==0 && flag==1) {flag=2;break;}
                if(flag==1){flag=-1; break;}
                if(j>=2){if(c[j-1]==1 && c[j-2]==0 ){flag=2; break;}}
                else {if(c[j-1]==1 && j==1 ){flag=2; break;}}

                if(c[j]-c[j-1] ==1 && j==9) { flag=1; ;continue;}
                else {flag = -1; break;}



        }
        }
        if(flag==2 || flag==1){cout << i+1; break;}
        else {flag=0;}

    }
    return 0;
}