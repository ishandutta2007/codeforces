#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    int n,count=0,maxnum;
    cin >> n;
    int a[n];
    map<int ,int >xxx;
    for(int i=0;i<n;i++){
        cin >>a[i];
        xxx[a[i]]++;
        if(xxx[a[i]]>count){
            count=xxx[a[i]];
            maxnum=a[i];
        }
    }
    int index[count],p=0;
    for(int i=0;i<n;i++){
        if(a[i]==maxnum){
            index[p]=i;
            p++;
        }
    }
    cout << n-count<<endl;
    p=0;
    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]==maxnum){
            for(int j=index[p]-1;j>=index[p]-c;j--){
                if(a[j]<maxnum)cout << 1;
                else cout << 2;
                
                cout << " "<< j+1<<" "<<j+2<<endl;
            }
            c=0;
            
        }
        else if(i<index[p]){
            c++;
        }
        else {
            //cout <<"fuck"<<endl;
            p++;
            if(p>=count){
                p--;
                for(int j=index[p]+1;j<n;j++){
                    if(a[j]>maxnum)cout << 2;
                    else cout << 1;
                    cout<< " "<<j+1<<" "<<j<<endl;
                }
                break;
            }
            i--;
            
        }
    }
    //cout << index[0];
    //cout<< maxnum<<count;
	return 0;
}