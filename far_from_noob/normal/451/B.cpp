#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    int n,count=0,temp=0;
    cin >> n;
    int a[n],b[n],galat[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    for(int i=0;i<n;i++){
        if(a[i]!=b[i])
        {
            galat[count]=i;
            count++;
        }
    }
    //cout<< galat[0];
    if(count==0)cout << "yes"<<endl<<1<< " "<<  1;
    else if(count%2==0 && ((count-1==galat[count-1]-galat[0]) ||(count==galat[count-1]-galat[0]))){
        int flag=0;
        for(int i=0;i<count;i++){
            if(a[galat[i]]==b[galat[count-1-i]])
            flag=1;
            else {
                 flag=0;
                 break;
            }
        }
        if(flag)
        cout<< "yes"<<endl<< galat[0]+1<<" "<<galat[count-1]+1;
        else cout <<"no";
    }
    else cout<< "no";
	return 0;
}