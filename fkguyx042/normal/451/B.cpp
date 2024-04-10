#include<iostream>
#include<stdio.h>
using namespace std;
int a[100005];
int main(){
    int n;
    while(~scanf("%d",&n)){
        a[0]=-1;
        a[n+1]=1000000009;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int start=-1,end=-1,flag=0;
        for(int i=2;i<=n+1;i++){
            if(a[i-1]>a[i] && start==-1){
                start=i-1;
            }
            else if(start!=-1 && end==-1 && a[i-1]<a[i]){
                end=i-1;
                flag=1;
            }
            else if(a[i-1]>a[i] && start!=-1 && end!=-1){
                flag=2;
                break;
            }
        }
        if(n==1 || start==end){
            cout<<"yes"<<endl;
            cout<<"1 1"<<endl;
        }
        else if(flag==2){
            cout<<"no"<<endl;
        }
        else if(a[start]<a[end+1] && a[end]>a[start-1]){
            cout<<"yes"<<endl;
            cout<<start<<" "<<end<<endl;
        }
        else
            cout<<"no"<<endl;
    }
}