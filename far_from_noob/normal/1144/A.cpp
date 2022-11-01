#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    // jo bhi ye code dekhe uski ma ki chut
    int n;
    cin >> n;
    string str[n];
    for(int i=0;i<n;i++){
        cin >> str[i];
        int p=0,a[100];
        p=str[i].length();
        for(int j=0;j<p;j++){
            a[j]=str[i][j]-'a'+1;
        }
        sort(a,a+p);
        int flag=1;
        for(int i=1;i<p;i++){
            if(a[i]-a[i-1] ==1){
                ;
            }
            else{
                flag=0;
                break;
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout << "No"<<endl;
        //cout << a[0]<<a[1]<<a[2]<<a[3];
        //cout << a[1];
    }
	return 0;
}