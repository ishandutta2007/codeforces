#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    int n;
    cin >> n;
    int a[n],extra[n],normal[n],p=0,q=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i]>a[i-1]  || i==0){
            normal[p]=a[i];
            p++;
        }
        else if(a[i+1]==a[i]){
            q=-1;
            break;
        }
        else {
            extra[q]=a[i];
            q++;
        }
    }
    if(q==-1)cout<<"NO";
    else {
        cout<< "YES"<<endl;
        cout << q<<endl;
        for(int i=0;i<q;i++) cout <<extra[i]<<" ";
        cout<<endl<<p<<endl;
        for(int i=p;i>0;i--)cout<< normal[i-1]<<" ";
    }
	return 0;
}