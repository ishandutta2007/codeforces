#include <iostream>
#include<bits/stdc++.h>
#define fo(i,n) for(int i=0;i<n;i++)
#define ll long long
using namespace std;
map<int,int>nupur;

int main()
{
    ll n;
    cin>>n;
    int temp =1;
    for(int i=2;i<=n;i++){
        if(nupur[i]!=0)cout<<nupur[i]<<" ";
        else {
            cout<<temp<<" ";
            for(int j=i;j<=n;j+=i){
                nupur[j]=temp;
            }
            temp++;
        }
    }

    //cout << "Hello world!" << endl;
    return 0;
}